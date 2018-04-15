//
// Created by delto on 15/04/2018.
//

#ifndef TOPICOSI_CONSTANTS_H
#define TOPICOSI_CONSTANTS_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


#define d 1 // Debug level
using namespace std;
using String = std::string;
using fileStd = std::fstream;

enum TYPES {
    COMMAND,
    COMMENT,
    ELEMENT
};
#endif //TOPICOSI_CONSTANTS_H
