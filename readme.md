	  ~- SciTE_webdev -~

[15.08.2016]	::.:::..:: Stable Release (1.11) ::.:::..::
--	- Redone; Portability Patch.
	 - Use %userprofile%\.Scite, $(env.scite_userhome) or just Scite's binPath.    
	- Fix; MSDN and CPP API File parsers.
	- New; Properties: Include XML & Yaml. Most props use theming / New theme.white
	- Redone VBA/WSH/JS APis.
	- New; Autocomplete: Grow and Shrink List dynamically.
	- Fix; Calltips: Now finally helpful and usable.
	- New; Use "release" Bins by default to reduce download size.
	- Fix; Remove unnecessary runtime dependencies. Be friendly to Reactos RC1.
	- New; .add_toolPath.cmd to Set Path for Scites Toolbase. 
	- Change; Move all Lua related files to Addons\lua-modules
	- Change; Add wrapper scripts for all Tools and move them to Addons\tools 
	- Add; Code Linter and Beautify Tools

[24.07.2016]
--	* Highlite: Overhauled many Regions...
	- New: Support theming for editor and lexers. New default Theme.
	- Fix: Dynamic filters in File Dialogs
	- Fix: Reworked and documented configuration properties.
	- Fix: Improve running Batch and traceing PHP, Python and Lua scripts.
	- Fix: Scite on writeProtected Pathes (eg C:\ProgramFiles)
	- New: Reworked Optionsmenu, new Debug menu.
	- Next Release will be RC.	

[23.03.2016]
--	* Fix remaining lib dependencies.
	- New CPP API (947 Entries) / Implemented enhanced Autocomplete.
	- Redone api files in goodies / Many Bug Fixes
	- Note: If you plan to use the GDB Interface, please install MinGW

[01.02.2016]
--	Fix statically Linking C Library (libgcc-s-dw2-1-dll)
	- Fix jQuery API :Selectors / Fix Toolbar Font Switching / Fix vbScript Highlitening / Cleanup BuildSys	
	
[16.01.2016]
--	* Sync with SciTE 3.63 Dev
	- Linux binaries / Fixed to Build System and Lua ApiDocs 
	- current Scite goodies (Patches / API Files)
	
[02.01.2016]
--	* a good Set of fixes for Debugging Infra.
	- Now supports GDB based debugging - Hey - Scite debugging Scite works :=)
	- New Prop debug.askTarget - shows a Strip to choose debuggee binary. / utilize lfs.chdir
	 (needs mingwbin in your Path) 
	- Integrate jQuery and js keywords / cleanup Properties.
	
[20.12.2015]
--	* a usable debugging infrastructure (but still via Tools menu)
	 - Finally supports lua debugging, more Languages coming soon. 
	 - Seeya next year Release :)  - Thoraten 
	
[11.12.2015]
--	* Initial support for debugging infrastructure via tools menu
	* Add interactive Lua Prompt. 
	* Fix Debug Markers. 
	   
[A09.12.2015]
--	* Port [user.toolbar] from Scite_ru. -> Credits Guys!
	 - See: http://scite-ru.bitbucket.org/pack/doc/SciTE-Ru_Kernel.html
	* Fix Editor Wrap / fix vba Keywords / add custom Styles / Cleanup Code / Fix Scite shared CLib dependency 
	* Add LuaSockets 3.0-RC1 / mobdebug.lua / Add LuaExpat 1.3.0
	
[A02.12.2015]
--	* Import Wsh and Vba Api Calltips. (Functions/Props/Methods & Objects)
	* Compatibility with Scite_Lua Extension and style Systems
	
[A27.11.2015]
--	* MSDN Sync: Allow Pause / Resume Sync feature.
	  ( Fix up sync on slower Connections.)
	  ( See Steampunk/Api_docs/msdn.js.obj.ref )
	* Finished import of Javascript Object Calltips
	  (now with enhanced LineWrap for Js and jQuery)
		
[A22.11.2015]
--	* Introduce Scite SideBar.lua ( needs shell.dll / gui.dll )
	   (Libs compiled from Source. Please see Code/SciTE_SupportLib)
	* Shrink down extmans scite_lua Scripts to a good base. 
	* Add perl and lua.api (plus a nice WorldofWarcraft lua api :).
	* Fixed LuaLib makefiles to statically link libgcc. Cleaned up Directories.
	* Introduce code\SciTE_ApiDocs\msdn (syncs Language Docs with local repo)
	
[B17.11.2015]
--	* Implement List based File associations. (See FileExt.list)
	* Fix REG 3.0 - XP Compatibility
	* Clean up Tool Command Menu. (Language specific Menu entries)
	* Clean up SciTE.platfom.properties.
	* Hey reaching nearly 42 Downloads 8)
	* Include extman.lua and a fancy HEX Editor
	
[E14.11.2015]
--	* Sync with vanilla SciTE 3.62
	* current language property files
	* Using  language.menu wildcards now 
		(compatible with Scite 3.62. just copy and be happy :)
	* coffeescript and csharp keywords
	* Sync Help Files with 3.62
	* fixed Scite default actions (explorer "open with")
	* use relative Pathes everywhere now
	* moved SciTE_start_usb to testcases
	
