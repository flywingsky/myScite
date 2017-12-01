--go@ dofile $(FilePath)
--~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-- AutoComplete by Lexikos. Updates 2017 by Marcedo
-- Version: 0.9
-- 12.07.17 - Sanity checks for SciTE.
-- 29.11.17 - Documentation, Performance Tweaks and appendCTags 

--[[
Tested on SciTE4AutoHotkey 3.0.06.01; may also work on SciTE 3.1.0 or later.
To use this script with SciTE4AutoHotkey:
  - Place this file in your SciTE user settings folder.
  - Add the following to UserLuaScript.lua:
        dofile(props['SciteUserHome'].."/AutoComplete.lua")
  - Restart SciTE.
 @info 29.11.2017 Marcedo@habMalNeFrage.de
 - Adapted for mySciTE 3.7.5
 - Performance: exclude NULL Lexer; 
    Use a FileSize maximum; 
    Only regenerate Data on changed File
    renew Keyword List OnDwell
- appendCTags() function (Autocomplete Project)    
]]
-- Maximal filesize that this script should handle
local AC_MAX_SIZE =262144 --260k

-- Default colour for cTag generated ProjectAPI
if props["colour.projectapi"]=="" then
 props["colour.projectapi"]="fore:#608096"
end 
 
-- List of styles per lexer that autocomplete should not occur within.
local SCLEX_AHK1 = 200
local SCLEX_AHK2 = 201 --?
local SCLEX_GENERIC = 1024

local IGNORE_STYLES = { -- Should include comments, strings and errors.
    [SCLEX_AHK1] = {1,2,6,20},
    [SCLEX_AHK2] = {1,2,3,5,15},
    [SCLEX_BATCH] = {1,3},
    [SCLEX_BASH] = {1,2,5,6,12,13},
    [SCLEX_CMAKE] = {1,2,3,4,7},
    [SCLEX_CSS] = {4,9,13,14},
    [SCLEX_COFFEESCRIPT] = {1,2,3,6,7,12,15,18,22,24},
    [SCLEX_CPP]  = {1,2,3,6,7,8,12},
    [SCLEX_FREEBASIC]  = {1,4,9},
    [SCLEX_HASKELL]  = {4,5,9,13,14,15,16,19},
    [SCLEX_HTML]  = {1,2,3,6,7,8,12},
    [SCLEX_LUA]  = {1,2,3,6,7,8,12},
    [SCLEX_MAKEFILE]  = {1,12},
    [SCLEX_MARKDOWN]  = {},
    [SCLEX_PERL]  = {1,2,6,7,22,23,24,25,26,27,44},
    [SCLEX_PYTHON]  = {1,3,4, 12, 13},
    [SCLEX_RUBY]  = {1,2,6,7},
    [SCLEX_RUST]  = {1,2,3,4},
    [SCLEX_SPICE]  = {8},
    [SCLEX_PROPERTIES]  = {1},
    [SCLEX_POWERSHELL]  = {1,2,3,13,16},
    [SCLEX_VHDL]  = {1,2,4,7,14,15},
    [SCLEX_GENERIC]  = {1,2,3,6,7,8}
}
 
local INCREMENTAL = true
local IGNORE_CASE = false
local CASE_CORRECT = true
local CASE_CORRECT_INSTANT = false
local WRAP_ARROW_KEYS = false
local CHOOSE_SINGLE = props["autocomplete.choose.single"]

-- Names from api files, stored by lexer name.
local apiCache = {} 
-- Number of chars to type before the autocomplete list appears:
local MIN_PREFIX_LEN = 2
-- Length of shortest word to add to the autocomplete list:
local MIN_IDENTIFIER_LEN = 3
-- List of regex patterns for finding suggestions for the autocomplete menu:
local IDENTIFIER_PATTERNS = {"[a-z_][a-z_0-9]+"}
-- Override settings that interfere with this script:
props["autocomplete.start.characters"] = ""
props["autocomplete.start.characters"] = ""

-- This feature is very awkward when combined with automatic popups:
props["autocomplete.choose.single"] = "0"

--~~~~~~~~~~~~~~~~~~~~~~~

local names = {}

