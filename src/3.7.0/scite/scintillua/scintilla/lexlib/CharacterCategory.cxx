// Scintilla source code edit control
/** @file CharacterCategory.cxx
 ** Returns the Unicode general category of a character.
 ** Table automatically regenerated by scripts/GenerateCharacterCategory.py
 ** Should only be rarely regenerated for new versions of Unicode.
 **/
// Copyright 2013 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.

#include <algorithm>

#include "StringCopy.h"
#include "CharacterCategory.h"

#ifdef SCI_NAMESPACE
namespace Scintilla {
#endif

namespace {
	// Use an unnamed namespace to protect the declarations from name conflicts

const int catRanges[] = {
//++Autogenerated -- start of section automatically generated
// Created with Python 3.6.1,  Unicode 9.0.0
25,
1046,
1073,
1171,
1201,
1293,
1326,
1361,
1394,
1425,
1452,
1489,
1544,
1873,
1938,
2033,
2080,
2925,
2961,
2990,
3028,
3051,
3092,
3105,
3949,
3986,
4014,
4050,
4089,
5142,
5169,
5203,
5333,
5361,
5396,
5429,
5444,
5487,
5522,
5562,
5589,
5620,
5653,
5682,
5706,
5780,
5793,
5841,
5908,
5930,
5956,
6000,
6026,
6129,
6144,
6898,
6912,
7137,
7922,
7937,
8192,
8225,
8256,
8289,
8320,
8353,
8384,
8417,
8448,
8481,
8512,
8545,
8576,
8609,
8640,
8673,
8704,
8737,
8768,
8801,
8832,
8865,
8896,
8929,
8960,
8993,
9024,
9057,
9088,
9121,
9152,
9185,
9216,
9249,
9280,
9313,
9344,
9377,
9408,
9441,
9472,
9505,
9536,
9569,
9600,
9633,
9664,
9697,
9728,
9761,
9792,
9825,
9856,
9889,
9920,
9953,
10016,
10049,
10080,
10113,
10144,
10177,
10208,
10241,
10272,
10305,
10336,
10369,
10400,
10433,
10464,
10497,
10560,
10593,
10624,
10657,
10688,
10721,
10752,
10785,
10816,
10849,
10880,
10913,
10944,
10977,
11008,
11041,
11072,
11105,
11136,
11169,
11200,
11233,
11264,
11297,
11328,
11361,
11392,
11425,
11456,
11489,
11520,
11553,
11584,
11617,
11648,
11681,
11712,
11745,
11776,
11809,
11840,
11873,
11904,
11937,
11968,
12001,
12032,
12097,
12128,
12161,
12192,
12225,
12320,
12385,
12416,
12449,
12480,
12545,
12576,
12673,
12736,
12865,
12896,
12961,
12992,
13089,
13184,
13249,
13280,
13345,
13376,
13409,
13440,
13473,
13504,
13569,
13600,
13633,
13696,
13729,
13760,
13825,
13856,
13953,
13984,
14017,
14048,
14113,
14180,
14208,
14241,
14340,
14464,
14498,
14529,
14560,
14594,
14625,
14656,
14690,
14721,
14752,
14785,
14816,
14849,
14880,
14913,
14944,
14977,
15008,
15041,
15072,
15105,
15136,
15169,
15200,
15233,
15296,
15329,
15360,
15393,
15424,
15457,
15488,
15521,
15552,
15585,
15616,
15649,
15680,
15713,
15744,
15777,
15808,
15841,
15904,
15938,
15969,
16000,
16033,
16064,
16161,
16192,
16225,
16256,
16289,
16320,
16353,
16384,
16417,
16448,
16481,
16512,
16545,
16576,
16609,
16640,
16673,
16704,
16737,
16768,
16801,
16832,
16865,
16896,
16929,
16960,
16993,
17024,
17057,
17088,
17121,
17152,
17185,
17216,
17249,
17280,
17313,
17344,
17377,
17408,
17441,
17472,
17505,
17536,
17569,
17600,
17633,
17664,
17697,
17728,
17761,
17792,
17825,
17856,
17889,
17920,
17953,
17984,
18017,
18240,
18305,
18336,
18401,
18464,
18497,
18528,
18657,
18688,
18721,
18752,
18785,
18816,
18849,
18880,
18913,
21124,
21153,
22019,
22612,
22723,
23124,
23555,
23732,
23939,
23988,
24003,
24052,
24581,
28160,
28193,
28224,
28257,
28291,
28340,
28352,
28385,
28445,
28483,
28513,
28625,
28640,
28701,
28820,
28864,
28913,
28928,
29053,
29056,
29117,
29120,
29185,
29216,
29789,
29792,
30081,
31200,
31233,
31296,
31393,
31488,
31521,
31552,
31585,
31616,
31649,
31680,
31713,
31744,
31777,
31808,
31841,
31872,
31905,
31936,
31969,
32000,
32033,
32064,
32097,
32128,
32161,
32192,
32225,
32384,
32417,
32466,
32480,
32513,
32544,
32609,
32672,
34305,
35840,
35873,
35904,
35937,
35968,
36001,
36032,
36065,
36096,
36129,
36160,
36193,
36224,
36257,
36288,
36321,
36352,
36385,
36416,
36449,
36480,
36513,
36544,
36577,
36608,
36641,
36672,
36705,
36736,
36769,
36800,
36833,
36864,
36897,
36949,
36965,
37127,
37184,
37217,
37248,
37281,
37312,
37345,
37376,
37409,
37440,
37473,
37504,
37537,
37568,
37601,
37632,
37665,
37696,
37729,
37760,
37793,
37824,
37857,
37888,
37921,
37952,
37985,
38016,
38049,
38080,
38113,
38144,
38177,
38208,
38241,
38272,
38305,
38336,
38369,
38400,
38433,
38464,
38497,
38528,
38561,
38592,
38625,
38656,
38689,
38720,
38753,
38784,
38817,
38848,
38881,
38912,
38977,
39008,
39041,
39072,
39105,
39136,
39169,
39200,
39233,
39264,
39297,
39328,
39361,
39424,
39457,
39488,
39521,
39552,
39585,
39616,
39649,
39680,
39713,
39744,
39777,
39808,
39841,
39872,
39905,
39936,
39969,
40000,
40033,
40064,
40097,
40128,
40161,
40192,
40225,
40256,
40289,
40320,
40353,
40384,
40417,
40448,
40481,
40512,
40545,
40576,
40609,
40640,
40673,
40704,
40737,
40768,
40801,
40832,
40865,
40896,
40929,
40960,
40993,
41024,
41057,
41088,
41121,
41152,
41185,
41216,
41249,
41280,
41313,
41344,
41377,
41408,
41441,
41472,
41505,
41536,
41569,
41600,
41633,
41664,
41697,
41728,
41761,
41792,
41825,
41856,
41889,
41920,
41953,
41984,
42017,
42048,
42081,
42112,
42145,
42176,
42209,
42240,
42273,
42304,
42337,
42368,
42401,
42432,
42465,
42525,
42528,
43773,
43811,
43857,
44061,
44065,
45341,
45361,
45388,
45437,
45493,
45555,
45597,
45605,
47052,
47077,
47121,
47141,
47217,
47237,
47313,
47333,
47389,
47620,
48509,
48644,
48753,
48829,
49178,
49362,
49457,
49523,
49553,
49621,
49669,
50033,
50074,
50109,
50129,
50180,
51203,
51236,
51557,
52232,
52561,
52676,
52741,
52772,
55953,
55972,
56005,
56250,
56277,
56293,
56483,
56549,
56629,
56645,
56772,
56840,
57156,
57269,
57316,
57361,
57821,
57850,
57860,
57893,
57924,
58885,
59773,
59812,
62661,
63012,
63069,
63496,
63812,
64869,
65155,
65237,
65265,
65347,
65405,
65540,
66245,
66371,
66405,
66691,
66725,
66819,
66853,
67037,
67089,
67581,
67588,
68389,
68509,
68561,
68605,
70660,
71357,
71364,
71645,
72325,
72794,
72805,
73830,
73860,
75589,
75622,
75653,
75684,
75718,
75813,
76070,
76197,
76230,
76292,
76325,
76548,
76869,
76945,
77000,
77329,
77347,
77380,
77861,
77894,
77981,
77988,
78269,
78308,
78397,
78436,
79165,
79172,
79421,
79428,
79485,
79556,
79709,
79749,
79780,
79814,
79909,
80061,
80102,
80189,
80230,
80293,
80324,
80381,
80614,
80669,
80772,
80861,
80868,
80965,
81053,
81096,
81412,
81491,
81546,
81749,
81779,
81821,
81957,
82022,
82077,
82084,
82301,
82404,
82493,
82532,
83261,
83268,
83517,
83524,
83613,
83620,
83709,
83716,
83805,
83845,
83901,
83910,
84005,
84093,
84197,
84285,
84325,
84445,
84517,
84573,
84772,
84925,
84932,
84989,
85192,
85509,
85572,
85669,
85725,
86053,
86118,
86173,
86180,
86493,
86500,
86621,
86628,
87357,
87364,
87613,
87620,
87709,
87716,
87901,
87941,
87972,
88006,
88101,
88285,
88293,
88358,
88413,
88422,
88485,
88541,
88580,
88637,
89092,
89157,
89245,
89288,
89617,
89651,
89693,
89892,
89949,
90149,
90182,
90269,
90276,
90557,
90596,
90685,
90724,
91453,
91460,
91709,
91716,
91805,
91812,
91997,
92037,
92068,
92102,
92133,
92166,
92197,
92349,
92390,
92477,
92518,
92581,
92637,
92869,
92902,
92957,
93060,
93149,
93156,
93253,
93341,
93384,
93717,
93732,
93770,
93981,
94277,
94308,
94365,
94372,
94589,
94660,
94781,
94788,
94941,
95012,
95101,
95108,
95165,
95172,
95261,
95332,
95421,
95492,
95613,
95684,
96093,
96198,
96261,
96294,
96381,
96454,
96573,
96582,
96677,
96733,
96772,
96829,
96998,
97053,
97480,
97802,
97909,
98099,
98133,
98173,
98309,
98342,
98461,
98468,
98749,
98756,
98877,
98884,
99645,
99652,
100189,
100260,
100293,
100390,
100541,
100549,
100669,
100677,
100829,
101029,
101117,
101124,
101245,
101380,
101445,
101533,
101576,
101917,
102154,
102389,
102404,
102437,
102470,
102557,
102564,
102845,
102852,
102973,
102980,
103741,
103748,
104093,
104100,
104285,
104325,
104356,
104390,
104421,
104454,
104637,
104645,
104678,
104765,
104774,
104837,
104925,
105126,
105213,
105412,
105469,
105476,
105541,
105629,
105672,
106013,
106020,
106109,
106533,
106566,
106653,
106660,
106941,
106948,
107069,
107076,
108413,
108452,
108486,
108581,
108733,
108742,
108861,
108870,
108965,
108996,
109045,
109085,
109188,
109286,
109322,
109540,
109637,
109725,
109768,
110090,
110389,
110404,
110621,
110662,
110749,
110756,
111357,
111428,
112221,
112228,
112541,
112548,
112605,
112644,
112893,
112965,
113021,
113126,
113221,
113341,
113349,
113405,
113414,
113693,
113864,
114205,
114246,
114321,
114365,
114724,
116261,
116292,
116357,
116605,
116723,
116740,
116931,
116965,
117233,
117256,
117585,
117661,
118820,
118909,
118916,
118973,
119012,
119101,
119108,
119165,
119204,
119261,
119428,
119581,
119588,
119837,
119844,
119965,
119972,
120029,
120036,
120093,
120132,
120221,
120228,
120357,
120388,
120453,
120669,
120677,
120740,
120797,
120836,
121021,
121027,
121085,
121093,
121309,
121352,
121693,
121732,
121885,
122884,
122933,
123025,
123509,
123537,
123573,
123653,
123733,
123912,
124234,
124565,
124581,
124629,
124645,
124693,
124709,
124749,
124782,
124813,
124846,
124870,
124932,
125213,
125220,
126397,
126501,
126950,
126981,
127153,
127173,
127236,
127397,
127773,
127781,
128957,
128981,
129221,
129269,
129469,
129493,
129553,
129717,
129841,
129917,
131076,
132454,
132517,
132646,
132677,
132870,
132901,
132966,
133029,
133092,
133128,
133457,
133636,
133830,
133893,
133956,
134085,
134180,
134214,
134308,
134374,
134596,
134693,
134820,
135237,
135270,
135333,
135398,
135589,
135620,
135654,
135688,
136006,
136101,
136149,
136192,
137437,
137440,
137501,
137632,
137693,
137732,
139121,
139139,
139172,
149821,
149828,
149981,
150020,
150269,
150276,
150333,
150340,
150493,
150532,
151869,
151876,
152029,
152068,
153149,
153156,
153309,
153348,
153597,
153604,
153661,
153668,
153821,
153860,
154365,
154372,
156221,
156228,
156381,
156420,
158589,
158629,
158737,
159018,
159677,
159748,
160277,
160605,
160768,
163549,
163585,
163805,
163852,
163876,
183729,
183780,
184342,
184356,
185197,
185230,
185277,
185348,
187761,
187849,
187940,
188221,
188420,
188861,
188868,
188997,
189117,
189444,
190021,
190129,
190205,
190468,
191045,
191133,
191492,
191933,
191940,
192061,
192069,
192157,
192516,
194181,
194246,
194277,
194502,
194757,
194790,
194853,
195217,
195299,
195345,
195443,
195460,
195493,
195549,
195592,
195933,
196106,
196445,
196625,
196812,
196849,
196965,
197082,
197117,
197128,
197469,
197636,
198755,
198788,
200477,
200708,
200869,
200932,
202021,
202052,
202109,
202244,
204509,
204804,
205821,
205829,
205926,
206053,
206118,
206237,
206342,
206405,
206438,
206629,
206749,
206869,
206909,
206993,
207048,
207364,
208349,
208388,
208573,
208900,
210333,
210436,
211293,
211464,
211786,
211837,
211925,
212996,
213733,
213798,
213861,
213917,
213969,
214020,
215718,
215749,
215782,
215813,
216061,
216069,
216102,
216133,
216166,
216229,
216486,
216677,
217021,
217061,
217096,
217437,
217608,
217949,
218129,
218339,
218385,
218589,
218629,
219079,
219133,
221189,
221318,
221348,
222853,
222886,
222917,
223078,
223109,
223142,
223301,
223334,
223396,
223645,
223752,
224081,
224309,
224613,
224917,
225213,
225285,
225350,
225380,
226342,
226373,
226502,
226565,
226630,
226661,
226756,
226824,
227140,
228549,
228582,
228613,
228678,
228773,
228806,
228837,
228934,
229021,
229265,
229380,
230534,
230789,
231046,
231109,
231197,
231281,
231432,
231773,
231844,
231944,
232260,
233219,
233425,
233473,
233789,
235537,
235805,
236037,
236145,
236165,
236582,
236613,
236836,
236965,
236996,
237126,
237189,
237220,
237309,
237317,
237405,
237569,
238979,
240993,
241411,
241441,
242531,
243717,
245469,
245605,
245760,
245793,
245824,
245857,
245888,
245921,
245952,
245985,
246016,
246049,
246080,
246113,
246144,
246177,
246208,
246241,
246272,
246305,
246336,
246369,
246400,
246433,
246464,
246497,
246528,
246561,
246592,
246625,
246656,
246689,
246720,
246753,
246784,
246817,
246848,
246881,
246912,
246945,
246976,
247009,
247040,
247073,
247104,
247137,
247168,
247201,
247232,
247265,
247296,
247329,
247360,
247393,
247424,
247457,
247488,
247521,
247552,
247585,
247616,
247649,
247680,
247713,
247744,
247777,
247808,
247841,
247872,
247905,
247936,
247969,
248000,
248033,
248064,
248097,
248128,
248161,
248192,
248225,
248256,
248289,
248320,
248353,
248384,
248417,
248448,
248481,
248512,
248545,
248576,
248609,
248640,
248673,
248704,
248737,
248768,
248801,
248832,
248865,
248896,
248929,
248960,
248993,
249024,
249057,
249088,
249121,
249152,
249185,
249216,
249249,
249280,
249313,
249344,
249377,
249408,
249441,
249472,
249505,
249536,
249569,
249600,
249633,
249664,
249697,
249728,
249761,
249792,
249825,
249856,
249889,
249920,
249953,
249984,
250017,
250048,
250081,
250112,
250145,
250176,
250209,
250240,
250273,
250304,
250337,
250368,
250401,
250432,
250465,
250496,
250529,
250816,
250849,
250880,
250913,
250944,
250977,
251008,
251041,
251072,
251105,
251136,
251169,
251200,
251233,
251264,
251297,
251328,
251361,
251392,
251425,
251456,
251489,
251520,
251553,
251584,
251617,
251648,
251681,
251712,
251745,
251776,
251809,
251840,
251873,
251904,
251937,
251968,
252001,
252032,
252065,
252096,
252129,
252160,
252193,
252224,
252257,
252288,
252321,
252352,
252385,
252416,
252449,
252480,
252513,
252544,
252577,
252608,
252641,
252672,
252705,
252736,
252769,
252800,
252833,
252864,
252897,
252928,
252961,
252992,
253025,
253056,
253089,
253120,
253153,
253184,
253217,
253248,
253281,
253312,
253345,
253376,
253409,
253440,
253473,
253504,
253537,
253568,
253601,
253632,
253665,
253696,
253729,
253760,
253793,
253824,
253857,
253888,
253921,
254208,
254465,
254685,
254720,
254941,
254977,
255232,
255489,
255744,
256001,
256221,
256256,
256477,
256513,
256797,
256800,
256861,
256864,
256925,
256928,
256989,
256992,
257025,
257280,
257537,
258013,
258049,
258306,
258561,
258818,
259073,
259330,
259585,
259773,
259777,
259840,
259970,
260020,
260033,
260084,
260161,
260285,
260289,
260352,
260482,
260532,
260609,
260765,
260801,
260864,
261021,
261044,
261121,
261376,
261556,
261661,
261697,
261821,
261825,
261888,
262018,
262068,
262141,
262166,
262522,
262668,
262865,
262927,
262960,
262989,
263023,
263088,
263117,
263151,
263185,
263447,
263480,
263514,
263670,
263697,
263983,
264016,
264049,
264171,
264241,
264338,
264365,
264398,
264433,
264786,
264817,
264843,
264881,
265206,
265242,
265405,
265434,
265738,
265763,
265821,
265866,
266066,
266157,
266190,
266211,
266250,
266578,
266669,
266702,
266749,
266755,
267197,
267283,
268285,
268805,
269223,
269349,
269383,
269477,
269885,
270357,
270400,
270453,
270560,
270613,
270657,
270688,
270785,
270848,
270945,
270997,
271008,
271061,
271122,
271136,
271317,
271488,
271541,
271552,
271605,
271616,
271669,
271680,
271829,
271841,
271872,
272001,
272036,
272161,
272213,
272257,
272320,
272402,
272544,
272577,
272725,
272754,
272789,
272833,
272885,
272906,
273417,
274528,
274561,
274601,
274730,
274773,
274845,
274962,
275125,
275282,
275349,
275474,
275509,
275570,
275605,
275666,
275701,
275922,
275957,
276946,
277013,
277074,
277109,
277138,
277173,
278162,
286741,
286989,
287022,
287053,
287086,
287125,
287762,
287829,
288045,
288078,
288117,
290706,
290741,
291698,
292501,
293778,
293973,
294909,
294933,
296189,
296981,
297341,
297994,
299925,
302410,
303125,
308978,
309013,
309298,
309333,
311058,
311317,
314866,
314901,
322829,
322862,
322893,
322926,
322957,
322990,
323021,
323054,
323085,
323118,
323149,
323182,
323213,
323246,
323274,
324245,
325650,
325805,
325838,
325874,
326861,
326894,
326925,
326958,
326989,
327022,
327053,
327086,
327117,
327150,
327186,
327701,
335890,
340077,
340110,
340141,
340174,
340205,
340238,
340269,
340302,
340333,
340366,
340397,
340430,
340461,
340494,
340525,
340558,
340589,
340622,
340653,
340686,
340717,
340750,
340786,
342797,
342830,
342861,
342894,
342930,
343949,
343982,
344018,
352277,
353810,
354485,
354546,
354741,
355997,
356053,
357085,
357141,
358237,
358325,
358717,
358741,
359005,
359829,
359965,
360448,
361981,
361985,
363517,
363520,
363553,
363584,
363681,
363744,
363777,
363808,
363841,
363872,
363905,
363936,
364065,
364096,
364129,
364192,
364225,
364419,
364480,
364577,
364608,
364641,
364672,
364705,
364736,
364769,
364800,
364833,
364864,
364897,
364928,
364961,
364992,
365025,
365056,
365089,
365120,
365153,
365184,
365217,
365248,
365281,
365312,
365345,
365376,
365409,
365440,
365473,
365504,
365537,
365568,
365601,
365632,
365665,
365696,
365729,
365760,
365793,
365824,
365857,
365888,
365921,
365952,
365985,
366016,
366049,
366080,
366113,
366144,
366177,
366208,
366241,
366272,
366305,
366336,
366369,
366400,
366433,
366464,
366497,
366528,
366561,
366592,
366625,
366656,
366689,
366720,
366753,
366784,
366817,
366848,
366881,
366912,
366945,
366976,
367009,
367040,
367073,
367104,
367137,
367168,
367201,
367232,
367265,
367296,
367329,
367360,
367393,
367424,
367457,
367488,
367521,
367552,
367585,
367616,
367649,
367680,
367713,
367797,
367968,
368001,
368032,
368065,
368101,
368192,
368225,
368285,
368433,
368554,
368593,
368641,
369885,
369889,
369949,
370081,
370141,
370180,
371997,
372195,
372241,
372285,
372709,
372740,
373501,
373764,
374013,
374020,
374269,
374276,
374525,
374532,
374781,
374788,
375037,
375044,
375293,
375300,
375549,
375556,
375805,
375813,
376849,
376911,
376944,
376975,
377008,
377041,
377135,
377168,
377201,
377231,
377264,
377297,
377580,
377617,
377676,
377713,
377743,
377776,
377809,
377871,
377904,
377933,
377966,
377997,
378030,
378061,
378094,
378125,
378158,
378193,
378339,
378385,
378700,
378769,
378892,
378929,
378957,
378993,
379069,
380949,
381789,
381813,
384669,
385045,
391901,
392725,
393117,
393238,
393265,
393365,
393379,
393412,
393449,
393485,
393518,
393549,
393582,
393613,
393646,
393677,
393710,
393741,
393774,
393813,
393869,
393902,
393933,
393966,
393997,
394030,
394061,
394094,
394124,
394157,
394190,
394261,
394281,
394565,
394694,
394764,
394787,
394965,
395017,
395107,
395140,
395185,
395221,
395293,
395300,
398077,
398117,
398196,
398243,
398308,
398348,
398372,
401265,
401283,
401380,
401437,
401572,
402909,
402980,
406013,
406037,
406090,
406229,
406532,
407421,
407573,
408733,
409092,
409621,
410621,
410634,
410965,
411914,
412181,
412202,
412693,
413706,
414037,
415274,
415765,
417789,
417813,
425988,
636637,
636949,
638980,
1309405,
1310724,
1311395,
1311428,
1348029,
1348117,
1349885,
1350148,
1351427,
1351633,
1351684,
1360259,
1360305,
1360388,
1360904,
1361220,
1361309,
1361920,
1361953,
1361984,
1362017,
1362048,
1362081,
1362112,
1362145,
1362176,
1362209,
1362240,
1362273,
1362304,
1362337,
1362368,
1362401,
1362432,
1362465,
1362496,
1362529,
1362560,
1362593,
1362624,
1362657,
1362688,
1362721,
1362752,
1362785,
1362816,
1362849,
1362880,
1362913,
1362944,
1362977,
1363008,
1363041,
1363072,
1363105,
1363136,
1363169,
1363200,
1363233,
1363264,
1363297,
1363328,
1363361,
1363396,
1363429,
1363463,
1363569,
1363589,
1363921,
1363939,
1363968,
1364001,
1364032,
1364065,
1364096,
1364129,
1364160,
1364193,
1364224,
1364257,
1364288,
1364321,
1364352,
1364385,
1364416,
1364449,
1364480,
1364513,
1364544,
1364577,
1364608,
1364641,
1364672,
1364705,
1364736,
1364769,
1364800,
1364833,
1364867,
1364933,
1364996,
1367241,
1367557,
1367633,
1367837,
1368084,
1368803,
1369108,
1369152,
1369185,
1369216,
1369249,
1369280,
1369313,
1369344,
1369377,
1369408,
1369441,
1369472,
1369505,
1369536,
1369569,
1369664,
1369697,
1369728,
1369761,
1369792,
1369825,
1369856,
1369889,
1369920,
1369953,
1369984,
1370017,
1370048,
1370081,
1370112,
1370145,
1370176,
1370209,
1370240,
1370273,
1370304,
1370337,
1370368,
1370401,
1370432,
1370465,
1370496,
1370529,
1370560,
1370593,
1370624,
1370657,
1370688,
1370721,
1370752,
1370785,
1370816,
1370849,
1370880,
1370913,
1370944,
1370977,
1371008,
1371041,
1371072,
1371105,
1371136,
1371169,
1371200,
1371233,
1371264,
1371297,
1371328,
1371361,
1371392,
1371425,
1371456,
1371489,
1371520,
1371553,
1371584,
1371617,
1371651,
1371681,
1371936,
1371969,
1372000,
1372033,
1372064,
1372129,
1372160,
1372193,
1372224,
1372257,
1372288,
1372321,
1372352,
1372385,
1372419,
1372468,
1372512,
1372545,
1372576,
1372609,
1372644,
1372672,
1372705,
1372736,
1372769,
1372864,
1372897,
1372928,
1372961,
1372992,
1373025,
1373056,
1373089,
1373120,
1373153,
1373184,
1373217,
1373248,
1373281,
1373312,
1373345,
1373376,
1373409,
1373440,
1373473,
1373504,
1373693,
1373696,
1373857,
1373888,
1373921,
1373981,
1375972,
1376003,
1376065,
1376100,
1376325,
1376356,
1376453,
1376484,
1376613,
1376644,
1377382,
1377445,
1377510,
1377557,
1377693,
1377802,
1378005,
1378067,
1378101,
1378141,
1378308,
1379985,
1380125,
1380358,
1380420,
1382022,
1382533,
1382621,
1382865,
1382920,
1383261,
1383429,
1384004,
1384209,
1384292,
1384337,
1384356,
1384413,
1384456,
1384772,
1385669,
1385937,
1385988,
1386725,
1387078,
1387165,
1387505,
1387524,
1388477,
1388549,
1388646,
1388676,
1390181,
1390214,
1390277,
1390406,
1390469,
1390502,
1390641,
1391069,
1391075,
1391112,
1391453,
1391569,
1391620,
1391781,
1391811,
1391844,
1392136,
1392452,
1392637,
1392644,
1393957,
1394150,
1394213,
1394278,
1394341,
1394429,
1394692,
1394789,
1394820,
1395077,
1395110,
1395165,
1395208,
1395549,
1395601,
1395716,
1396227,
1396260,
1396469,
1396548,
1396582,
1396613,
1396646,
1396676,
1398277,
1398308,
1398341,
1398436,
1398501,
1398564,
1398725,
1398788,
1398821,
1398852,
1398909,
1399652,
1399715,
1399761,
1399812,
1400166,
1400197,
1400262,
1400337,
1400388,
1400419,
1400486,
1400517,
1400573,
1400868,
1401085,
1401124,
1401341,
1401380,
1401597,
1401860,
1402109,
1402116,
1402365,
1402369,
1403764,
1403779,
1403905,
1404125,
1404417,
1406980,
1408102,
1408165,
1408198,
1408261,
1408294,
1408369,
1408390,
1408421,
1408477,
1408520,
1408861,
1409028,
1766557,
1766916,
1767677,
1767780,
1769373,
1769499,
1835036,
2039812,
2051549,
2051588,
2055005,
2056193,
2056445,
2056801,
2056989,
2057124,
2057157,
2057188,
2057522,
2057540,
2057981,
2057988,
2058173,
2058180,
2058237,
2058244,
2058333,
2058340,
2058429,
2058436,
2061908,
2062429,
2062948,
2074574,
2074605,
2074653,
2075140,
2077213,
2077252,
2079005,
2080260,
2080659,
2080693,
2080733,
2080773,
2081297,
2081517,
2081550,
2081585,
2081629,
2081797,
2082321,
2082348,
2082411,
2082477,
2082510,
2082541,
2082574,
2082605,
2082638,
2082669,
2082702,
2082733,
2082766,
2082797,
2082830,
2082861,
2082894,
2082925,
2082958,
2082993,
2083053,
2083086,
2083121,
2083243,
2083345,
2083453,
2083473,
2083596,
2083629,
2083662,
2083693,
2083726,
2083757,
2083790,
2083825,
2083922,
2083948,
2083986,
2084093,
2084113,
2084147,
2084177,
2084253,
2084356,
2084541,
2084548,
2088893,
2088954,
2088989,
2089009,
2089107,
2089137,
2089229,
2089262,
2089297,
2089330,
2089361,
2089388,
2089425,
2089480,
2089809,
2089874,
2089969,
2090016,
2090861,
2090897,
2090926,
2090964,
2090987,
2091028,
2091041,
2091885,
2091922,
2091950,
2091986,
2092013,
2092046,
2092081,
2092109,
2092142,
2092177,
2092228,
2092547,
2092580,
2094019,
2094084,
2095101,
2095172,
2095389,
2095428,
2095645,
2095684,
2095901,
2095940,
2096061,
2096147,
2096210,
2096244,
2096277,
2096307,
2096381,
2096405,
2096434,
2096565,
2096637,
2096954,
2097045,
2097117,
2097156,
2097565,
2097572,
2098429,
2098436,
2099069,
2099076,
2099165,
2099172,
2099677,
2099716,
2100189,
2101252,
2105213,
2105361,
2105469,
2105578,
2107037,
2107125,
2107401,
2109098,
2109237,
2109770,
2109845,
2109949,
2109973,
2110365,
2110485,
2110525,
2112021,
2113445,
2113501,
2117636,
2118589,
2118660,
2120253,
2120709,
2120746,
2121629,
2121732,
2122762,
2122909,
2123268,
2123817,
2123844,
2124105,
2124157,
2124292,
2125509,
2125693,
2125828,
2126813,
2126833,
2126852,
2128029,
2128132,
2128401,
2128425,
2128605,
2129920,
2131201,
2132484,
2135005,
2135048,
2135389,
2135552,
2136733,
2136833,
2138013,
2138116,
2139421,
2139652,
2141341,
2141681,
2141725,
2146308,
2156285,
2156548,
2157277,
2157572,
2157853,
2162692,
2162909,
2162948,
2163005,
2163012,
2164445,
2164452,
2164541,
2164612,
2164669,
2164708,
2165469,
2165489,
2165514,
2165764,
2166517,
2166570,
2166788,
2167805,
2168042,
2168349,
2169860,
2170493,
2170500,
2170589,
2170730,
2170884,
2171594,
2171805,
2171889,
2171908,
2172765,
2172913,
2172957,
2174980,
2176797,
2176906,
2176964,
2177034,
2177565,
2177610,
2179076,
2179109,
2179229,
2179237,
2179325,
2179461,
2179588,
2179741,
2179748,
2179869,
2179876,
2180765,
2180869,
2180989,
2181093,
2181130,
2181405,
2181649,
2181949,
2182148,
2183082,
2183153,
2183172,
2184106,
2184221,
2185220,
2185493,
2185508,
2186405,
2186493,
2186602,
2186769,
2187005,
2187268,
2189021,
2189105,
2189316,
2190045,
2190090,
2190340,
2190973,
2191114,
2191364,
2191965,
2192177,
2192317,
2192682,
2192925,
2195460,
2197821,
2199552,
2201213,
2201601,
2203261,
2203466,
2203677,
2214922,
2215933,
2228230,
2228261,
2228294,
2228324,
2230021,
2230513,
2230749,
2230858,
2231496,
2231837,
2232293,
2232390,
2232420,
2233862,
2233957,
2234086,
2234149,
2234225,
2234298,
2234321,
2234461,
2234884,
2235709,
2235912,
2236253,
2236421,
2236516,
2237669,
2237830,
2237861,
2238141,
2238152,
2238481,
2238621,
2238980,
2240101,
2240145,
2240196,
2240253,
2240517,
2240582,
2240612,
2242150,
2242245,
2242534,
2242596,
2242737,
2242885,
2242993,
2243037,
2243080,
2243396,
2243441,
2243460,
2243505,
2243613,
2243626,
2244285,
2244612,
2245213,
2245220,
2246022,
2246117,
2246214,
2246277,
2246310,
2246341,
2246417,
2246597,
2246653,
2248708,
2248957,
2248964,
2249021,
2249028,
2249181,
2249188,
2249693,
2249700,
2250033,
2250077,
2250244,
2251749,
2251782,
2251877,
2252157,
2252296,
2252637,
2252805,
2252870,
2252957,
2252964,
2253245,
2253284,
2253373,
2253412,
2254141,
2254148,
2254397,
2254404,
2254493,
2254500,
2254685,
2254725,
2254756,
2254790,
2254853,
2254886,
2255037,
2255078,
2255165,
2255206,
2255325,
2255364,
2255421,
2255590,
2255645,
2255780,
2255942,
2256029,
2256069,
2256317,
2256389,
2256573,
2260996,
2262694,
2262789,
2263046,
2263109,
2263206,
2263237,
2263268,
2263409,
2263560,
2263901,
2263921,
2263965,
2263985,
2264029,
2265092,
2266630,
2266725,
2266918,
2266949,
2266982,
2267109,
2267174,
2267205,
2267268,
2267345,
2267364,
2267421,
2267656,
2267997,
2273284,
2274790,
2274885,
2275037,
2275078,
2275205,
2275270,
2275301,
2275377,
2276100,
2276229,
2276317,
2277380,
2278918,
2279013,
2279270,
2279333,
2279366,
2279397,
2279473,
2279556,
2279613,
2279944,
2280285,
2280465,
2280893,
2281476,
2282853,
2282886,
2282917,
2282950,
2283013,
2283206,
2283237,
2283293,
2283528,
2283869,
2285572,
2286429,
2286501,
2286598,
2286661,
2286790,
2286821,
2287005,
2287112,
2287434,
2287505,
2287605,
2287645,
2298880,
2299905,
2300936,
2301258,
2301565,
2301924,
2301981,
2316292,
2318141,
2326532,
2326845,
2326852,
2328038,
2328069,
2328317,
2328325,
2328518,
2328549,
2328580,
2328625,
2328797,
2329096,
2329418,
2330045,
2330129,
2330180,
2331165,
2331205,
2331933,
2331942,
2331973,
2332198,
2332229,
2332294,
2332325,
2332413,
2359300,
2388829,
2392073,
2395645,
2395665,
2395837,
2396164,
2402461,
2490372,
2524669,
2654212,
2672893,
2949124,
2967357,
2967556,
2968573,
2968584,
2968925,
2969041,
2969117,
2972164,
2973149,
2973189,
2973361,
2973405,
2973700,
2975237,
2975473,
2975637,
2975747,
2975889,
2975925,
2975965,
2976264,
2976605,
2976618,
2976861,
2976868,
2977565,
2977700,
2978333,
3006468,
3008701,
3009028,
3009062,
3010557,
3011045,
3011171,
3011613,
3013635,
3013693,
3014660,
3210685,
3211268,
3235453,
3538948,
3539037,
3637252,
3640701,
3640836,
3641277,
3641348,
3641661,
3641860,
3642205,
3642261,
3642277,
3642353,
3642394,
3642525,
3801109,
3808989,
3809301,
3810557,
3810613,
3812518,
3812581,
3812693,
3812774,
3812986,
3813221,
3813493,
3813541,
3813781,
3814725,
3814869,
3816765,
3817493,
3819589,
3819701,
3819741,
3825685,
3828477,
3828746,
3829341,
3833856,
3834689,
3835520,
3836353,
3836605,
3836609,
3837184,
3838017,
3838848,
3838909,
3838912,
3839005,
3839040,
3839101,
3839136,
3839229,
3839264,
3839421,
3839424,
3839681,
3839837,
3839841,
3839901,
3839905,
3840157,
3840161,
3840512,
3841345,
3842176,
3842269,
3842272,
3842429,
3842464,
3842749,
3842752,
3843005,
3843009,
3843840,
3843933,
3843936,
3844093,
3844096,
3844285,
3844288,
3844349,
3844416,
3844669,
3844673,
3845504,
3846337,
3847168,
3848001,
3848832,
3849665,
3850496,
3851329,
3852160,
3852993,
3853824,
3854657,
3855581,
3855616,
3856434,
3856449,
3857266,
3857281,
3857472,
3858290,
3858305,
3859122,
3859137,
3859328,
3860146,
3860161,
3860978,
3860993,
3861184,
3862002,
3862017,
3862834,
3862849,
3863040,
3863858,
3863873,
3864690,
3864705,
3864896,
3864929,
3864989,
3865032,
3866645,
3883013,
3884789,
3884901,
3886517,
3886757,
3886805,
3887237,
3887285,
3887345,
3887517,
3887973,
3888157,
3888165,
3888669,
3932165,
3932413,
3932421,
3932989,
3933029,
3933277,
3933285,
3933373,
3933381,
3933565,
3997700,
4004029,
4004074,
4004357,
4004605,
4005888,
4006977,
4008069,
4008317,
4008456,
4008797,
4008913,
4008989,
4046852,
4047005,
4047012,
4047901,
4047908,
4047997,
4048004,
4048061,
4048100,
4048157,
4048164,
4048509,
4048516,
4048669,
4048676,
4048733,
4048740,
4048797,
4048964,
4049021,
4049124,
4049181,
4049188,
4049245,
4049252,
4049309,
4049316,
4049437,
4049444,
4049533,
4049540,
4049597,
4049636,
4049693,
4049700,
4049757,
4049764,
4049821,
4049828,
4049885,
4049892,
4049949,
4049956,
4050045,
4050052,
4050109,
4050148,
4050301,
4050308,
4050557,
4050564,
4050717,
4050724,
4050877,
4050884,
4050941,
4050948,
4051293,
4051300,
4051869,
4052004,
4052125,
4052132,
4052317,
4052324,
4052893,
4054546,
4054621,
4063253,
4064669,
4064789,
4067997,
4068373,
4068861,
4068917,
4069405,
4069429,
4069917,
4069941,
4071133,
4071434,
4071869,
4071957,
4072957,
4072981,
4074909,
4075029,
4076989,
4078805,
4079741,
4080149,
4081565,
4081685,
4081981,
4082197,
4082269,
4087829,
4095860,
4096021,
4119165,
4119573,
4119997,
4120085,
4120317,
4120597,
4124317,
4124693,
4127421,
4128789,
4129181,
4129301,
4131101,
4131349,
4131677,
4131861,
4133149,
4133397,
4134365,
4137493,
4137981,
4138005,
4138269,
4138517,
4138557,
4138613,
4139005,
4139029,
4139421,
4139541,
4140029,
4141077,
4141661,
4143125,
4143165,
4194308,
5561085,
5562372,
5695165,
5695492,
5702621,
5702660,
5887069,
6225924,
6243293,
29360186,
29360221,
29361178,
29364253,
29368325,
29376029,
31457308,
33554397,
33554460,
35651549,
//--Autogenerated -- end of section automatically generated
};

const int maxUnicode = 0x10ffff;
const int maskCategory = 0x1F;
const int nRanges = ELEMENTS(catRanges);

}

// Each element in catRanges is the start of a range of Unicode characters in
// one general category.
// The value is comprised of a 21-bit character value shifted 5 bits and a 5 bit
// category matching the CharacterCategory enumeration.
// Initial version has 3249 entries and adds about 13K to the executable.
// The array is in ascending order so can be searched using binary search.
// Therefore the average call takes log2(3249) = 12 comparisons.
// For speed, it may be useful to make a linear table for the common values,
// possibly for 0..0xff for most Western European text or 0..0xfff for most
// alphabetic languages.

CharacterCategory CategoriseCharacter(int character) {
	if (character < 0 || character > maxUnicode)
		return ccCn;
	const int baseValue = character * (maskCategory+1) + maskCategory;
	const int *placeAfter = std::lower_bound(catRanges, catRanges+nRanges, baseValue);
	return static_cast<CharacterCategory>(*(placeAfter-1) & maskCategory);
}

// Implementation of character sets recommended for identifiers in Unicode Standard Annex #31.
// http://unicode.org/reports/tr31/

namespace {

enum class OtherID { oidNone, oidStart, oidContinue };

// Some characters are treated as valid for identifiers even
// though most characters from their category are not.
// Values copied from http://www.unicode.org/Public/9.0.0/ucd/PropList.txt
OtherID OtherIDOfCharacter(int character) {
	if (
		(character == 0x1885) ||	// MONGOLIAN LETTER ALI GALI BALUDA
		(character == 0x1886) ||	// MONGOLIAN LETTER ALI GALI THREE BALUDA
		(character == 0x2118) ||	// SCRIPT CAPITAL P
		(character == 0x212E) ||	// ESTIMATED SYMBOL
		(character == 0x309B) ||	// KATAKANA-HIRAGANA VOICED SOUND MARK
		(character == 0x309C)) {	// KATAKANA-HIRAGANA SEMI-VOICED SOUND MARK
		return OtherID::oidStart;
	} else if (
		(character == 0x00B7) ||	// MIDDLE DOT
		(character == 0x0387) ||	// GREEK ANO TELEIA
		((character >= 0x1369) && (character <= 0x1371)) ||	// ETHIOPIC DIGIT ONE..ETHIOPIC DIGIT NINE
		(character == 0x19DA)) {	// NEW TAI LUE THAM DIGIT ONE
		return OtherID::oidContinue;
	} else {
		return OtherID::oidNone;
	}
}

// Determine if a character is in  Ll|Lu|Lt|Lm|Lo|Nl|Mn|Mc|Nd|Pc and has
// Pattern_Syntax|Pattern_White_Space.
// As of Unicode 9, only VERTICAL TILDE which is in Lm and has Pattern_Syntax matches.
// Should really generate from PropList.txt a list of Pattern_Syntax and Pattern_White_Space.
bool IsIdPattern(int character) {
	return character == 0x2E2F;
}

bool OmitXidStart(int character) {
	switch (character) {
	case 0x037A:	// GREEK YPOGEGRAMMENI
	case 0x0E33:	// THAI CHARACTER SARA AM
	case 0x0EB3:	// LAO VOWEL SIGN AM
	case 0x309B:	// KATAKANA-HIRAGANA VOICED SOUND MARK
	case 0x309C:	// KATAKANA-HIRAGANA SEMI-VOICED SOUND MARK
	case 0xFC5E:	// ARABIC LIGATURE SHADDA WITH DAMMATAN ISOLATED FORM
	case 0xFC5F:	// ARABIC LIGATURE SHADDA WITH KASRATAN ISOLATED FORM
	case 0xFC60:	// ARABIC LIGATURE SHADDA WITH FATHA ISOLATED FORM
	case 0xFC61:	// ARABIC LIGATURE SHADDA WITH DAMMA ISOLATED FORM
	case 0xFC62:	// ARABIC LIGATURE SHADDA WITH KASRA ISOLATED FORM
	case 0xFC63:	// ARABIC LIGATURE SHADDA WITH SUPERSCRIPT ALEF ISOLATED FORM
	case 0xFDFA:	// ARABIC LIGATURE SALLALLAHOU ALAYHE WASALLAM
	case 0xFDFB:	// ARABIC LIGATURE JALLAJALALOUHOU
	case 0xFE70:	// ARABIC FATHATAN ISOLATED FORM
	case 0xFE72:	// ARABIC DAMMATAN ISOLATED FORM
	case 0xFE74:	// ARABIC KASRATAN ISOLATED FORM
	case 0xFE76:	// ARABIC FATHA ISOLATED FORM
	case 0xFE78:	// ARABIC DAMMA ISOLATED FORM
	case 0xFE7A:	// ARABIC KASRA ISOLATED FORM
	case 0xFE7C:	// ARABIC SHADDA ISOLATED FORM
	case 0xFE7E:	// ARABIC SUKUN ISOLATED FORM
	case 0xFF9E:	// HALFWIDTH KATAKANA VOICED SOUND MARK
	case 0xFF9F:	// HALFWIDTH KATAKANA SEMI-VOICED SOUND MARK
		return true;
	default:
		return false;
	}
}

bool OmitXidContinue(int character) {
	switch (character) {
	case 0x037A:	// GREEK YPOGEGRAMMENI
	case 0x309B:	// KATAKANA-HIRAGANA VOICED SOUND MARK
	case 0x309C:	// KATAKANA-HIRAGANA SEMI-VOICED SOUND MARK
	case 0xFC5E:	// ARABIC LIGATURE SHADDA WITH DAMMATAN ISOLATED FORM
	case 0xFC5F:	// ARABIC LIGATURE SHADDA WITH KASRATAN ISOLATED FORM
	case 0xFC60:	// ARABIC LIGATURE SHADDA WITH FATHA ISOLATED FORM
	case 0xFC61:	// ARABIC LIGATURE SHADDA WITH DAMMA ISOLATED FORM
	case 0xFC62:	// ARABIC LIGATURE SHADDA WITH KASRA ISOLATED FORM
	case 0xFC63:	// ARABIC LIGATURE SHADDA WITH SUPERSCRIPT ALEF ISOLATED FORM
	case 0xFDFA:	// ARABIC LIGATURE SALLALLAHOU ALAYHE WASALLAM
	case 0xFDFB:	// ARABIC LIGATURE JALLAJALALOUHOU
	case 0xFE70:	// ARABIC FATHATAN ISOLATED FORM
	case 0xFE72:	// ARABIC DAMMATAN ISOLATED FORM
	case 0xFE74:	// ARABIC KASRATAN ISOLATED FORM
	case 0xFE76:	// ARABIC FATHA ISOLATED FORM
	case 0xFE78:	// ARABIC DAMMA ISOLATED FORM
	case 0xFE7A:	// ARABIC KASRA ISOLATED FORM
	case 0xFE7C:	// ARABIC SHADDA ISOLATED FORM
	case 0xFE7E:	// ARABIC SUKUN ISOLATED FORM
		return true;
	default:
		return false;
	}
}

}

// UAX #31 defines ID_Start as
// [[:L:][:Nl:][:Other_ID_Start:]--[:Pattern_Syntax:]--[:Pattern_White_Space:]]
bool IsIdStart(int character) {
	if (IsIdPattern(character)) {
		return false;
	}
	const OtherID oid = OtherIDOfCharacter(character);
	if (oid == OtherID::oidStart) {
		return true;
	}
	const CharacterCategory c = CategoriseCharacter(character);
	return (c == ccLl || c == ccLu || c == ccLt || c == ccLm || c == ccLo
		|| c == ccNl);
}

// UAX #31 defines ID_Continue as
// [[:ID_Start:][:Mn:][:Mc:][:Nd:][:Pc:][:Other_ID_Continue:]--[:Pattern_Syntax:]--[:Pattern_White_Space:]]
bool IsIdContinue(int character) {
	if (IsIdPattern(character)) {
		return false;
	}
	const OtherID oid = OtherIDOfCharacter(character);
	if (oid != OtherID::oidNone) {
		return true;
	}
	const CharacterCategory c = CategoriseCharacter(character);
	return (c == ccLl || c == ccLu || c == ccLt || c == ccLm || c == ccLo
		|| c == ccNl || c == ccMn || c == ccMc || c == ccNd || c == ccPc);
}

// XID_Start is ID_Start modified for Normalization Form KC in UAX #31
bool IsXidStart(int character) {
	if (OmitXidStart(character)) {
		return false;
	} else {
		return IsIdStart(character);
	}
}

// XID_Continue is ID_Continue modified for Normalization Form KC in UAX #31
bool IsXidContinue(int character) {
	if (OmitXidContinue(character)) {
		return false;
	} else {
		return IsIdContinue(character);
	}
}

#ifdef SCI_NAMESPACE
}
#endif
