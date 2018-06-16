//
// Created by Delton on 13/04/18.
//

#include "Command.h"
#include <utility>
#include <algorithm>
#include <unordered_map>

Command::Command(){
    this->type = COMMAND;
};

void Command::setCommand(String command){
    this->command = std::move(command);
};

string Command::getCommand(){
    return this->command;
};

void Command::setType(int t){
};

int Command::getType() {
    return COMMAND;
}

Command::~Command() {

}

int getVectorIndex(vector<string> vec, string str){
    ptrdiff_t pos = distance(vec.begin(), find(vec.begin(), vec.end(), str));
    return pos;
}

vector<string> getIndexes(Parser* p){
    ListaObj* elementList = p->getObjectList();
    vector<string> nodes = p->getNodes();
    vector<string> aliases;
    //Parse volt nodes
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        if(distance(nodes.begin(), it) != 0){
            aliases.push_back(*it);
        }
    }
    //Parse currentNodes
    for (auto it = elementList->begin(); it != elementList->end(); ++it) {
        auto obj = *it;
        if (obj->getType() == ELEMENT) {
            Element *element = (Element *) obj;
            if (element->getElementType().compare("V") == 0 | element->getElementType().compare("E") == 0 | element->getElementType().compare("G") == 0 )
                aliases.push_back(element->getStringAlias());
            else if (element->getElementType().compare("H") == 0){
                aliases.push_back(element->getStringAlias());
                aliases.push_back(element->getControlElementString());
            }
        }
    }
    return aliases;
}

int countControledElements(Parser* p){
    ListaObj* elementList = p->getObjectList();
    int count = 0;
    for (auto it = elementList->begin(); it != elementList->end(); ++it) {
        auto obj = *it;
        if (obj->getType() == ELEMENT) {
            Element *element = (Element *) obj;
            if (element->getElementType().compare("F") == 0 | element->getElementType().compare("H") == 0)
                count++;
        }
    }
    return count;
}

