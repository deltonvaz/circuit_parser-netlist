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

typedef struct value {
    double floatValue;
    string stringValue;
    int type;
} value;

#endif //TOPICOSI_CONSTANTS_H
