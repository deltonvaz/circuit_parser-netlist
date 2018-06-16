//
// Created by delto on 15/04/2018.
//

#ifndef TOPICOSI_CONSTANTS_H
#define TOPICOSI_CONSTANTS_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <set>


#define de 0 // Debug element level
#define dOut 0 // Debug outputlist level
#define d 0 // Debug level
#define testMatrix 0 // Debug level

#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#endif  /* _COLORS_ */

using namespace std;
using String = std::string;
using fileStd = std::fstream;

enum TYPES {
    COMMAND,
    COMMENT,
    ELEMENT
};

enum VALUETYPES{
    FLOAT,
    STRING
};

enum GROUP{
    NONE, //just to stay beauty :v
    G1,
    G2
};

typedef struct value {
    double floatValue;
    string stringValue;
    int type;
} value;

#endif //TOPICOSI_CONSTANTS_H
