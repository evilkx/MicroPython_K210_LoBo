
/*

 The Hershey Fonts:
  -  each point is described in eight bytes as "xxx yyy:", where xxx and yyy are
     the coordinate values as ASCII numbers.
  - are a set of more than 2000 glyph (symbol) descriptions in vector
    ( <x,y>; point-to-point ) format
  - can be grouped as almost 20 'occidental' (english, greek,
    cyrillic) fonts, 3 or more 'oriental' (Kanji, Hiragana,
    and Katakana) fonts, and a few hundred miscellaneous
    symbols (mathematical, musical, cartographic, etc etc)
  - are suitable for typographic quality output on a vector device
    (such as a plotter) when used at an appropriate scale.


The structure is basically as follows: each character consists of a number 1->4000 (not all used) in column 0:4,
the number of vertices in columns 5:7, the left hand position in column 8, the right hand position in column 9,
and finally the vertices in single character pairs.
All coordinates are given relative to the ASCII value of 'R'.
If the coordinate value is " " that indicates a pen up operation.

As an example consider the 8th symbol

    MWOMOV UMUV OQUQ

The left position is 'M' - 'R' = -5
The right position is 'W' - 'R' = 5
The first coordinate is "OM" = (-3,-5)
The second coordinate is "OV" = (-3,4)
Raise the pen " " (new vector)
Move to "UM" = (3,-5)
Draw to "UV" = (3,4)
Raise the pen " " (new vector)
Move to "OQ" = (-3,-1)
Draw to "UQ" = (3,-1)
Drawing this out on a piece of paper will reveal it represents an 'H'.

*/

#include "mpconfigport.h"

#if MICROPY_USE_DISPLAY

