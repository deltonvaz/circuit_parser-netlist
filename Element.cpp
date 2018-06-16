//
// Created by Delton on 13/04/18.
//

#include <algorithm>
#include "Element.h"

Element::Element() {
    this->setType(ELEMENT);
}

Element::~Element() {
}

ostream& operator<<(ostream& os, const Element& m)
{
    string et = m.elementType;
    std::cout.precision(6);
    if(et.compare("R") == 0 | et.compare("C") == 0 | et.compare("L") == 0 | et.compare("V") == 0 | et.compare("I") == 0 | et.compare("D") == 0) {
        if (et.compare("R") == 0)
            os << "RES [";
        else if (et.compare("C") == 0)
            os << "CAP [";
        else if (et.compare("L") == 0)
            os << "IND [";
        else if (et.compare("V") == 0)
            os << "VS  [";
        else if (et.compare("I") == 0)
            os << "IS  [";
        else if (et.compare("D") == 0)
            os << "DIO [";

        os << m.alias << "]; n+[" << m.positiveN << "], n-[" << m.negativeN
              << "]; value=";

        if (m.valueType == FLOAT) os << scientific << m.floatValue;
        else os << m.stringValue;


    }else if(et.compare("E") == 0 | et.compare("G") == 0) {
        if (et.compare("E") == 0) os << "VCVS[";
        else if (et.compare("G") == 0) os << "VCCS[";

        os << m.alias << "]; na[" << m.positiveN << "], nb["
              << m.negativeN << "], nc[" << m.cPositiveN << "], nd["
              << m.cNegativeN << "]; value=";

        if (m.valueType == FLOAT) os << scientific << m.floatValue;
        else os << m.stringValue;

    }else if(et.compare("H") == 0 | et.compare("F") == 0){
        if (et.compare("F") == 0) os << "CCCS[";
        else if (et.compare("H") == 0) os << "CCVS[";

        os << m.alias << "]; n+[" << m.positiveN << "], n-[" << m.negativeN
              << "], controlElement[" << m.controlElement << "]; value=";

        if (m.valueType == FLOAT) os << scientific << m.floatValue;
        else os << m.stringValue;

    }else{
        if (et.compare("Q") == 0) {
            os << "TJB\t[" << m.alias << "]; nC" << m.nC << "], nB[" << m.nB << "] nE["
                  << m.nE << "]; value=";
            if (m.valueType == FLOAT) os << scientific << m.floatValue;
            else os << m.stringValue;

        } else if (et.compare("M") == 0) {
            os << "MOS [" << m.alias << "]; nd[" << m.nD << "], ng[" << m.nG << "], ns["
                  << m.nS << "]; value=";
            if (m.valueType == FLOAT) os << scientific << m.floatValue;
            else os << m.stringValue;
        }
    }

    os << endl;
    return os;
}