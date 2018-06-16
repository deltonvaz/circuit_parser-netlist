//
// Created by Delton on 13/04/18.
//
#include <string>
#include <cstring>
#include <map>
#include <iterator>
#include "Constants.h"
#include "Object.h"

#ifndef TOPICOSI_ELEMENT_H
#define TOPICOSI_ELEMENT_H

typedef std::list<Object*> ListaObj;

class Element : public Object {
    private:
        string elementType, stringValue, controlElementString, stringAlias, stringNode;
        double floatValue;
        int type, positiveN, negativeN, cPositiveN, cNegativeN, nC, nB, nE, nD, nG, nS, alias, valueType, controlElement, group;

public:
        Element();
        ~Element();

        friend std::ostream& operator<<(std::ostream&, const Element&);

        virtual void setControlElementString(string str){
            this->controlElementString = str;
        }

        virtual string getControlElementString(){
            return this->controlElementString;
        }

        virtual int getGroup(){
            return this->group;
        }

        virtual void setGroup(int vt){
            this->group = vt;
        }

        virtual int getValueType(){
            return this->valueType;
        }

        virtual void setValueType(int vt){
            this->valueType = vt;
        }

        virtual string getStringValue(){
            return this->stringValue;
        }

        virtual void setStringValue(string vt){
            this->stringValue = vt;
        }

        virtual double getFloatValue(){
            return this->floatValue;
        }

        virtual void setFloatValue(double vt){
            this->floatValue = vt;
        }

        virtual void setElementType(string type){
            this->elementType = type;
        }

        virtual string getElementType(){
            return this->elementType;
        }

        virtual void setStringAlias(string stringAlias){
            this->stringAlias = stringAlias;
        }

        virtual string getStringAlias(){
            return this->stringAlias;
        }

        virtual void setStringNode(string stringNode){
            this->stringNode = stringNode;
        }

        virtual string getStringNode(){
            return this->stringNode;
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

        virtual int getAlias(){
            return this->alias;
        };
        virtual void setAlias(int a){
            this->alias = a;
        };

        virtual int getControlledPositiveNode(){
            return this->cPositiveN;
        }

        virtual void setControlledPositiveNode(int v){
            this->cPositiveN = v;
        }

        virtual int getControlledNegativeNode(){
            return this->cNegativeN;
        }

        virtual void setControlledNegativeNode(int v){
            this->cNegativeN = v;
        }

        virtual void setnC(int v){
            this->nC = v;
        };

        virtual int getnC(){
            return this->nC;
        };

        virtual void setnB(int v){
            this->nC = v;
        };

        virtual int getnB(){
            return this->nB;
        };

        virtual void setnE(int v){
            this->nB = v;
        };

        virtual int getnE(){
            return this->nE;
        };

        virtual void setnD(int v){
            this->nD = v;
        };

        virtual int getnD(){
            return this->nD;
        };

        virtual void setnG(int v){
            this->nG = v;
        };

        virtual int getnG(){
            return this->nG;
        };

        virtual void setnS(int v){
            this->nS = v;
        };

        virtual int getnS(){
            return this->nS;
        };

        virtual void setControlElement(int v){
            this->controlElement = v;
        };

        virtual int getControlElement(){
            return this->controlElement;
        };

};


#endif //TOPICOSI_ELEMENT_H
