//
// Created by dev on 13/04/18.
//
#include <string>
#include <cstring>
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
        char *alias;
        float positiveN, negativeN, value;
        int type;
        Elements teste;
    public:
        Element();
        ~Element();

        virtual void setElementType(Elements type){
            this->teste = type;
        }

        virtual void setPositiveNode(String v){
            std::string::size_type sz;     // alias of size_t
            this->positiveN = std::stof (v,&sz);
        };

        virtual float getPositiveNode(){
            return this->positiveN;
        };

        virtual void setNegativeNode(String v){
            std::string::size_type sz;     // alias of size_t
            this->negativeN = std::stof (v,&sz);
        };

        virtual float getNegativeNode(){
            return this->negativeN;
        };

        virtual void setType(int t){
            this->type = t;
        };

        virtual int getType(){
            return this->type;
        }

        virtual float getValue(){
            return this->value;
        };

        virtual void setValue(String v){
            std::string::size_type sz;     // alias of size_t
            this->value = std::stof (v,&sz);
        };

        virtual String getAlias(){
            return this->alias;
        };
        virtual void setAlias(const char *a){
            strcpy(this->alias, a);
        };
};


#endif //TOPICOSI_ELEMENT_H