local notempty = next
local shouldIgnorePos= function(self) end -- init'd by buildNames().
local normalize

if IGNORE_CASE then
    normalize = string.upper
else
    normalize = function(word) return word end
end
		
--
-- Deal with different Path Separators o linux/win
--
local function dirSep()
if props["PLAT_WIN"] then
    return("\\")
else
    return("/")
end
end

--
-- returns if a given fileNamePath exists
--
local function file_exists(name)
   local f=io.open(name,"r")
   if f~=nil then io.close(f) return true else return false end
end

--
-- returns the size of a given fileNamePath.
--
function file_size (filePath)
    if  filePath ~=""  and filePath ~= nil then 
        local myFile,err=io.open(filePath,"r")
        if err then return 0 end -- todo handle filePath containing Unicode chars 
        local size = myFile:seek("end")    -- get file size
        myFile:close()
        return size
    else
        return 0
    end
end

--
-- checks for a Value in a Table
--
local function isInTable(table, elem)
	if table == null then return false end
	for k,i in ipairs(table) do
		if i == elem then
			return true
		end
	end
	return false
end

--
--   Appends uniqued tagNames to given table
--   Append tagNames to currentLexers substyle 11.20
--
local cTagNames="" -- globally cached function names
cTagAPI={} -- globally cached projectAPI functions(param)
local updateCTags=1

local function appendCTags(apiNames)    
    local sysTmp=os.getenv("tmp")
    local cTagsFilePath=props["project.path"]..dirSep()..props["project.ctags.filename"]
    local cTagsAPIPath=sysTmp..dirSep()..props["project.name"].."_cTags.api" -- performance:  should we reuse an existing File ?
    props["project.ctags.apipath"]=cTagsAPIPath
  
    if file_exists(cTagsFilePath) and updateCTags==1 then 
        local lastEntry=""
        cTagNames=""
        cTagsFile= io.open(cTagsAPIPath,"w")
        io.output(cTagsFile)   -- projects cTags APICalltips file
        
        for entry in io.lines(cTagsFilePath) do
            -- parameters for Calltips
            local params = entry:match("(%(.*%))") or "" -- functions
            local name = entry:match("([%w_.:]+)") -- Only the Names for List Entries
            if entry:match("d$")=="d" then name= entry:match("([%w_.:]+)") or "" end -- Constants 
            if name..params~=lastEntry then --Dupe Check
                if name~=lastname then 
                    -- Variables
                    cTagAPI[name]=true 
                    -- Highlitening
                    if string.len(params) > 0 then cTagNames=cTagNames.." "..name end
                    lastname=name
                end
                -- Functions
                lastEntry=name..params -- todo: write a helper to cope with ctags writing dupes from different files
                io.write(lastEntry.."\n") 
            end
        end
        io.close(cTagsFile)
        buffer.projectName= props["project.name"]
        updateCTags=0

        -- Append Once to filetypes api path
        projectEXT=props["file.patterns.project"]
        if origApiPath==nil then origApiPath=props["APIPath"] end
        props["api."..projectEXT] =origApiPath..";"..props["project.ctags.apipath"]
        
        -- test: Expose the functions collected by cTags for syntax highlitening a Projects API      
        local currentLexer=props["Language"]
        props["substyles."..currentLexer..".11"]=20
        props["substylewords.11.20."..projectEXT] = cTagNames
        props["style."..currentLexer..".11.20"]=props["colour.projectapi"]
    end
    
    --already done, so use the cached Version
    return cTagAPI  
end

--
-- Disable collection of words in comments, strings, etc.
-- Also disables autocomplete popups while typing there.
--
local function setLexerSpecificStuff()
    local iLexer=editor.Lexer
    --print (editor.Lexer)
    if type(IGNORE_STYLES[iLexer])=="nil" and editor.Lexer~=1 then -- Performance: Disable Ac for the Null Lexer
       -- print("ac>Current lexer not supported. Using generic Mode.")
        iLexer=SCLEX_GENERIC
    end
    if IGNORE_STYLES[iLexer] then
    -- Define a function for calling later:
        shouldIgnorePos = function(pos)       
            return isInTable(IGNORE_STYLES[iLexer], editor.StyleAt[pos])
        end
    else
        -- Optional: Disable autocomplete popups for unknown lexers.
        shouldIgnorePos = function(pos) return true end
    end
