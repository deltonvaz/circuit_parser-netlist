//
// Created by dev on 13/04/18.
//
#include <string>
#include <cstring>
#include <map>
#include <iterator>
#include "Constants.h"
#include "Object.h"

#ifndef TOPICOSI_ELEMENT_H
#define TOPICOSI_ELEMENT_H

enum Elements
{
    RESISTOR,
    CAPACITOR,
    INDUTOR,
    FONTE_TENSAO,
    FONTE_CORRENTE,
    FONTE_VCVS, //Voltage controlled voltage source E<rótulo> <nó+> <nó-> <nóC+> <nóC-> <valor>
    FONTE_CCCS, //Current controlled current source F<rótulo> <nó+> <nó-> <nóC+> <nóC-> <valor>
    FONTE_VCCS, //Voltage controlled current source G<rótulo> <nó+> <nó-> <nóC+> <nóC-> <valor>
    FONTE_CCVS, //Current controlled voltage source H<rótulo> <nó+> <nó-> <nóC+> <nóC-> <valor>
    DIODO,
    TJB,
    MOSFET
};

class Element : public Object {
    private:
        string alias, elementType, value;
        //float positiveN, negativeN; //, value;
        int type, positiveN, negativeN;
    public:
        Element();
        ~Element();

        virtual void setElementType(string type){
            this->elementType = type;
        }

        virtual string getElementType(){
            return this->elementType;
        }

        virtual void setPositiveNode(int v){
            this->positiveN = v;
        };

        virtual int getPositiveNode(){
            return this->positiveN;
        };

        virtual void setNegativeNode(int v){
            this->negativeN = v;
        };

        virtual int getNegativeNode(){
            return this->negativeN;
        };

        virtual void setType(int t){
            this->type = t;
        };

        virtual int getType(){
            return this->type;
        }

        virtual string getValue(){
            return this->value;
        };

        virtual void setValue(String v){
            this->value = v;
        };

        virtual String getAlias(){
            return this->alias;
        };
        virtual void setAlias(string a){
            this->alias = a;
        };
};


#endif //TOPICOSI_ELEMENT_H
