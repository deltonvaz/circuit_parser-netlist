//
// Created by delto on 15/04/2018.
//

#ifndef TOPICOSI_OBJECT_H
#define TOPICOSI_OBJECT_H

#include "Constants.h"

class Object {
    public:
        int type{};
        virtual int getType() = 0;
        virtual void setType(int t) = 0;
};


#endif //TOPICOSI_OBJECT_H