end

--
-- Append current Lexers Api Files
--
local function getApiNames()
    local lexer = editor.LexerLanguage
    if apiCache[lexer] then
        return apiCache[lexer]
    end
    local apiNames = {}
    local apiFiles = props["APIPath"] or ""
    apiFiles:gsub("[^;]+", function(apiFile) -- For each in ;-delimited list.
    if not file_exists(apiFile) then print ("ac>ignoring nonExistant apiFile: "..apiFile) return end
    for name in io.lines(apiFile) do
        name = name:gsub("[(, ].*", "") -- Discard parameters/comments.
            if string.len(name) > 0 then
                apiNames[name] = true
            end
        end
        return ""
    end)

   apiNames= appendCTags(apiNames)
    if lexer~=nil then
        apiCache[lexer] = apiNames -- Even if it's empty
    end
    
    return apiNames
end

--
-- create AutoCompletes Keyword list
--
local function buildNames()
-- Perfomance: 
-- Disable Ac for the Null Lexer
-- only rebuild list when the buffer was modified
-- use a user settable maximum size for AutoComplete to be active

--print("build names buffer state:",buffer.dirty)

   local fSize=0
    
    if editor.Lexer~=1 and buffer.dirty==true then 
      if props["FileName"] ~="" then fSize= file_size(props["FilePath"]) end
      if fSize > AC_MAX_SIZE then  return end  

        setLexerSpecificStuff()
        -- Reset our array of names.
        names = {}
        -- Collect all words matching the given patterns.
        local unique = {}
        for i, pattern in ipairs(IDENTIFIER_PATTERNS) do
            local startPos, endPos
            endPos = 0
            while true do
                startPos, endPos = editor:findtext(pattern, SCFIND_REGEXP, endPos + 1)
                if not startPos then
                    break
                end
                
                if not shouldIgnorePos(startPos) then
                    if endPos-startPos+1 >= MIN_IDENTIFIER_LEN then
                        -- Create one key-value pair per unique word:
                        local name = editor:textrange(startPos, endPos)
                        unique[normalize(name)] = name
                    end
                end
            end
        end
        -- Build an ordered array from the table of names.
        for name in pairs(getApiNames()) do
            -- This also "case-corrects"; e.g. "gui" -> "Gui"
            unique[normalize(name)] = name
        end
        
        for _,name in pairs(unique) do
            table.insert(names, name)
        end
        
        table.sort(names, function(a,b) return normalize(a) < normalize(b) end)
        buffer.namesForAutoComplete = names -- Cache it for OnSwitchFile.
        buffer.dirty=false
        --print ("ac>buildNames:  ...Created a new keywordlist")   
    end
end


local lastAutoCItem = 0 -- Used by handleKey().
local menuItems

