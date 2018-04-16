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
typedef std::set<string> LabelList;
typedef std::list<Object*> ListaObj;

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
        string alias, elementType;
        float value;
        //float positiveN, negativeN; //, value;
        int type, positiveN, negativeN, cPositiveN, cNegativeN, nC, nB, nE, nD, nG, nS;
        const char * c;

    public:
        Element(String &line, String type, vector<string> &result, LabelList &labels, ListaObj &lista, Elements element);
        ~Element();
        vector<string> split();

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

        virtual float getValue(){
            return this->value;
        };

        virtual void setValue(String v){
            this->value = std::stof(v);
            if ((v.substr(v.size() - 3) == "meg") || (v.substr(v.size() - 3) == "MEG")){
                this->value = this->value*10E6;
            }
            switch (tolower(v.back())) {
                case 'k': {
                    this->value = this->value * 10E3;
                    if (d) cout << this->value << endl;
                    break;
                }
                case 'm': {
                    this->value = this->value * 10E-3;
                    if (d) cout << this->value << endl;
                    break;
                }
                case 'f': {
                    this->value = this->value * 10E-15;
                    cout << this->value << endl;
                    break;
                }
                case 'p': {
                    this->value = this->value * 10E-12;
                    if (d) cout << this->value << endl;
                    break;
                }
                case 'n': {
                    this->value = this->value * 10E-9;
                    if (d) cout << this->value << endl;
                    break;
                }
                case 'u': {
                    this->value = this->value * 10E-6;
                    if (d) cout << this->value << endl;
                    break;
                }
                case 'g': {
                    this->value = this->value * 10E9;
                    if (d) cout << this->value << endl;
                    break;
                }
                case 't': {
                    this->value = this->value * 10E12;
                    if (d) cout << this->value << endl;
                    break;
                }
            }

        };

        virtual String getAlias(){
            return this->alias;
        };
        virtual void setAlias(string a){
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
};


#endif //TOPICOSI_ELEMENT_H
