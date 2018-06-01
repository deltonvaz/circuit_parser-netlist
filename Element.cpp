//
// Created by Delton on 13/04/18.
//

#include "Element.h"

Element::Element() {
    this->setType(ELEMENT);
}

Element::~Element() {
}

void Element::printElement(ofstream *file) {
    string et = this->getElementType();
    std::cout.precision(6);
    if(et.compare("R") == 0 | et.compare("C") == 0 | et.compare("L") == 0 | et.compare("V") == 0 | et.compare("I") == 0 | et.compare("D") == 0) {
        if (this->getElementType().compare("R") == 0) {
            if (de) cout << "RES [";
            *file << "RES [";
        } else if (this->getElementType().compare("C") == 0) {
            if (de) cout << "CAP [";
            *file << "CAP [";
        } else if (this->getElementType().compare("L") == 0) {
            if (de) cout << "IND [";
            *file << "IND [";
        } else if (this->getElementType().compare("V") == 0) {
            if (de) cout << "VS [";
            *file << "VS [";
        } else if (this->getElementType().compare("I") == 0) {
            if (de) cout << "IS [";
            *file << "IS [";
        } else if (this->getElementType().compare("D") == 0) {
            if (de) cout << "DIO [";
            *file << "DIO [";
        }
        if (de) cout << this->getAlias() << "]; n+[" << this->getPositiveNode() << "]; n-[" << getNegativeNode() << "]; value=";

        *file << this->getAlias() << "]; n+[" << this->getPositiveNode() << "]; n-[" << getNegativeNode()
              << "]; value=";
        if (this->getValueType() == FLOAT) {
            if (de) cout << this->getFloatValue();
            *file << scientific << this->getFloatValue();
        }else {
            if (de) cout << this->getStringValue();
            *file << this->getStringValue();
        }
    }else if(et.compare("E") == 0 | et.compare("F") == 0 | et.compare("G") == 0 | et.compare("H") == 0 ) {
        if (this->getElementType().compare("E") == 0) {
            if (de) cout << "VCVS[";
            *file << "VCVS[";
        } else if (this->getElementType().compare("F") == 0) {
            if (de)cout << "CCCS[";
            *file << "CCCS[";
        } else if (this->getElementType().compare("G") == 0) {
            if (de) cout << "VCCS[";
            *file << "VCCS[";
        } else if (this->getElementType().compare("H") == 0) {
            if (de) cout << "CCVS[";
            *file << "CCVS[";
        }
        if (de) cout << this->getAlias() << "]; na[" << this->getPositiveNode() << "], nb["
                            << getNegativeNode() << "], nc[" << this->getControlledPositiveNode() << "], nd["
                            << this->getControlledNegativeNode() << "]; value=";

        *file << this->getAlias() << "]; na[" << this->getPositiveNode() << "], nb["
              << getNegativeNode() << "], nc[" << this->getControlledPositiveNode() << "], nd["
              << this->getControlledNegativeNode() << "]; value=";
        if (this->getValueType() == FLOAT) {
            if (d) cout << this->getFloatValue();
            *file << scientific << this->getFloatValue();
        }else {
            if (d) cout << this->getStringValue();
            *file << this->getStringValue();
        }

    }else{
        if (this->getElementType().compare("Q") == 0) {
            if (de)
                cout << "TJB\t[" << this->getAlias() << "]; nC" << this->getnC() << "], nB[" << this->getnB() << "] nE["
                     << this->getnE() << "]; value=";
            *file << "TJB\t[" << this->getAlias() << "]; nC" << this->getnC() << "], nB[" << this->getnB() << "] nE["
                  << this->getnE() << "]; value=";
            if (this->getValueType() == FLOAT) {
                if (d) cout << this->getFloatValue();
                *file << scientific << this->getFloatValue();
            }else {
                if (d) cout << this->getStringValue();
                *file << this->getStringValue();
            }
        } else if (this->getElementType().compare("M") == 0) {
            if (de)
                cout << "MOS\t[" << this->getAlias() << "]; nd[" << this->getnD() << "], ng[" << this->getnG()
                     << "] ns["
                     << this->getnS() << "]; value=";
            *file << "MOS\t[" << this->getAlias() << "]; nd[" << this->getnD() << "], ng[" << this->getnG() << "] ns["
                  << this->getnS() << "]; value=";
            if (this->getValueType() == FLOAT) {
                if (d) cout << this->getFloatValue();
                *file << scientific << this->getFloatValue();
            }else{
                if (d) cout << this->getStringValue();
                *file << this->getStringValue();
            }
        }
    }
}