const unsigned char futural[] = {
    0x48, 0x45, 0x52, 0x53,
    106, 0,
    71, 93, 65, 98,  // 23x34
    // ' ', 32, (3x3)
    32, 0, 0, 0, 0x51, 0x53, 0x51, 0x53,

    // '!', 33, (3x22)
    33, 0, 16, 0, 0x51, 0x53, 0x46, 0x5b,
    0x52,0x46,0x52,0x54,0x20,0x52,0x52,0x59,0x51,0x5a,0x52,0x5b,0x53,0x5a,0x52,0x59,
    // '"', 34, (9x14)
    34, 0, 10, 0, 0x4e, 0x56, 0x46, 0x53,
    0x4e,0x46,0x4e,0x4d,0x20,0x52,0x56,0x46,0x56,0x4d,
    // '#', 35, (16x33)
    35, 0, 22, 0, 0x4b, 0x5a, 0x42, 0x62,
    0x53,0x42,0x4c,0x62,0x20,0x52,0x59,0x42,0x52,0x62,0x20,0x52,0x4c,0x4f,0x5a,0x4f,0x20,0x52,0x4b,0x55,0x59,0x55,
    // '$', 36, (15x30)
    36, 0, 52, 0, 0x4b, 0x59, 0x42, 0x5f,
    0x50,0x42,0x50,0x5f,0x20,0x52,0x54,0x42,0x54,0x5f,0x20,0x52,0x59,0x49,0x57,0x47,0x54,0x46,0x50,0x46,0x4d,0x47,0x4b,0x49,0x4b,0x4b,0x4c,0x4d,0x4d,0x4e,0x4f,0x4f,0x55,0x51,0x57,0x52,0x58,0x53,0x59,0x55,0x59,0x58,0x57,0x5a,0x54,0x5b,0x50,0x5b,0x4d,0x5a,0x4b,0x58,
    // '%', 37, (19x22)
    37, 0, 62, 0, 0x49, 0x5b, 0x46, 0x5b,
    0x5b,0x46,0x49,0x5b,0x20,0x52,0x4e,0x46,0x50,0x48,0x50,0x4a,0x4f,0x4c,0x4d,0x4d,0x4b,0x4d,0x49,0x4b,0x49,0x49,0x4a,0x47,0x4c,0x46,0x4e,0x46,0x50,0x47,0x53,0x48,0x56,0x48,0x59,0x47,0x5b,0x46,0x20,0x52,0x57,0x54,0x55,0x55,0x54,0x57,0x54,0x59,0x56,0x5b,0x58,0x5b,0x5a,0x5a,0x5b,0x58,0x5b,0x56,0x59,0x54,0x57,0x54,
    // '&', 38, (21x22)
    38, 0, 68, 0, 0x48, 0x5c, 0x46, 0x5b,
    0x5c,0x4f,0x5c,0x4e,0x5b,0x4d,0x5a,0x4d,0x59,0x4e,0x58,0x50,0x56,0x55,0x54,0x58,0x52,0x5a,0x50,0x5b,0x4c,0x5b,0x4a,0x5a,0x49,0x59,0x48,0x57,0x48,0x55,0x49,0x53,0x4a,0x52,0x51,0x4e,0x52,0x4d,0x53,0x4b,0x53,0x49,0x52,0x47,0x50,0x46,0x4e,0x47,0x4d,0x49,0x4d,0x4b,0x4e,0x4e,0x50,0x51,0x55,0x58,0x57,0x5a,0x59,0x5b,0x5b,0x5b,0x5c,0x5a,0x5c,0x59,
    // ''', 39, (3x14)
    39, 0, 14, 0, 0x51, 0x53, 0x46, 0x53,
    0x52,0x48,0x51,0x47,0x52,0x46,0x53,0x47,0x53,0x49,0x52,0x4b,0x51,0x4c,
    // '(', 40, (8x33)
    40, 0, 20, 0, 0x4f, 0x56, 0x42, 0x62,
    0x56,0x42,0x54,0x44,0x52,0x47,0x50,0x4b,0x4f,0x50,0x4f,0x54,0x50,0x59,0x52,0x5d,0x54,0x60,0x56,0x62,
    // ')', 41, (8x33)
    41, 0, 20, 0, 0x4e, 0x55, 0x42, 0x62,
    0x4e,0x42,0x50,0x44,0x52,0x47,0x54,0x4b,0x55,0x50,0x55,0x54,0x54,0x59,0x52,0x5d,0x50,0x60,0x4e,0x62,
    // '*', 42, (11x13)
    42, 0, 16, 0, 0x4d, 0x57, 0x4c, 0x58,
    0x52,0x4c,0x52,0x58,0x20,0x52,0x4d,0x4f,0x57,0x55,0x20,0x52,0x57,0x4f,0x4d,0x55,
    // '+', 43, (19x19)
    43, 0, 10, 0, 0x49, 0x5b, 0x49, 0x5b,
    0x52,0x49,0x52,0x5b,0x20,0x52,0x49,0x52,0x5b,0x52,
    // ',', 44, (3x11)
    44, 0, 14, 0, 0x51, 0x53, 0x51, 0x5b,
    0x53,0x57,0x52,0x58,0x51,0x57,0x52,0x56,0x53,0x57,0x53,0x59,0x51,0x5b,
    // '-', 45, (19x3)
    45, 0, 4, 0, 0x49, 0x5b, 0x51, 0x53,
    0x49,0x52,0x5b,0x52,
    // '.', 46, (3x8)
    46, 0, 10, 0, 0x51, 0x53, 0x51, 0x58,
    0x52,0x56,0x51,0x57,0x52,0x58,0x53,0x57,0x52,0x56,
    // '/', 47, (19x33)
    47, 0, 4, 0, 0x49, 0x5b, 0x42, 0x62,
    0x5b,0x42,0x49,0x62,
    // '0', 48, (15x22)
    48, 0, 34, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x51,0x46,0x4e,0x47,0x4c,0x4a,0x4b,0x4f,0x4b,0x52,0x4c,0x57,0x4e,0x5a,0x51,0x5b,0x53,0x5b,0x56,0x5a,0x58,0x57,0x59,0x52,0x59,0x4f,0x58,0x4a,0x56,0x47,0x53,0x46,0x51,0x46,
    // '1', 49, (6x22)
    49, 0, 8, 0, 0x4e, 0x53, 0x46, 0x5b,
    0x4e,0x4a,0x50,0x49,0x53,0x46,0x53,0x5b,
    // '2', 50, (15x22)
    50, 0, 28, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4c,0x4b,0x4c,0x4a,0x4d,0x48,0x4e,0x47,0x50,0x46,0x54,0x46,0x56,0x47,0x57,0x48,0x58,0x4a,0x58,0x4c,0x57,0x4e,0x55,0x51,0x4b,0x5b,0x59,0x5b,
    // '3', 51, (15x22)
    51, 0, 30, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4d,0x46,0x58,0x46,0x52,0x4e,0x55,0x4e,0x57,0x4f,0x58,0x50,0x59,0x53,0x59,0x55,0x58,0x58,0x56,0x5a,0x53,0x5b,0x50,0x5b,0x4d,0x5a,0x4c,0x59,0x4b,0x57,
    // '4', 52, (16x22)
    52, 0, 12, 0, 0x4b, 0x5a, 0x46, 0x5b,
    0x55,0x46,0x4b,0x54,0x5a,0x54,0x20,0x52,0x55,0x46,0x55,0x5b,
    // '5', 53, (15x22)
    53, 0, 34, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x57,0x46,0x4d,0x46,0x4c,0x4f,0x4d,0x4e,0x50,0x4d,0x53,0x4d,0x56,0x4e,0x58,0x50,0x59,0x53,0x59,0x55,0x58,0x58,0x56,0x5a,0x53,0x5b,0x50,0x5b,0x4d,0x5a,0x4c,0x59,0x4b,0x57,
    // '6', 54, (14x22)
    54, 0, 46, 0, 0x4c, 0x59, 0x46, 0x5b,
    0x58,0x49,0x57,0x47,0x54,0x46,0x52,0x46,0x4f,0x47,0x4d,0x4a,0x4c,0x4f,0x4c,0x54,0x4d,0x58,0x4f,0x5a,0x52,0x5b,0x53,0x5b,0x56,0x5a,0x58,0x58,0x59,0x55,0x59,0x54,0x58,0x51,0x56,0x4f,0x53,0x4e,0x52,0x4e,0x4f,0x4f,0x4d,0x51,0x4c,0x54,
    // '7', 55, (15x22)
    55, 0, 10, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x59,0x46,0x4f,0x5b,0x20,0x52,0x4b,0x46,0x59,0x46,
    // '8', 56, (15x22)
    56, 0, 58, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x50,0x46,0x4d,0x47,0x4c,0x49,0x4c,0x4b,0x4d,0x4d,0x4f,0x4e,0x53,0x4f,0x56,0x50,0x58,0x52,0x59,0x54,0x59,0x57,0x58,0x59,0x57,0x5a,0x54,0x5b,0x50,0x5b,0x4d,0x5a,0x4c,0x59,0x4b,0x57,0x4b,0x54,0x4c,0x52,0x4e,0x50,0x51,0x4f,0x55,0x4e,0x57,0x4d,0x58,0x4b,0x58,0x49,0x57,0x47,0x54,0x46,0x50,0x46,
    // '9', 57, (14x22)
    57, 0, 46, 0, 0x4b, 0x58, 0x46, 0x5b,
    0x58,0x4d,0x57,0x50,0x55,0x52,0x52,0x53,0x51,0x53,0x4e,0x52,0x4c,0x50,0x4b,0x4d,0x4b,0x4c,0x4c,0x49,0x4e,0x47,0x51,0x46,0x52,0x46,0x55,0x47,0x57,0x49,0x58,0x4d,0x58,0x52,0x57,0x57,0x55,0x5a,0x52,0x5b,0x50,0x5b,0x4d,0x5a,0x4c,0x58,
    // ':', 58, (3x10)
    58, 0, 22, 0, 0x51, 0x53, 0x4f, 0x58,
    0x52,0x4f,0x51,0x50,0x52,0x51,0x53,0x50,0x52,0x4f,0x20,0x52,0x52,0x56,0x51,0x57,0x52,0x58,0x53,0x57,0x52,0x56,
    // ';', 59, (3x13)
    59, 0, 26, 0, 0x51, 0x53, 0x4f, 0x5b,
    0x52,0x4f,0x51,0x50,0x52,0x51,0x53,0x50,0x52,0x4f,0x20,0x52,0x53,0x57,0x52,0x58,0x51,0x57,0x52,0x56,0x53,0x57,0x53,0x59,0x51,0x5b,
    // '<', 60, (17x19)
    60, 0, 6, 0, 0x4a, 0x5a, 0x49, 0x5b,
    0x5a,0x49,0x4a,0x52,0x5a,0x5b,
    // '=', 61, (19x7)
    61, 0, 10, 0, 0x49, 0x5b, 0x4f, 0x55,
    0x49,0x4f,0x5b,0x4f,0x20,0x52,0x49,0x55,0x5b,0x55,
    // '>', 62, (17x19)
    62, 0, 6, 0, 0x4a, 0x5a, 0x49, 0x5b,
    0x4a,0x49,0x5a,0x52,0x4a,0x5b,
    // '?', 63, (13x22)
    63, 0, 40, 0, 0x4c, 0x58, 0x46, 0x5b,
    0x4c,0x4b,0x4c,0x4a,0x4d,0x48,0x4e,0x47,0x50,0x46,0x54,0x46,0x56,0x47,0x57,0x48,0x58,0x4a,0x58,0x4c,0x57,0x4e,0x56,0x4f,0x52,0x51,0x52,0x54,0x20,0x52,0x52,0x59,0x51,0x5a,0x52,0x5b,0x53,0x5a,0x52,0x59,
    // '@', 64, (22x22)
    64, 0, 110, 0, 0x48, 0x5d, 0x46, 0x5b,
    0x57,0x4e,0x56,0x4c,0x54,0x4b,0x51,0x4b,0x4f,0x4c,0x4e,0x4d,0x4d,0x50,0x4d,0x53,0x4e,0x55,0x50,0x56,0x53,0x56,0x55,0x55,0x56,0x53,0x20,0x52,0x51,0x4b,0x4f,0x4d,0x4e,0x50,0x4e,0x53,0x4f,0x55,0x50,0x56,0x20,0x52,0x57,0x4b,0x56,0x53,0x56,0x55,0x58,0x56,0x5a,0x56,0x5c,0x54,0x5d,0x51,0x5d,0x4f,0x5c,0x4c,0x5b,0x4a,0x59,0x48,0x57,0x47,0x54,0x46,0x51,0x46,0x4e,0x47,0x4c,0x48,0x4a,0x4a,0x49,0x4c,0x48,0x4f,0x48,0x52,0x49,0x55,0x4a,0x57,0x4c,0x59,0x4e,0x5a,0x51,0x5b,0x54,0x5b,0x57,0x5a,0x59,0x59,0x5a,0x58,0x20,0x52,0x58,0x4b,0x57,0x53,0x57,0x55,0x58,0x56,
    // 'A', 65, (17x22)
    65, 0, 16, 0, 0x4a, 0x5a, 0x46, 0x5b,
    0x52,0x46,0x4a,0x5b,0x20,0x52,0x52,0x46,0x5a,0x5b,0x20,0x52,0x4d,0x54,0x57,0x54,
    // 'B', 66, (15x22)
    66, 0, 46, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x5b,0x20,0x52,0x4b,0x46,0x54,0x46,0x57,0x47,0x58,0x48,0x59,0x4a,0x59,0x4c,0x58,0x4e,0x57,0x4f,0x54,0x50,0x20,0x52,0x4b,0x50,0x54,0x50,0x57,0x51,0x58,0x52,0x59,0x54,0x59,0x57,0x58,0x59,0x57,0x5a,0x54,0x5b,0x4b,0x5b,
    // 'C', 67, (16x22)
    67, 0, 36, 0, 0x4b, 0x5a, 0x46, 0x5b,
    0x5a,0x4b,0x59,0x49,0x57,0x47,0x55,0x46,0x51,0x46,0x4f,0x47,0x4d,0x49,0x4c,0x4b,0x4b,0x4e,0x4b,0x53,0x4c,0x56,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x55,0x5b,0x57,0x5a,0x59,0x58,0x5a,0x56,
    // 'D', 68, (15x22)
    68, 0, 30, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x5b,0x20,0x52,0x4b,0x46,0x52,0x46,0x55,0x47,0x57,0x49,0x58,0x4b,0x59,0x4e,0x59,0x53,0x58,0x56,0x57,0x58,0x55,0x5a,0x52,0x5b,0x4b,0x5b,
    // 'E', 69, (14x22)
    69, 0, 22, 0, 0x4c, 0x59, 0x46, 0x5b,
    0x4c,0x46,0x4c,0x5b,0x20,0x52,0x4c,0x46,0x59,0x46,0x20,0x52,0x4c,0x50,0x54,0x50,0x20,0x52,0x4c,0x5b,0x59,0x5b,
    // 'F', 70, (14x22)
    70, 0, 16, 0, 0x4c, 0x59, 0x46, 0x5b,
    0x4c,0x46,0x4c,0x5b,0x20,0x52,0x4c,0x46,0x59,0x46,0x20,0x52,0x4c,0x50,0x54,0x50,
    // 'G', 71, (16x22)
    71, 0, 44, 0, 0x4b, 0x5a, 0x46, 0x5b,
    0x5a,0x4b,0x59,0x49,0x57,0x47,0x55,0x46,0x51,0x46,0x4f,0x47,0x4d,0x49,0x4c,0x4b,0x4b,0x4e,0x4b,0x53,0x4c,0x56,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x55,0x5b,0x57,0x5a,0x59,0x58,0x5a,0x56,0x5a,0x53,0x20,0x52,0x55,0x53,0x5a,0x53,
    // 'H', 72, (15x22)
    72, 0, 16, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x5b,0x20,0x52,0x59,0x46,0x59,0x5b,0x20,0x52,0x4b,0x50,0x59,0x50,
    // 'I', 73, (3x22)
    73, 0, 4, 0, 0x51, 0x53, 0x46, 0x5b,
    0x52,0x46,0x52,0x5b,
    // 'J', 74, (11x22)
    74, 0, 20, 0, 0x4c, 0x56, 0x46, 0x5b,
    0x56,0x46,0x56,0x56,0x55,0x59,0x54,0x5a,0x52,0x5b,0x50,0x5b,0x4e,0x5a,0x4d,0x59,0x4c,0x56,0x4c,0x54,
    // 'K', 75, (15x22)
    75, 0, 16, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x5b,0x20,0x52,0x59,0x46,0x4b,0x54,0x20,0x52,0x50,0x4f,0x59,0x5b,
    // 'L', 76, (13x22)
    76, 0, 10, 0, 0x4c, 0x58, 0x46, 0x5b,
    0x4c,0x46,0x4c,0x5b,0x20,0x52,0x4c,0x5b,0x58,0x5b,
    // 'M', 77, (17x22)
    77, 0, 22, 0, 0x4a, 0x5a, 0x46, 0x5b,
    0x4a,0x46,0x4a,0x5b,0x20,0x52,0x4a,0x46,0x52,0x5b,0x20,0x52,0x5a,0x46,0x52,0x5b,0x20,0x52,0x5a,0x46,0x5a,0x5b,
    // 'N', 78, (15x22)
    78, 0, 16, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x5b,0x20,0x52,0x4b,0x46,0x59,0x5b,0x20,0x52,0x59,0x46,0x59,0x5b,
    // 'O', 79, (17x22)
    79, 0, 42, 0, 0x4a, 0x5a, 0x46, 0x5b,
    0x50,0x46,0x4e,0x47,0x4c,0x49,0x4b,0x4b,0x4a,0x4e,0x4a,0x53,0x4b,0x56,0x4c,0x58,0x4e,0x5a,0x50,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,0x59,0x56,0x5a,0x53,0x5a,0x4e,0x59,0x4b,0x58,0x49,0x56,0x47,0x54,0x46,0x50,0x46,
    // 'P', 80, (15x22)
    80, 0, 26, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x5b,0x20,0x52,0x4b,0x46,0x54,0x46,0x57,0x47,0x58,0x48,0x59,0x4a,0x59,0x4d,0x58,0x4f,0x57,0x50,0x54,0x51,0x4b,0x51,
    // 'Q', 81, (17x24)
    81, 0, 48, 0, 0x4a, 0x5a, 0x46, 0x5d,
    0x50,0x46,0x4e,0x47,0x4c,0x49,0x4b,0x4b,0x4a,0x4e,0x4a,0x53,0x4b,0x56,0x4c,0x58,0x4e,0x5a,0x50,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,0x59,0x56,0x5a,0x53,0x5a,0x4e,0x59,0x4b,0x58,0x49,0x56,0x47,0x54,0x46,0x50,0x46,0x20,0x52,0x53,0x57,0x59,0x5d,
    // 'R', 82, (15x22)
    82, 0, 32, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x5b,0x20,0x52,0x4b,0x46,0x54,0x46,0x57,0x47,0x58,0x48,0x59,0x4a,0x59,0x4c,0x58,0x4e,0x57,0x4f,0x54,0x50,0x4b,0x50,0x20,0x52,0x52,0x50,0x59,0x5b,
    // 'S', 83, (15x22)
    83, 0, 40, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x59,0x49,0x57,0x47,0x54,0x46,0x50,0x46,0x4d,0x47,0x4b,0x49,0x4b,0x4b,0x4c,0x4d,0x4d,0x4e,0x4f,0x4f,0x55,0x51,0x57,0x52,0x58,0x53,0x59,0x55,0x59,0x58,0x57,0x5a,0x54,0x5b,0x50,0x5b,0x4d,0x5a,0x4b,0x58,
    // 'T', 84, (15x22)
    84, 0, 10, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x52,0x46,0x52,0x5b,0x20,0x52,0x4b,0x46,0x59,0x46,
    // 'U', 85, (15x22)
    85, 0, 20, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x55,0x4c,0x58,0x4e,0x5a,0x51,0x5b,0x53,0x5b,0x56,0x5a,0x58,0x58,0x59,0x55,0x59,0x46,
    // 'V', 86, (17x22)
    86, 0, 10, 0, 0x4a, 0x5a, 0x46, 0x5b,
    0x4a,0x46,0x52,0x5b,0x20,0x52,0x5a,0x46,0x52,0x5b,
    // 'W', 87, (21x22)
    87, 0, 22, 0, 0x48, 0x5c, 0x46, 0x5b,
    0x48,0x46,0x4d,0x5b,0x20,0x52,0x52,0x46,0x4d,0x5b,0x20,0x52,0x52,0x46,0x57,0x5b,0x20,0x52,0x5c,0x46,0x57,0x5b,
    // 'X', 88, (15x22)
    88, 0, 10, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x59,0x5b,0x20,0x52,0x59,0x46,0x4b,0x5b,
    // 'Y', 89, (17x22)
    89, 0, 12, 0, 0x4a, 0x5a, 0x46, 0x5b,
    0x4a,0x46,0x52,0x50,0x52,0x5b,0x20,0x52,0x5a,0x46,0x52,0x50,
    // 'Z', 90, (15x22)
    90, 0, 16, 0, 0x4b, 0x59, 0x46, 0x5b,
    0x59,0x46,0x4b,0x5b,0x20,0x52,0x4b,0x46,0x59,0x46,0x20,0x52,0x4b,0x5b,0x59,0x5b,
    // '[', 91, (8x33)
    91, 0, 22, 0, 0x4f, 0x56, 0x42, 0x62,
    0x4f,0x42,0x4f,0x62,0x20,0x52,0x50,0x42,0x50,0x62,0x20,0x52,0x4f,0x42,0x56,0x42,0x20,0x52,0x4f,0x62,0x56,0x62,
    // '\', 92, (15x25)
    92, 0, 4, 0, 0x4b, 0x59, 0x46, 0x5e,
    0x4b,0x46,0x59,0x5e,
    // ']', 93, (8x33)
    93, 0, 22, 0, 0x4e, 0x55, 0x42, 0x62,
    0x54,0x42,0x54,0x62,0x20,0x52,0x55,0x42,0x55,0x62,0x20,0x52,0x4e,0x42,0x55,0x42,0x20,0x52,0x4e,0x62,0x55,0x62,
    // '^', 94, (17x16)
    94, 0, 10, 0, 0x4a, 0x5a, 0x44, 0x53,
    0x52,0x44,0x4a,0x52,0x20,0x52,0x52,0x44,0x5a,0x52,
    // '_', 95, (19x18)
    95, 0, 4, 0, 0x49, 0x5b, 0x51, 0x62,
    0x49,0x62,0x5b,0x62,
    // '`', 96, (3x9)
    96, 0, 14, 0, 0x51, 0x53, 0x4b, 0x53,
    0x53,0x4b,0x51,0x4d,0x51,0x4f,0x52,0x50,0x53,0x4f,0x52,0x4e,0x51,0x4f,
    // 'a', 97, (13x15)
    97, 0, 34, 0, 0x4c, 0x58, 0x4d, 0x5b,
    0x58,0x4d,0x58,0x5b,0x20,0x52,0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,
    // 'b', 98, (13x22)
    98, 0, 34, 0, 0x4c, 0x58, 0x46, 0x5b,
    0x4c,0x46,0x4c,0x5b,0x20,0x52,0x4c,0x50,0x4e,0x4e,0x50,0x4d,0x53,0x4d,0x55,0x4e,0x57,0x50,0x58,0x53,0x58,0x55,0x57,0x58,0x55,0x5a,0x53,0x5b,0x50,0x5b,0x4e,0x5a,0x4c,0x58,
    // 'c', 99, (13x15)
    99, 0, 28, 0, 0x4c, 0x58, 0x4d, 0x5b,
    0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,
    // 'd', 100, (13x22)
    100, 0, 34, 0, 0x4c, 0x58, 0x46, 0x5b,
    0x58,0x46,0x58,0x5b,0x20,0x52,0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,
    // 'e', 101, (13x15)
    101, 0, 34, 0, 0x4c, 0x58, 0x4d, 0x5b,
    0x4c,0x53,0x58,0x53,0x58,0x51,0x57,0x4f,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,
    // 'f', 102, (9x22)
    102, 0, 16, 0, 0x4f, 0x57, 0x46, 0x5b,
    0x57,0x46,0x55,0x46,0x53,0x47,0x52,0x4a,0x52,0x5b,0x20,0x52,0x4f,0x4d,0x56,0x4d,
    // 'g', 103, (13x22)
    103, 0, 44, 0, 0x4c, 0x58, 0x4d, 0x62,
    0x58,0x4d,0x58,0x5d,0x57,0x60,0x56,0x61,0x54,0x62,0x51,0x62,0x4f,0x61,0x20,0x52,0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,
    // 'h', 104, (12x22)
    104, 0, 20, 0, 0x4d, 0x58, 0x46, 0x5b,
    0x4d,0x46,0x4d,0x5b,0x20,0x52,0x4d,0x51,0x50,0x4e,0x52,0x4d,0x55,0x4d,0x57,0x4e,0x58,0x51,0x58,0x5b,
    // 'i', 105, (3x23)
    105, 0, 16, 0, 0x51, 0x53, 0x45, 0x5b,
    0x51,0x46,0x52,0x47,0x53,0x46,0x52,0x45,0x51,0x46,0x20,0x52,0x52,0x4d,0x52,0x5b,
    // 'j', 106, (7x30)
    106, 0, 22, 0, 0x4e, 0x54, 0x45, 0x62,
    0x52,0x46,0x53,0x47,0x54,0x46,0x53,0x45,0x52,0x46,0x20,0x52,0x53,0x4d,0x53,0x5e,0x52,0x61,0x50,0x62,0x4e,0x62,
    // 'k', 107, (12x22)
    107, 0, 16, 0, 0x4d, 0x58, 0x46, 0x5b,
    0x4d,0x46,0x4d,0x5b,0x20,0x52,0x57,0x4d,0x4d,0x57,0x20,0x52,0x51,0x53,0x58,0x5b,
    // 'l', 108, (3x22)
    108, 0, 4, 0, 0x51, 0x53, 0x46, 0x5b,
    0x52,0x46,0x52,0x5b,
    // 'm', 109, (23x15)
    109, 0, 36, 0, 0x47, 0x5d, 0x4d, 0x5b,
    0x47,0x4d,0x47,0x5b,0x20,0x52,0x47,0x51,0x4a,0x4e,0x4c,0x4d,0x4f,0x4d,0x51,0x4e,0x52,0x51,0x52,0x5b,0x20,0x52,0x52,0x51,0x55,0x4e,0x57,0x4d,0x5a,0x4d,0x5c,0x4e,0x5d,0x51,0x5d,0x5b,
    // 'n', 110, (12x15)
    110, 0, 20, 0, 0x4d, 0x58, 0x4d, 0x5b,
    0x4d,0x4d,0x4d,0x5b,0x20,0x52,0x4d,0x51,0x50,0x4e,0x52,0x4d,0x55,0x4d,0x57,0x4e,0x58,0x51,0x58,0x5b,
    // 'o', 111, (14x15)
    111, 0, 34, 0, 0x4c, 0x59, 0x4d, 0x5b,
    0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,0x59,0x55,0x59,0x53,0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,
    // 'p', 112, (13x22)
    112, 0, 34, 0, 0x4c, 0x58, 0x4d, 0x62,
    0x4c,0x4d,0x4c,0x62,0x20,0x52,0x4c,0x50,0x4e,0x4e,0x50,0x4d,0x53,0x4d,0x55,0x4e,0x57,0x50,0x58,0x53,0x58,0x55,0x57,0x58,0x55,0x5a,0x53,0x5b,0x50,0x5b,0x4e,0x5a,0x4c,0x58,
    // 'q', 113, (13x22)
    113, 0, 34, 0, 0x4c, 0x58, 0x4d, 0x62,
    0x58,0x4d,0x58,0x62,0x20,0x52,0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,
    // 'r', 114, (9x15)
    114, 0, 16, 0, 0x4f, 0x57, 0x4d, 0x5b,
    0x4f,0x4d,0x4f,0x5b,0x20,0x52,0x4f,0x53,0x50,0x50,0x52,0x4e,0x54,0x4d,0x57,0x4d,
    // 's', 115, (12x15)
    115, 0, 34, 0, 0x4d, 0x58, 0x4d, 0x5b,
    0x58,0x50,0x57,0x4e,0x54,0x4d,0x51,0x4d,0x4e,0x4e,0x4d,0x50,0x4e,0x52,0x50,0x53,0x55,0x54,0x57,0x55,0x58,0x57,0x58,0x58,0x57,0x5a,0x54,0x5b,0x51,0x5b,0x4e,0x5a,0x4d,0x58,
    // 't', 116, (9x22)
    116, 0, 16, 0, 0x4f, 0x57, 0x46, 0x5b,
    0x52,0x46,0x52,0x57,0x53,0x5a,0x55,0x5b,0x57,0x5b,0x20,0x52,0x4f,0x4d,0x56,0x4d,
    // 'u', 117, (12x15)
    117, 0, 20, 0, 0x4d, 0x58, 0x4d, 0x5b,
    0x4d,0x4d,0x4d,0x57,0x4e,0x5a,0x50,0x5b,0x53,0x5b,0x55,0x5a,0x58,0x57,0x20,0x52,0x58,0x4d,0x58,0x5b,
    // 'v', 118, (13x15)
    118, 0, 10, 0, 0x4c, 0x58, 0x4d, 0x5b,
    0x4c,0x4d,0x52,0x5b,0x20,0x52,0x58,0x4d,0x52,0x5b,
    // 'w', 119, (17x15)
    119, 0, 22, 0, 0x4a, 0x5a, 0x4d, 0x5b,
    0x4a,0x4d,0x4e,0x5b,0x20,0x52,0x52,0x4d,0x4e,0x5b,0x20,0x52,0x52,0x4d,0x56,0x5b,0x20,0x52,0x5a,0x4d,0x56,0x5b,
    // 'x', 120, (12x15)
    120, 0, 10, 0, 0x4d, 0x58, 0x4d, 0x5b,
    0x4d,0x4d,0x58,0x5b,0x20,0x52,0x58,0x4d,0x4d,0x5b,
    // 'y', 121, (14x22)
    121, 0, 18, 0, 0x4b, 0x58, 0x4d, 0x62,
    0x4c,0x4d,0x52,0x5b,0x20,0x52,0x58,0x4d,0x52,0x5b,0x50,0x5f,0x4e,0x61,0x4c,0x62,0x4b,0x62,
    // 'z', 122, (12x15)
    122, 0, 16, 0, 0x4d, 0x58, 0x4d, 0x5b,
    0x58,0x4d,0x4d,0x5b,0x20,0x52,0x4d,0x4d,0x58,0x4d,0x20,0x52,0x4d,0x5b,0x58,0x5b,
    // '{', 123, (6x33)
    123, 0, 78, 0, 0x4f, 0x54, 0x42, 0x62,
    0x54,0x42,0x52,0x43,0x51,0x44,0x50,0x46,0x50,0x48,0x51,0x4a,0x52,0x4b,0x53,0x4d,0x53,0x4f,0x51,0x51,0x20,0x52,0x52,0x43,0x51,0x45,0x51,0x47,0x52,0x49,0x53,0x4a,0x54,0x4c,0x54,0x4e,0x53,0x50,0x4f,0x52,0x53,0x54,0x54,0x56,0x54,0x58,0x53,0x5a,0x52,0x5b,0x51,0x5d,0x51,0x5f,0x52,0x61,0x20,0x52,0x51,0x53,0x53,0x55,0x53,0x57,0x52,0x59,0x51,0x5a,0x50,0x5c,0x50,0x5e,0x51,0x60,0x52,0x61,0x54,0x62,
    // '|', 124, (3x33)
    124, 0, 4, 0, 0x51, 0x53, 0x42, 0x62,
    0x52,0x42,0x52,0x62,
    // '}', 125, (6x33)
    125, 0, 78, 0, 0x50, 0x55, 0x42, 0x62,
    0x50,0x42,0x52,0x43,0x53,0x44,0x54,0x46,0x54,0x48,0x53,0x4a,0x52,0x4b,0x51,0x4d,0x51,0x4f,0x53,0x51,0x20,0x52,0x52,0x43,0x53,0x45,0x53,0x47,0x52,0x49,0x51,0x4a,0x50,0x4c,0x50,0x4e,0x51,0x50,0x55,0x52,0x51,0x54,0x50,0x56,0x50,0x58,0x51,0x5a,0x52,0x5b,0x53,0x5d,0x53,0x5f,0x52,0x61,0x20,0x52,0x53,0x53,0x51,0x55,0x51,0x57,0x52,0x59,0x53,0x5a,0x54,0x5c,0x54,0x5e,0x53,0x60,0x52,0x61,0x50,0x62,
    // '~', 126, (19x7)
    126, 0, 46, 0, 0x49, 0x5b, 0x4f, 0x55,
    0x49,0x55,0x49,0x53,0x4a,0x50,0x4c,0x4f,0x4e,0x4f,0x50,0x50,0x54,0x53,0x56,0x54,0x58,0x54,0x5a,0x53,0x5b,0x51,0x20,0x52,0x49,0x53,0x4a,0x51,0x4c,0x50,0x4e,0x50,0x50,0x51,0x54,0x54,0x56,0x55,0x58,0x55,0x5a,0x54,0x5b,0x51,0x5b,0x4f,
    // 'ex127', 127, (17x22)
    127, 0, 68, 0, 0x4a, 0x5a, 0x46, 0x5b,
    0x4a,0x46,0x4a,0x5b,0x4b,0x5b,0x4b,0x46,0x4c,0x46,0x4c,0x5b,0x4d,0x5b,0x4d,0x46,0x4e,0x46,0x4e,0x5b,0x4f,0x5b,0x4f,0x46,0x50,0x46,0x50,0x5b,0x51,0x5b,0x51,0x46,0x52,0x46,0x52,0x5b,0x53,0x5b,0x53,0x46,0x54,0x46,0x54,0x5b,0x55,0x5b,0x55,0x46,0x56,0x46,0x56,0x5b,0x57,0x5b,0x57,0x46,0x58,0x46,0x58,0x5b,0x59,0x5b,0x59,0x46,0x5a,0x46,0x5a,0x5b,
    // 'ex128', 128, (16x27)
    128, 0, 42, 0, 0x4b, 0x5a, 0x41, 0x5b,
    0x5a,0x4b,0x59,0x49,0x57,0x47,0x55,0x46,0x51,0x46,0x4f,0x47,0x4d,0x49,0x4c,0x4b,0x4b,0x4e,0x4b,0x53,0x4c,0x56,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x55,0x5b,0x57,0x5a,0x59,0x58,0x5a,0x56,0x20,0x52,0x52,0x46,0x56,0x41,
    // 'ex129', 129, (16x27)
    129, 0, 44, 0, 0x4b, 0x5a, 0x41, 0x5b,
    0x5a,0x4b,0x59,0x49,0x57,0x47,0x55,0x46,0x51,0x46,0x4f,0x47,0x4d,0x49,0x4c,0x4b,0x4b,0x4e,0x4b,0x53,0x4c,0x56,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x55,0x5b,0x57,0x5a,0x59,0x58,0x5a,0x56,0x20,0x52,0x4e,0x41,0x52,0x46,0x56,0x41,
    // 'ex130', 130, (15x27)
    130, 0, 48, 0, 0x4b, 0x59, 0x41, 0x5b,
    0x59,0x49,0x57,0x47,0x54,0x46,0x50,0x46,0x4d,0x47,0x4b,0x49,0x4b,0x4b,0x4c,0x4d,0x4d,0x4e,0x4f,0x4f,0x55,0x51,0x57,0x52,0x58,0x53,0x59,0x55,0x59,0x58,0x57,0x5a,0x54,0x5b,0x50,0x5b,0x4d,0x5a,0x4b,0x58,0x20,0x52,0x4e,0x41,0x52,0x46,0x56,0x41,
    // 'ex131', 131, (15x27)
    131, 0, 24, 0, 0x4b, 0x59, 0x41, 0x5b,
    0x59,0x46,0x4b,0x5b,0x20,0x52,0x4b,0x46,0x59,0x46,0x20,0x52,0x4b,0x5b,0x59,0x5b,0x20,0x52,0x4e,0x41,0x52,0x46,0x56,0x41,
    // 'ex132', 132, (13x18)
    132, 0, 34, 0, 0x4c, 0x58, 0x4a, 0x5b,
    0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,0x20,0x52,0x52,0x4d,0x56,0x4a,
    // 'ex133', 133, (13x19)
    133, 0, 36, 0, 0x4c, 0x58, 0x49, 0x5b,
    0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,0x20,0x52,0x4e,0x49,0x52,0x4d,0x56,0x49,
    // 'ex134', 134, (12x19)
    134, 0, 42, 0, 0x4d, 0x58, 0x49, 0x5b,
    0x58,0x50,0x57,0x4e,0x54,0x4d,0x51,0x4d,0x4e,0x4e,0x4d,0x50,0x4e,0x52,0x50,0x53,0x55,0x54,0x57,0x55,0x58,0x57,0x58,0x58,0x57,0x5a,0x54,0x5b,0x51,0x5b,0x4e,0x5a,0x4d,0x58,0x20,0x52,0x4e,0x49,0x52,0x4d,0x56,0x49,
    // 'ex135', 135, (12x19)
    135, 0, 24, 0, 0x4d, 0x58, 0x49, 0x5b,
    0x58,0x4d,0x4d,0x5b,0x20,0x52,0x4d,0x4d,0x58,0x4d,0x20,0x52,0x4d,0x5b,0x58,0x5b,0x20,0x52,0x4e,0x49,0x52,0x4d,0x56,0x49,
    // 'ex136', 136, (18x22)
    136, 0, 36, 0, 0x48, 0x59, 0x46, 0x5b,
    0x4b,0x46,0x4b,0x5b,0x20,0x52,0x4b,0x46,0x52,0x46,0x55,0x47,0x57,0x49,0x58,0x4b,0x59,0x4e,0x59,0x53,0x58,0x56,0x57,0x58,0x55,0x5a,0x52,0x5b,0x4b,0x5b,0x20,0x52,0x48,0x50,0x4e,0x50,
    // 'ex137', 137, (17x22)
    137, 0, 40, 0, 0x4c, 0x5c, 0x46, 0x5b,
    0x58,0x46,0x58,0x5b,0x20,0x52,0x58,0x50,0x56,0x4e,0x54,0x4d,0x51,0x4d,0x4f,0x4e,0x4d,0x50,0x4c,0x53,0x4c,0x55,0x4d,0x58,0x4f,0x5a,0x51,0x5b,0x54,0x5b,0x56,0x5a,0x58,0x58,0x20,0x52,0x55,0x48,0x5c,0x48,
};

#endif

