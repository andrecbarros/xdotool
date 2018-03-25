/* xdo utility pieces 
 *
 * $Id$
 */

#ifndef _XDO_UTIL_H_
#define _XDO_UTIL_H_

#include "xdo.h"

/* human to Keysym string mapping */
static const char *symbol_map[] = {
  "alt", "Alt_L",
  "ctrl", "Control_L",
  "control", "Control_L",
  "meta", "Meta_L",
  "super", "Super_L",
  "shift", "Shift_L",
  NULL, NULL,
};

/* Define some convenient and traditional \\<symbol> inside strings */
const char *escC = "'\"?abdefnrtv";
const uint32_t escC_map[] = {
  XK_apostrophe,              XK_quotedbl,                XK_question,                '\a',                       '\b',
  '\x7f',                     '\x1b',                     '\f',                       '\n',                       '\r',
  '\t',                       '\v',                       0
};

/* What is called ANSI here is actually the quite popular ISO-8859-1 plus special chars found in Windows-1252 charset
   for code points between 0x80..0x9f
   To be used:
   - Prior to its insert point as \\<number>; there should exist an \\A somewhere in the string (with optional termination \\T).
*/
const uint32_t escANSI_map[] = {
  XK_EuroSign,                0x20081,                    XK_singlelowquotemark,      XK_function,                XK_doublelowquotemark,
  XK_ellipsis,                XK_dagger,                  XK_doubledagger,            XK_Ccircumflex,             XK_permille,
  XK_Scaron,                  0x12039,                    XK_OE,                      0x2008d,                    XK_Zcaron,
  0x2008f,                    0x20090,                    XK_leftsinglequotemark,     XK_rightsinglequotemark,    XK_leftdoublequotemark,
  XK_rightdoublequotemark,    XK_enfilledcircbullet,      XK_endash,                  XK_emdash,                  0x102dc,
  XK_trademark,               XK_scaron,                  0x1203a,                    XK_oe,                      0x2009d,
  XK_zcaron,                  XK_Ydiaeresis
};