Matrix Command::generateResult(Parser* p, ofstream* outputFile) {
    ListaObj* elementList = p->getObjectList();
    int positiveN, negativeN, currenIndex;
    int m = (int) elementList->size();
    vector<string> aliases;
    Matrix x, mna, s;
    aliases = getIndexes(p);
    m = m+countControledElements(p);
    //Check elements for s matrix, all nodes and current of voltage sources
    x = Matrix(m, 1);
    s = Matrix(m, 1);
    mna = Matrix(m,m);
    for (auto it = elementList->begin(); it != elementList->end(); ++it) {
        auto obj = *it;
        if (obj->getType() == ELEMENT) {
            Element *element = (Element *) obj;
            positiveN = element->getPositiveNode();
            negativeN = element->getNegativeNode();
            currenIndex = getVectorIndex(aliases, element->getStringAlias())+1;
            if (element->getElementType().compare("R") == 0){ // Resistance G1 case
                if(element->getGroup() == G1) {
                    if (positiveN < 0) {
                        mna(negativeN, negativeN) += (1 / element->getFloatValue());
                    } else if (negativeN < 0) {
                        mna(positiveN, positiveN) += (1 / element->getFloatValue());
                    } else {
                        mna(positiveN, positiveN) += (1 / element->getFloatValue());
                        mna(negativeN, negativeN) += (1 / element->getFloatValue());
                        mna(positiveN, negativeN) -= 1 / element->getFloatValue();
                        mna(negativeN, positiveN) -= 1 / element->getFloatValue();
                    }
                }else{ // group 2 case
                    int auxIndex = getVectorIndex(aliases, element->getStringAlias())+1;
                    mna(positiveN, auxIndex) += 1;
                    mna(negativeN, auxIndex) -= 1;

                    mna(auxIndex, positiveN) += 1;
                    mna(auxIndex, negativeN) -= 1;
                    mna(auxIndex, auxIndex) -= element->getFloatValue();
                }

            }else if (element->getElementType().compare("V") == 0) { // VS case, always group 2
                mna(positiveN, currenIndex) += 1;
                mna(negativeN, currenIndex) -= 1;

                mna(currenIndex, positiveN) += 1;
                mna(currenIndex, negativeN) -= 1;

                x(currenIndex, 0) = currenIndex;

                s(currenIndex,0) = element->getFloatValue();

            }else if (element->getElementType().compare("E") == 0) { // VCVS case
                mna(positiveN, currenIndex) += 1;
                mna(negativeN, currenIndex) -= 1;

                mna(currenIndex, positiveN) += 1;
                mna(currenIndex, negativeN) -= 1;

                mna(currenIndex, element->getControlledPositiveNode()) -= element->getFloatValue();
                mna(currenIndex, element->getControlledNegativeNode()) += element->getFloatValue();

                x(currenIndex, 0) = currenIndex;

            }else if (element->getElementType().compare("G") == 0) { // VCCS case
                mna(positiveN, element->getControlledPositiveNode()) += element->getFloatValue();
                mna(positiveN, element->getControlledNegativeNode()) -= element->getFloatValue();

                mna(negativeN, element->getControlledPositiveNode()) -= element->getFloatValue();
                mna(negativeN, element->getControlledNegativeNode()) += element->getFloatValue();

                x(currenIndex, 0) = currenIndex;

            }else if (element->getElementType().compare("I") == 0) {// IS case, group 1
                if(element->getGroup() == G1){
                    x(positiveN,0) = positiveN;
                    x(negativeN,0) = negativeN;
                    s(positiveN,0) -= element->getFloatValue();
                    s(negativeN,0) += element->getFloatValue();
                }else{
                    mna(positiveN, currenIndex) += 1;
                    mna(negativeN, currenIndex) -= 1;
                    mna(currenIndex, currenIndex) += 1;
                    s(currenIndex,0) += element->getFloatValue();
                }

            }else if (element->getElementType().compare("H") == 0) {// CCVS = H
                mna(positiveN, currenIndex) += 1;
                mna(negativeN, currenIndex) -= 1;

                mna(currenIndex, positiveN) += 1;
                mna(currenIndex, negativeN) -= 1;

                mna(currenIndex, getVectorIndex(aliases, element->getControlElementString())+1) -= element->getFloatValue();

            } else if (element->getElementType().compare("F") == 0) {// CCCS = F
                mna(positiveN, getVectorIndex(aliases, element->getControlElementString())+1) += element->getFloatValue();
                mna(negativeN, getVectorIndex(aliases, element->getControlElementString())+1) -= element->getFloatValue();

            }
        }
    }
    Matrix eMna, eS;
    //Eliminate 0 values from h and s matrixes
    eMna = mna.eliminateFirstLineAndColumn();
    eS = s.eliminateFirstLine();

    Matrix mnaInverse;
    mnaInverse = eMna.inverse();
    //Multiplication
    x = mnaInverse*eS;

    int checkIndex = 0;

    *outputFile << endl << "Tensões e correntes nos nós: " << endl << endl;
    if(d) cout << endl;
    for (auto pp = aliases.begin(); pp != aliases.end(); pp++) {
        checkIndex = (int) distance(aliases.begin(), pp);
        if (checkIndex == p->getNodes().size()-1) {
            if(d) cout << endl;
            *outputFile << endl;
        }
        if (x(checkIndex, 0) != 0 || checkIndex < p->getNodes().size() - 1) {
            if(d) cout << "V(" << *pp << ") = " << x((int) distance(aliases.begin(), pp), 0) << endl;
            *outputFile << "V(" << *pp << ") = " << x((int) distance(aliases.begin(), pp), 0) << endl;
        }else if(x(checkIndex, 0) != 0){
            if(d) cout << "I(" << *pp << ") = " << x((int) distance(aliases.begin(), pp), 0) << endl;
            *outputFile << "I(" << *pp << ") = " << x((int) distance(aliases.begin(), pp), 0) << endl;
        }
    }
    if(d) cout << endl;
    *outputFile << endl;
    return s;
}