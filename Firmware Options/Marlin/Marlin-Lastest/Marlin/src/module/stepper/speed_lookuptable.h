/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#if F_CPU == 16000000

  const struct { uint16_t base; uint8_t gain; } speed_lookuptable_fast[256] PROGMEM = {
    {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, // dummy first row
    {   977,   109 }, {   868,    87 }, {   781,    71 }, {   710,    59 }, {   651,    50 }, {   601,    43 }, {   558,    37 }, {   521,    33 },
    {   488,    28 }, {   460,    26 }, {   434,    23 }, {   411,    20 }, {   391,    19 }, {   372,    17 }, {   355,    15 }, {   340,    14 },
    {   326,    13 }, {   313,    13 }, {   300,    11 }, {   289,    10 }, {   279,    10 }, {   269,     9 }, {   260,     8 }, {   252,     8 },
    {   244,     7 }, {   237,     7 }, {   230,     7 }, {   223,     6 }, {   217,     6 }, {   211,     5 }, {   206,     6 }, {   200,     5 },
    {   195,     4 }, {   191,     5 }, {   186,     4 }, {   182,     4 }, {   178,     4 }, {   174,     4 }, {   170,     4 }, {   166,     3 },
    {   163,     4 }, {   159,     3 }, {   156,     3 }, {   153,     3 }, {   150,     3 }, {   147,     2 }, {   145,     3 }, {   142,     2 },
    {   140,     3 }, {   137,     2 }, {   135,     3 }, {   132,     2 }, {   130,     2 }, {   128,     2 }, {   126,     2 }, {   124,     2 },
    {   122,     2 }, {   120,     2 }, {   118,     1 }, {   117,     2 }, {   115,     2 }, {   113,     1 }, {   112,     2 }, {   110,     1 },
    {   109,     2 }, {   107,     1 }, {   106,     2 }, {   104,     1 }, {   103,     2 }, {   101,     1 }, {   100,     1 }, {    99,     1 },
    {    98,     2 }, {    96,     1 }, {    95,     1 }, {    94,     1 }, {    93,     1 }, {    92,     1 }, {    91,     1 }, {    90,     1 },
    {    89,     1 }, {    88,     1 }, {    87,     1 }, {    86,     1 }, {    85,     1 }, {    84,     1 }, {    83,     1 }, {    82,     1 },
    {    81,     0 }, {    81,     1 }, {    80,     1 }, {    79,     1 }, {    78,     1 }, {    77,     0 }, {    77,     1 }, {    76,     1 },
    {    75,     1 }, {    74,     0 }, {    74,     1 }, {    73,     1 }, {    72,     0 }, {    72,     1 }, {    71,     1 }, {    70,     0 },
    {    70,     1 }, {    69,     0 }, {    69,     1 }, {    68,     1 }, {    67,     0 }, {    67,     1 }, {    66,     0 }, {    66,     1 },
    {    65,     0 }, {    65,     1 }, {    64,     0 }, {    64,     1 }, {    63,     0 }, {    63,     1 }, {    62,     0 }, {    62,     1 },
    {    61,     0 }, {    61,     1 }, {    60,     0 }, {    60,     1 }, {    59,     0 }, {    59,     1 }, {    58,     0 }, {    58,     1 },
    {    57,     0 }, {    57,     0 }, {    57,     1 }, {    56,     0 }, {    56,     1 }, {    55,     0 }, {    55,     0 }, {    55,     1 },
    {    54,     0 }, {    54,     0 }, {    54,     1 }, {    53,     0 }, {    53,     1 }, {    52,     0 }, {    52,     0 }, {    52,     1 },
    {    51,     0 }, {    51,     0 }, {    51,     1 }, {    50,     0 }, {    50,     0 }, {    50,     1 }, {    49,     0 }, {    49,     0 },
    {    49,     0 }, {    49,     1 }, {    48,     0 }, {    48,     0 }, {    48,     1 }, {    47,     0 }, {    47,     0 }, {    47,     0 },
    {    47,     1 }, {    46,     0 }, {    46,     0 }, {    46,     1 }, {    45,     0 }, {    45,     0 }, {    45,     0 }, {    45,     1 },
    {    44,     0 }, {    44,     0 }, {    44,     0 }, {    44,     1 }, {    43,     0 }, {    43,     0 }, {    43,     0 }, {    43,     1 },
    {    42,     0 }, {    42,     0 }, {    42,     0 }, {    42,     0 }, {    42,     1 }, {    41,     0 }, {    41,     0 }, {    41,     0 },
    {    41,     1 }, {    40,     0 }, {    40,     0 }, {    40,     0 }, {    40,     0 }, {    40,     1 }, {    39,     0 }, {    39,     0 },
    {    39,     0 }, {    39,     0 }, {    39,     1 }, {    38,     0 }, {    38,     0 }, {    38,     0 }, {    38,     0 }, {    38,     0 },
    {    38,     1 }, {    37,     0 }, {    37,     0 }, {    37,     0 }, {    37,     0 }, {    37,     0 }, {    37,     1 }, {    36,     0 },
    {    36,     0 }, {    36,     0 }, {    36,     0 }, {    36,     0 }, {    36,     1 }, {    35,     0 }, {    35,     0 }, {    35,     0 },
    {    35,     0 }, {    35,     0 }, {    35,     1 }, {    34,     0 }, {    34,     0 }, {    34,     0 }, {    34,     0 }, {    34,     0 },
    {    34,     0 }, {    34,     1 }, {    33,     0 }, {    33,     0 }, {    33,     0 }, {    33,     0 }, {    33,     0 }, {    33,     0 },
    {    33,     1 }, {    32,     0 }, {    32,     0 }, {    32,     0 }, {    32,     0 }, {    32,     0 }, {    32,     0 }, {    32,     0 },
    {    32,     1 }, {    31,     0 }, {    31,     0 }, {    31,     0 }, {    31,     0 }, {    31,     0 }, {    31,     0 }, {    31,     0 },
  };

  const uint16_t speed_lookuptable_slow[256][2] PROGMEM = {
    { 62500, 12500 }, { 50000,  8333 }, { 41667,  5953 }, { 35714,  4464 }, { 31250,  3472 }, { 27778,  2778 }, { 25000,  2273 }, { 22727,  1894 },
    { 20833,  1602 }, { 19231,  1374 }, { 17857,  1190 }, { 16667,  1042 }, { 15625,   919 }, { 14706,   817 }, { 13889,   731 }, { 13158,   658 },
    { 12500,   595 }, { 11905,   541 }, { 11364,   494 }, { 10870,   453 }, { 10417,   417 }, { 10000,   385 }, {  9615,   356 }, {  9259,   330 },
    {  8929,   308 }, {  8621,   288 }, {  8333,   268 }, {  8065,   252 }, {  7813,   237 }, {  7576,   223 }, {  7353,   210 }, {  7143,   199 },
    {  6944,   187 }, {  6757,   178 }, {  6579,   169 }, {  6410,   160 }, {  6250,   152 }, {  6098,   146 }, {  5952,   138 }, {  5814,   132 },
    {  5682,   126 }, {  5556,   121 }, {  5435,   116 }, {  5319,   111 }, {  5208,   106 }, {  5102,   102 }, {  5000,    98 }, {  4902,    94 },
    {  4808,    91 }, {  4717,    87 }, {  4630,    85 }, {  4545,    81 }, {  4464,    78 }, {  4386,    76 }, {  4310,    73 }, {  4237,    70 },
    {  4167,    69 }, {  4098,    66 }, {  4032,    64 }, {  3968,    62 }, {  3906,    60 }, {  3846,    58 }, {  3788,    57 }, {  3731,    55 },
    {  3676,    53 }, {  3623,    52 }, {  3571,    50 }, {  3521,    49 }, {  3472,    47 }, {  3425,    47 }, {  3378,    45 }, {  3333,    44 },
    {  3289,    42 }, {  3247,    42 }, {  3205,    40 }, {  3165,    40 }, {  3125,    39 }, {  3086,    37 }, {  3049,    37 }, {  3012,    36 },
    {  2976,    35 }, {  2941,    34 }, {  2907,    33 }, {  2874,    33 }, {  2841,    32 }, {  2809,    31 }, {  2778,    31 }, {  2747,    30 },
    {  2717,    29 }, {  2688,    28 }, {  2660,    28 }, {  2632,    28 }, {  2604,    27 }, {  2577,    26 }, {  2551,    26 }, {  2525,    25 },
    {  2500,    25 }, {  2475,    24 }, {  2451,    24 }, {  2427,    23 }, {  2404,    23 }, {  2381,    23 }, {  2358,    22 }, {  2336,    21 },
    {  2315,    21 }, {  2294,    21 }, {  2273,    21 }, {  2252,    20 }, {  2232,    20 }, {  2212,    19 }, {  2193,    19 }, {  2174,    19 },
    {  2155,    18 }, {  2137,    18 }, {  2119,    18 }, {  2101,    18 }, {  2083,    17 }, {  2066,    17 }, {  2049,    16 }, {  2033,    17 },
    {  2016,    16 }, {  2000,    16 }, {  1984,    15 }, {  1969,    16 }, {  1953,    15 }, {  1938,    15 }, {  1923,    15 }, {  1908,    14 },
    {  1894,    14 }, {  1880,    14 }, {  1866,    14 }, {  1852,    14 }, {  1838,    13 }, {  1825,    13 }, {  1812,    13 }, {  1799,    13 },
    {  1786,    13 }, {  1773,    12 }, {  1761,    13 }, {  1748,    12 }, {  1736,    12 }, {  1724,    12 }, {  1712,    11 }, {  1701,    12 },
    {  1689,    11 }, {  1678,    11 }, {  1667,    11 }, {  1656,    11 }, {  1645,    11 }, {  1634,    11 }, {  1623,    10 }, {  1613,    10 },
    {  1603,    11 }, {  1592,    10 }, {  1582,    10 }, {  1572,     9 }, {  1563,    10 }, {  1553,    10 }, {  1543,     9 }, {  1534,    10 },
    {  1524,     9 }, {  1515,     9 }, {  1506,     9 }, {  1497,     9 }, {  1488,     9 }, {  1479,     8 }, {  1471,     9 }, {  1462,     9 },
    {  1453,     8 }, {  1445,     8 }, {  1437,     8 }, {  1429,     9 }, {  1420,     8 }, {  1412,     8 }, {  1404,     7 }, {  1397,     8 },
    {  1389,     8 }, {  1381,     7 }, {  1374,     8 }, {  1366,     7 }, {  1359,     8 }, {  1351,     7 }, {  1344,     7 }, {  1337,     7 },
    {  1330,     7 }, {  1323,     7 }, {  1316,     7 }, {  1309,     7 }, {  1302,     7 }, {  1295,     6 }, {  1289,     7 }, {  1282,     6 },
    {  1276,     7 }, {  1269,     6 }, {  1263,     7 }, {  1256,     6 }, {  1250,     6 }, {  1244,     6 }, {  1238,     6 }, {  1232,     7 },
    {  1225,     5 }, {  1220,     6 }, {  1214,     6 }, {  1208,     6 }, {  1202,     6 }, {  1196,     6 }, {  1190,     5 }, {  1185,     6 },
    {  1179,     5 }, {  1174,     6 }, {  1168,     5 }, {  1163,     6 }, {  1157,     5 }, {  1152,     5 }, {  1147,     5 }, {  1142,     6 },
    {  1136,     5 }, {  1131,     5 }, {  1126,     5 }, {  1121,     5 }, {  1116,     5 }, {  1111,     5 }, {  1106,     5 }, {  1101,     5 },
    {  1096,     4 }, {  1092,     5 }, {  1087,     5 }, {  1082,     4 }, {  1078,     5 }, {  1073,     5 }, {  1068,     4 }, {  1064,     5 },
    {  1059,     4 }, {  1055,     5 }, {  1050,     4 }, {  1046,     4 }, {  1042,     5 }, {  1037,     4 }, {  1033,     4 }, {  1029,     4 },
    {  1025,     5 }, {  1020,     4 }, {  1016,     4 }, {  1012,     4 }, {  1008,     4 }, {  1004,     4 }, {  1000,     4 }, {   996,     4 },
    {   992,     4 }, {   988,     4 }, {   984,     4 }, {   980,     3 }, {   977,     4 }, {   973,     4 }, {   969,     4 }, {   965,     4 },
  };

#elif F_CPU == 20000000

  const struct { uint16_t base; uint8_t gain; } speed_lookuptable_fast[256] PROGMEM = {
    {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, {     0,     0 }, // dummy first row
    {  1221,   136 }, {  1085,   108 }, {   977,    89 }, {   888,    74 }, {   814,    63 }, {   751,    53 }, {   698,    47 }, {   651,    41 },
    {   610,    36 }, {   574,    31 }, {   543,    29 }, {   514,    26 }, {   488,    23 }, {   465,    21 }, {   444,    19 }, {   425,    18 },
    {   407,    16 }, {   391,    15 }, {   376,    14 }, {   362,    13 }, {   349,    12 }, {   337,    11 }, {   326,    11 }, {   315,    10 },
    {   305,     9 }, {   296,     9 }, {   287,     8 }, {   279,     8 }, {   271,     7 }, {   264,     7 }, {   257,     7 }, {   250,     6 },
    {   244,     6 }, {   238,     5 }, {   233,     6 }, {   227,     5 }, {   222,     5 }, {   217,     5 }, {   212,     4 }, {   208,     5 },
    {   203,     4 }, {   199,     4 }, {   195,     4 }, {   191,     3 }, {   188,     4 }, {   184,     3 }, {   181,     3 }, {   178,     4 },
    {   174,     3 }, {   171,     3 }, {   168,     2 }, {   166,     3 }, {   163,     3 }, {   160,     2 }, {   158,     3 }, {   155,     2 },
    {   153,     3 }, {   150,     2 }, {   148,     2 }, {   146,     2 }, {   144,     2 }, {   142,     2 }, {   140,     2 }, {   138,     2 },
    {   136,     2 }, {   134,     2 }, {   132,     2 }, {   130,     2 }, {   128,     1 }, {   127,     2 }, {   125,     1 }, {   124,     2 },
    {   122,     1 }, {   121,     2 }, {   119,     1 }, {   118,     2 }, {   116,     1 }, {   115,     1 }, {   114,     2 }, {   112,     1 },
    {   111,     1 }, {   110,     1 }, {   109,     2 }, {   107,     1 }, {   106,     1 }, {   105,     1 }, {   104,     1 }, {   103,     1 },
    {   102,     1 }, {   101,     1 }, {   100,     1 }, {    99,     1 }, {    98,     1 }, {    97,     1 }, {    96,     1 }, {    95,     1 },
    {    94,     1 }, {    93,     1 }, {    92,     1 }, {    91,     1 }, {    90,     0 }, {    90,     1 }, {    89,     1 }, {    88,     1 },
    {    87,     1 }, {    86,     0 }, {    86,     1 }, {    85,     1 }, {    84,     1 }, {    83,     0 }, {    83,     1 }, {    82,     1 },
    {    81,     0 }, {    81,     1 }, {    80,     1 }, {    79,     0 }, {    79,     1 }, {    78,     0 }, {    78,     1 }, {    77,     1 },
    {    76,     0 }, {    76,     1 }, {    75,     0 }, {    75,     1 }, {    74,     1 }, {    73,     0 }, {    73,     1 }, {    72,     0 },
    {    72,     1 }, {    71,     0 }, {    71,     1 }, {    70,     0 }, {    70,     1 }, {    69,     0 }, {    69,     1 }, {    68,     0 },
    {    68,     1 }, {    67,     0 }, {    67,     1 }, {    66,     0 }, {    66,     0 }, {    66,     1 }, {    65,     0 }, {    65,     1 },
    {    64,     0 }, {    64,     1 }, {    63,     0 }, {    63,     0 }, {    63,     1 }, {    62,     0 }, {    62,     1 }, {    61,     0 },
    {    61,     0 }, {    61,     1 }, {    60,     0 }, {    60,     0 }, {    60,     1 }, {    59,     0 }, {    59,     1 }, {    58,     0 },
    {    58,     0 }, {    58,     1 }, {    57,     0 }, {    57,     0 }, {    57,     1 }, {    56,     0 }, {    56,     0 }, {    56,     1 },
    {    55,     0 }, {    55,     0 }, {    55,     0 }, {    55,     1 }, {    54,     0 }, {    54,     0 }, {    54,     1 }, {    53,     0 },
    {    53,     0 }, {    53,     0 }, {    53,     1 }, {    52,     0 }, {    52,     0 }, {    52,     1 }, {    51,     0 }, {    51,     0 },
    {    51,     0 }, {    51,     1 }, {    50,     0 }, {    50,     0 }, {    50,     0 }, {    50,     1 }, {    49,     0 }, {    49,     0 },
    {    49,     0 }, {    49,     1 }, {    48,     0 }, {    48,     0 }, {    48,     0 }, {    48,     1 }, {    47,     0 }, {    47,     0 },
    {    47,     0 }, {    47,     0 }, {    47,     1 }, {    46,     0 }, {    46,     0 }, {    46,     0 }, {    46,     1 }, {    45,     0 },
    {    45,     0 }, {    45,     0 }, {    45,     0 }, {    45,     1 }, {    44,     0 }, {    44,     0 }, {    44,     0 }, {    44,     0 },
    {    44,     1 }, {    43,     0 }, {    43,     0 }, {    43,     0 }, {    43,     0 }, {    43,     1 }, {    42,     0 }, {    42,     0 },
    {    42,     0 }, {    42,     0 }, {    42,     0 }, {    42,     1 }, {    41,     0 }, {    41,     0 }, {    41,     0 }, {    41,     0 },
    {    41,     0 }, {    41,     1 }, {    40,     0 }, {    40,     0 }, {    40,     0 }, {    40,     0 }, {    40,     0 }, {    40,     1 },
    {    39,     0 }, {    39,     0 }, {    39,     0 }, {    39,     0 }, {    39,     0 }, {    39,     1 }, {    38,     0 }, {    38,     0 },
  };

  const uint16_t speed_lookuptable_slow[256][2] PROGMEM = {
    { 62500, 10417 }, { 52083,  7440 }, { 44643,  5580 }, { 39063,  4341 }, { 34722,  3472 }, { 31250,  2841 }, { 28409,  2367 }, { 26042,  2004 },
    { 24038,  1717 }, { 22321,  1488 }, { 20833,  1302 }, { 19531,  1149 }, { 18382,  1021 }, { 17361,   914 }, { 16447,   822 }, { 15625,   744 },
    { 14881,   676 }, { 14205,   618 }, { 13587,   566 }, { 13021,   521 }, { 12500,   481 }, { 12019,   445 }, { 11574,   413 }, { 11161,   385 },
    { 10776,   359 }, { 10417,   336 }, { 10081,   315 }, {  9766,   296 }, {  9470,   279 }, {  9191,   262 }, {  8929,   248 }, {  8681,   235 },
    {  8446,   222 }, {  8224,   211 }, {  8013,   200 }, {  7813,   191 }, {  7622,   182 }, {  7440,   173 }, {  7267,   165 }, {  7102,   158 },
    {  6944,   151 }, {  6793,   144 }, {  6649,   139 }, {  6510,   132 }, {  6378,   128 }, {  6250,   123 }, {  6127,   117 }, {  6010,   114 },
    {  5896,   109 }, {  5787,   105 }, {  5682,   102 }, {  5580,    98 }, {  5482,    94 }, {  5388,    91 }, {  5297,    89 }, {  5208,    85 },
    {  5123,    83 }, {  5040,    80 }, {  4960,    77 }, {  4883,    75 }, {  4808,    73 }, {  4735,    71 }, {  4664,    68 }, {  4596,    67 },
    {  4529,    65 }, {  4464,    63 }, {  4401,    61 }, {  4340,    59 }, {  4281,    58 }, {  4223,    56 }, {  4167,    55 }, {  4112,    54 },
    {  4058,    52 }, {  4006,    50 }, {  3956,    50 }, {  3906,    48 }, {  3858,    47 }, {  3811,    46 }, {  3765,    45 }, {  3720,    44 },
    {  3676,    42 }, {  3634,    42 }, {  3592,    41 }, {  3551,    40 }, {  3511,    39 }, {  3472,    38 }, {  3434,    37 }, {  3397,    37 },
    {  3360,    36 }, {  3324,    35 }, {  3289,    34 }, {  3255,    33 }, {  3222,    33 }, {  3189,    32 }, {  3157,    32 }, {  3125,    31 },
    {  3094,    30 }, {  3064,    30 }, {  3034,    29 }, {  3005,    29 }, {  2976,    28 }, {  2948,    27 }, {  2921,    27 }, {  2894,    27 },
    {  2867,    26 }, {  2841,    26 }, {  2815,    25 }, {  2790,    25 }, {  2765,    24 }, {  2741,    24 }, {  2717,    23 }, {  2694,    23 },
    {  2671,    23 }, {  2648,    22 }, {  2626,    22 }, {  2604,    21 }, {  2583,    22 }, {  2561,    20 }, {  2541,    21 }, {  2520,    20 },
    {  2500,    20 }, {  2480,    19 }, {  2461,    20 }, {  2441,    19 }, {  2422,    18 }, {  2404,    19 }, {  2385,    18 }, {  2367,    17 },
    {  2350,    18 }, {  2332,    17 }, {  2315,    17 }, {  2298,    17 }, {  2281,    17 }, {  2264,    16 }, {  2248,    16 }, {  2232,    16 },
    {  2216,    15 }, {  2201,    16 }, {  2185,    15 }, {  2170,    15 }, {  2155,    15 }, {  2140,    14 }, {  2126,    15 }, {  2111,    14 },
    {  2097,    14 }, {  2083,    13 }, {  2070,    14 }, {  2056,    14 }, {  2042,    13 }, {  2029,    13 }, {  2016,    13 }, {  2003,    13 },
    {  1990,    12 }, {  1978,    13 }, {  1965,    12 }, {  1953,    12 }, {  1941,    12 }, {  1929,    12 }, {  1917,    12 }, {  1905,    11 },
    {  1894,    11 }, {  1883,    12 }, {  1871,    11 }, {  1860,    11 }, {  1849,    11 }, {  1838,    11 }, {  1827,    10 }, {  1817,    11 },
    {  1806,    10 }, {  1796,    10 }, {  1786,    10 }, {  1776,    10 }, {  1766,    10 }, {  1756,    10 }, {  1746,    10 }, {  1736,     9 },
    {  1727,    10 }, {  1717,     9 }, {  1708,    10 }, {  1698,     9 }, {  1689,     9 }, {  1680,     9 }, {  1671,     9 }, {  1662,     9 },
    {  1653,     8 }, {  1645,     9 }, {  1636,     8 }, {  1628,     9 }, {  1619,     8 }, {  1611,     8 }, {  1603,     9 }, {  1594,     8 },
    {  1586,     8 }, {  1578,     8 }, {  1570,     7 }, {  1563,     8 }, {  1555,     8 }, {  1547,     8 }, {  1539,     7 }, {  1532,     8 },
    {  1524,     7 }, {  1517,     7 }, {  1510,     8 }, {  1502,     7 }, {  1495,     7 }, {  1488,     7 }, {  1481,     7 }, {  1474,     7 },
    {  1467,     7 }, {  1460,     7 }, {  1453,     6 }, {  1447,     7 }, {  1440,     7 }, {  1433,     6 }, {  1427,     7 }, {  1420,     6 },
    {  1414,     6 }, {  1408,     7 }, {  1401,     6 }, {  1395,     6 }, {  1389,     6 }, {  1383,     6 }, {  1377,     6 }, {  1371,     6 },
    {  1365,     6 }, {  1359,     6 }, {  1353,     6 }, {  1347,     6 }, {  1341,     6 }, {  1335,     5 }, {  1330,     6 }, {  1324,     5 },
    {  1319,     6 }, {  1313,     5 }, {  1308,     6 }, {  1302,     5 }, {  1297,     6 }, {  1291,     5 }, {  1286,     5 }, {  1281,     5 },
    {  1276,     6 }, {  1270,     5 }, {  1265,     5 }, {  1260,     5 }, {  1255,     5 }, {  1250,     5 }, {  1245,     5 }, {  1240,     5 },
    {  1235,     5 }, {  1230,     5 }, {  1225,     4 }, {  1221,     5 }, {  1216,     5 }, {  1211,     4 }, {  1207,     5 }, {  1202,     5 },
  };

#endif