/* HTML symbols have widespread use and as so may be convenient for some */
#ifdef HTML_SYMBOLS
/* To be used:
   - HTML_SYMBOLS should be defined at compilation time;
   - Prior to its insert point as &<symbol>; there should exist an \\H somewhere in the string (with optional termination \\L).
*/
typedef struct HTML_map {const char * sym; const uint32_t utf;} HTML_map;
static const HTML_map html_map[] = { /* mainly xml symbols, punctuations, math symbols, greek symbols and chars used in physics (script) */
  {"AElig", 0x00C6},          {"Alpha", 0x0391},          {"Ascr", 0x1D49C},          {"Beta", 0x0392},           {"Bscr", 0x212C},
  {"Chi", 0x03A7},            {"Cscr", 0x1D49E},          {"Dagger", 0x2021},         {"Delta", 0x0394},          {"Dscr", 0x1D49F},
  {"ETH", 0x00D0},            {"Epsilon", 0x0395},        {"Escr", 0x2130},           {"Eta", 0x0397},            {"Fscr", 0x2131},
  {"Gamma", 0x0393},          {"Gscr", 0x1D4A2},          {"Hscr", 0x210B},           {"Iota", 0x0399},           {"Iscr", 0x2110},
  {"Jscr", 0x1D4A5},          {"Kappa", 0x039A},          {"Kscr", 0x1D4A6},          {"Lambda", 0x039B},         {"Lscr", 0x2112},
  {"Mscr", 0x2133},           {"Mu", 0x039C},             {"Nscr", 0x1D4A9},          {"Nu", 0x039D},             {"OElig", 0x0152},
  {"Omega", 0x03A9},          {"Omicron", 0x039F},        {"Oscr", 0x1D4AA},          {"Oslash", 0x00D8},         {"Phi", 0x03A6},
  {"Pi", 0x03A0},             {"Prime", 0x2033},          {"Pscr", 0x1D4AB},          {"Psi", 0x03A8},            {"Qscr", 0x1D4AC},
  {"Rho", 0x03A1},            {"Rscr", 0x211B},           {"Sigma", 0x03A3},          {"Sscr", 0x1D4AE},          {"THORN", 0x00DE},
  {"Tau", 0x03A4},            {"Theta", 0x0398},          {"Tscr", 0x1D4AF},          {"Upsilon", 0x03A5},        {"Uscr", 0x1D4B0},
  {"Vscr", 0x1D4B1},          {"Wscr", 0x1D4B2},          {"Xi", 0x039E},             {"Xscr", 0x1D4B3},
  {"Yscr", 0x1D4B4},          {"Zeta", 0x0396},           {"Zscr", 0x1D4B5},

  {"ac", 0x223E},             {"acd", 0x223F},            {"aelig", 0x00E6},          {"alefsym", 0x2135},        {"alpha", 0x03B1},
  {"amp", 0x0026},            {"and", 0x2227},            {"ang", 0x2220},            {"apos", 0x0027},           {"asymp", 0x2248},
  {"bdquo", 0x201E},          {"beta", 0x03B2},           {"brvbar", 0x00A6},         {"bull", 0x2022},           {"cap", 0x2229},
  {"cent", 0x00A2},           {"chi", 0x03C7},            {"circ", 0x02C6},           {"clubs", 0x2663},          {"complexes", 0x2102},
  {"cong", 0x2245},           {"copy", 0x00A9},           {"crarr", 0x21B5},          {"cup", 0x222A},            {"curren", 0x00A4},
  {"dArr", 0x21D3},           {"dagger", 0x2020},         {"darr", 0x2193},           {"deg", 0x00B0},            {"delta", 0x03B4},
  {"diams", 0x2666},          {"divide", 0x00F7},         {"empty", 0x2205},          {"emsp", 0x2003},           {"ensp", 0x2002},
  {"epsilon", 0x03B5},        {"epsiv", 0x03F5},          {"equal", 0x003D},          {"equiv", 0x2261},          {"eta", 0x03B7},
  {"eth", 0x00F0},            {"euro", 0x20AC},           {"exclamation", 0x0021},    {"exist", 0x2203},          {"fnof", 0x0192},
  {"forall", 0x2200},         {"frac12", 0x00BD},         {"frac14", 0x00BC},         {"frac34", 0x00BE},         {"frasl", 0x2044},
  {"gamma", 0x03B3},          {"ge", 0x2265},             {"gt", 0x003E},             {"hArr", 0x21D4},           {"harr", 0x2194},
  {"hearts", 0x2665},         {"hellip", 0x2026},         {"horbar", 0x2015},         {"image", 0x2111},          {"imped", 0x01B5},
  {"infin", 0x221E},          {"int", 0x222B},            {"integers", 0x2124},       {"iota", 0x03B9},           {"iquest", 0x00BF},
  {"isin", 0x2208},           {"kappa", 0x03BA},          {"lArr", 0x21D0},           {"lambda", 0x03BB},         {"lang", 0x2329},
  {"laquo", 0x00AB},          {"larr", 0x2190},           {"lceil", 0x2308},          {"ldquo", 0x201C},          {"le", 0x2264},
  {"lfloor", 0x230A},         {"lowast", 0x2217},         {"loz", 0x25CA},            {"lrm", 0x200E},            {"lsaquo", 0x2039},
  {"lsquo", 0x2018},          {"lt", 0x003C},             {"macr", 0x00AF},           {"mdash", 0x2014},          {"mho", 0x2127},
  {"micro", 0x00B5},          {"middot", 0x00B7},         {"minus", 0x2212},          {"mu", 0x03BC},             {"nabla", 0x2207},
  {"naturals", 0x2115},       {"nbsp", 0x00A0},           {"ndash", 0x2013},          {"ne", 0x2260},             {"ni", 0x220B},
  {"not", 0x00AC},            {"notin", 0x2209},          {"nsub", 0x2284},           {"nu", 0x03BD},             {"oelig", 0x0153},
  {"ohm", 0x2126},            {"oint", 0x222E},           {"oline", 0x203E},          {"omega", 0x03C9},          {"omicron", 0x03BF},
  {"oplus", 0x2295},          {"or", 0x2228},             {"ordf", 0x00AA},           {"ordm", 0x00BA},           {"oslash", 0x00F8},
  {"otimes", 0x2297},         {"para", 0x00B6},           {"part", 0x2202},           {"percent", 0x0025},        {"permil", 0x2030},
  {"perp", 0x22A5},           {"phi", 0x03C6},            {"pi", 0x03C0},             {"piv", 0x03D6},            {"planck", 0x210F},
  {"planckh", 0x210E},        {"plusmn", 0x00B1},         {"pound", 0x00A3},          {"prime", 0x2032},          {"prod", 0x220F},
  {"prop", 0x221D},           {"psi", 0x03C8},            {"quaternions", 0x210D},    {"quot", 0x0022},           {"rArr", 0x21D2},
  {"radic", 0x221A},          {"rang", 0x232A},           {"raquo", 0x00BB},          {"rarr", 0x2192},           {"rationals", 0x211A},
  {"rceil", 0x2309},          {"rdquo", 0x201D},          {"real", 0x211C},           {"reals", 0x211D},          {"reg", 0x00AE},
  {"rfloor", 0x230B},         {"rho", 0x03C1},            {"rhov", 0x03F1},           {"rlm", 0x200F},            {"rsaquo", 0x203A},
  {"rsquo", 0x2019},          {"sbquo", 0x201A},          {"sdot", 0x22C5},           {"sect", 0x00A7},           {"shy", 0x00AD},
  {"sigma", 0x03C3},          {"sigmaf", 0x03C2},         {"sim", 0x223C},            {"spades", 0x2660},         {"sub", 0x2282},
  {"sube", 0x2286},           {"sum", 0x2211},            {"sup", 0x2283},            {"sup1", 0x00B9},           {"sup2", 0x00B2},
  {"sup3", 0x00B3},           {"supe", 0x2287},           {"szlig", 0x00DF},          {"tau", 0x03C4},            {"there4", 0x2234},
  {"theta", 0x03B8},          {"thetasym", 0x03D1},       {"thinsp", 0x2009},         {"thorn", 0x00FE},          {"tilde", 0x02DC},
  {"times", 0x00D7},          {"trade", 0x2122},          {"uArr", 0x21D1},           {"uarr", 0x2191},           {"uml", 0x00A8},
  {"upsih", 0x03D2},          {"upsilon", 0x03C5},        {"weierp", 0x2118},         {"xi", 0x03BE},             {"yen", 0x00A5},
  {"zeta", 0x03B6},           {"zwj", 0x200D},            {"zwnj", 0x200C}
};
#endif

#endif /* ifndef _XDO_UTIL_H_ */
