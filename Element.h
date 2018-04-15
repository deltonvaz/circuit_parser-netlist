//
// Created by dev on 13/04/18.
//
#include <string>

using String = std::string;

#ifndef TOPICOSI_ELEMENT_H
#define TOPICOSI_ELEMENT_H


class Element {
    public:
        String type;
        virtual void newElement();
};


#endif //TOPICOSI_ELEMENT_H