local function handleChar(char, calledByHotkey)
    local pos = editor.CurrentPos
    local startPos = editor:WordStartPosition(pos, true)
    local len = pos - startPos
    buffer.dirty=true
    
    if ipairs==nil then ipairs={} end
    if editor.Lexer==1  then return end
    
    if not INCREMENTAL and editor:AutoCActive() then
        -- Nothing to do.
        return
    end
    
    if len < MIN_PREFIX_LEN then
        if editor:AutoCActive() then
            if len == 0 then
                -- Happens sometimes after typing ")".
                editor:AutoCCancel()
                return
            end
            -- Otherwise, autocomplete is already showing so may as well
            -- keep it updated even though len < MIN_PREFIX_LEN.
        else
            if char then
                -- Not enough text to trigger autocomplete, so return.
                return
            end
            -- Otherwise, we were called explicitly without a param.
        end
    end

    if not editor:AutoCActive() and shouldIgnorePos(startPos) and not calledByHotkey then
        -- User is typing in a comment or string, so don't automatically
        -- pop up the auto-complete window.
        return
    end

    local prefix = normalize(editor:textrange(startPos, pos))       

    menuItems = {}
    for i, name in ipairs(names) do
        local s = normalize(string.sub(name, 1, len))
        if s >= prefix then
            if s == prefix then 
                table.insert(menuItems, name)
            else
                break -- There will be no more matches.
            end
        end
    end
    if notempty(menuItems) then
        -- Show or update the auto-complete list.
        local list = table.concat(menuItems, "\1")
        editor.AutoCIgnoreCase = IGNORE_CASE
        editor.AutoCCaseInsensitiveBehaviour = 1 -- Do NOT pre-select a case-sensitive match
        editor.AutoCSeparator = 1
        editor.AutoCMaxHeight = 10
        editor:AutoCShow(len, list)
        -- Check if we should auto-auto-complete.
        if normalize(menuItems[1]) == prefix and not calledByHotkey then
            -- User has completely typed the only item, so cancel.
            if CASE_CORRECT then
                if CASE_CORRECT_INSTANT or #menuItems == 1 then
                    -- Make sure the correct item is selected.
                    editor:AutoCShow(len, menuItems[1])
                    editor:AutoCComplete()
                end
                if #menuItems > 1 then
                    editor:AutoCShow(len, list)
                end
            end
            if #menuItems == 1 then
                editor:AutoCCancel()
                return
            end
        end
        lastAutoCItem = #menuItems - 1
        if lastAutoCItem == 0 and calledByHotkey and CHOOSE_SINGLE then
            editor:AutoCComplete()
        end
    else
        -- No relevant items.
        if editor:AutoCActive() then
            editor:AutoCCancel()
        end
    end
end


local function handleKey(key, shift, ctrl, alt)
   if editor.Lexer==1  then return end
    
    if key == 0x20 and ctrl and not (shift or alt) then -- ^Space
        handleChar(nil, true)
        return true
    end
    if alt or not editor:AutoCActive() then return end
    if key == 0x8 then -- VK_BACK
        if not ctrl then
            -- Need to handle it here rather than relying on the default
            -- processing, which would occur after handleChar() returns:
            editor:DeleteBack()
            handleChar()
            return true
        end
    elseif key == 0x25 then -- VK_LEFT
        if not shift then
            if ctrl then
                editor:WordLeft() -- See VK_BACK for comments.
            else
                editor:CharLeft() -- See VK_BACK for comments.
            end
            handleChar()
            return true
        end
    elseif key == 0x26 then -- VK_UP
        if editor.AutoCCurrent == 0 then
            -- User pressed UP when already at the top of the list.
            if WRAP_ARROW_KEYS then
                -- Select the last item.
                editor:AutoCSelect(menuItems[#menuItems])
                return true
            end
            -- Cancel the list and let the caret move up.
            editor:AutoCCancel()
        end
    elseif key == 0x28 then -- VK_DOWN
        if editor.AutoCCurrent == lastAutoCItem then
            -- User pressed DOWN when already at the bottom of the list.
            if WRAP_ARROW_KEYS then
                -- Select the first item.
                editor:AutoCSelect(menuItems[1])
                return true
            end
            -- Cancel the list and let the caret move down.
            editor:AutoCCancel()
        end
    elseif key == 0x5A and ctrl then -- ^z
        editor:AutoCCancel()
    end
end


-- Event handlers

local events = {
    OnChar          = handleChar,
    OnKey           = handleKey,
    OnSave          = buildNames,
    OnDwellStart  = buildNames, -- should be raised on any User Interaction (Mousemove/Keybord Nav...) 
    OnSwitchFile    = function()
        -- Use this file's cached list if possible:
        names = buffer.namesForAutoComplete
        if not names then
            -- Otherwise, build a new list.
            buffer.dirty=true
            buildNames()
        else
            setLexerSpecificStuff()
        end
    end,
    OnOpen          = function()
        -- Ensure the document is styled first, so we can filter out
        -- words in comments and strings.
        editor:Colourise(0, editor.Length)
        -- Then do the real work.
        buffer.dirty=true
        buildNames()
    end
}
-- Add event handlers in a cooperative fashion:
for evt, func in pairs(events) do
    local oldfunc = _G[evt]
    if oldfunc then
        _G[evt] = function(...) return func(...) or oldfunc(...) end
    else
        _G[evt] = func
    end
end
