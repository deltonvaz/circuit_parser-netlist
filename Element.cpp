//
// Created by Delton on 13/04/18.
//

#include "Element.h"
vector<string> Element::split(){
    vector<string> result;
    std::istringstream iss(this->c);
    std::string token;
    while(iss >> token)
    {
        if (d) cout << token << endl;
        result.push_back(token);
    }
    return result;
}

Element::Element(String &line, String type, vector<string> &result, LabelList &nodeLabels, ListaObj &lista, Elements e, LabelList &labelsRotulo) {
        this->cPositiveN = this->cNegativeN = -1;
        nodeLabels.insert("0"); //initialize vector of node labels
        if (e == FONTE_VCVS || e == FONTE_VCCS || e == FONTE_CCCS || e == FONTE_CCVS){
            this->setType(ELEMENT);
            this->setElementType(type);
            if (d) cout << line << endl;
            this->c = line.c_str();
            result = split();
            if (result.size() == 6){
                labelsRotulo.insert(result[0]);
                this->setAlias(std::distance(labelsRotulo.begin(), labelsRotulo.find(result[0])));
                nodeLabels.insert(result[1]);
                nodeLabels.insert(result[2]);
                nodeLabels.insert(result[3]);
                nodeLabels.insert(result[4]);
                this->setPositiveNode(std::distance(nodeLabels.begin(), nodeLabels.find(result[1])));
                this->setNegativeNode(std::distance(nodeLabels.begin(), nodeLabels.find(result[2])));
                this->setControlledPositiveNode(std::distance(nodeLabels.begin(), nodeLabels.find(result[3])));
                this->setControlledNegativeNode(std::distance(nodeLabels.begin(), nodeLabels.find(result[4])));
                if (d) cout << result[5] << endl;
                this->setValue(result[5]);
                lista.push_back(this);
            }else {
                cerr << "invalid " << type << " type" << endl;
                exit(0);
            }
        }else if(e == TJB){
            this->setType(ELEMENT);
            this->setElementType(type);
            if (d) cout << line << endl;
            this->c = line.c_str();
            result = split();
            if(result.size() == 5){
                labelsRotulo.insert(result[0]);
                this->setAlias(std::distance(labelsRotulo.begin(), labelsRotulo.find(result[0])));
                nodeLabels.insert(result[1]);
                nodeLabels.insert(result[2]);
                nodeLabels.insert(result[3]);
                this->setnC(std::distance(nodeLabels.begin(), nodeLabels.find(result[1])));
                this->setnB(std::distance(nodeLabels.begin(), nodeLabels.find(result[2])));
                this->setnE(std::distance(nodeLabels.begin(), nodeLabels.find(result[3])));
                if (d) cout << result [4] << endl;
                this->setValue(result[4]);
                lista.push_back(this);
            }else{
                cerr << "invalid tbj argument";
                exit(0);
            }
        } else if(e ==MOSFET){
            this->setType(ELEMENT);
            this->setElementType(type);
            if (d) cout << line << endl;
            this->c = line.c_str();
            result = split();
            if(result.size() == 5) {
                labelsRotulo.insert(result[0]);
                this->setAlias(std::distance(labelsRotulo.begin(), labelsRotulo.find(result[0])));
                nodeLabels.insert(result[1]);
                nodeLabels.insert(result[2]);
                nodeLabels.insert(result[3]);
                this->setnD(std::distance(nodeLabels.begin(), nodeLabels.find(result[1])));
                this->setnG(std::distance(nodeLabels.begin(), nodeLabels.find(result[2])));
                this->setnS(std::distance(nodeLabels.begin(), nodeLabels.find(result[3])));
                if (d) cout << result[4] << endl;
                this->setValue(result[4]);
                lista.push_back(this);
            }else{
                cerr << "invalid mosfet argument";
                exit(0);
            }
        }
        else {
            this->setType(ELEMENT);
            this->setElementType(type);
            this->c = line.c_str();
            result = split();
            if (result.size() == 4) {
                //this->setAlias(result[0]);
                labelsRotulo.insert(result[0]);
                this->setAlias(std::distance(labelsRotulo.begin(), labelsRotulo.find(result[0])));
                nodeLabels.insert(result[1]);
                nodeLabels.insert(result[2]);
                this->setPositiveNode(std::distance(nodeLabels.begin(), nodeLabels.find(result[1])));
                this->setNegativeNode(std::distance(nodeLabels.begin(), nodeLabels.find(result[2])));
                this->setValue(result[3]);
                lista.push_back(this);
            }else {
                cerr << "invalid " << type << " type" << endl;
                exit(0);
            }


        }
    }
