//
// Created by Delton on 13/04/18.
//

#include "Element.h"

    vector<string> Element::split(){
        const char *str = this->c;
        vector<string> result;
        do
        {
            const char *begin = str;
            while(*str != ' ' && *str)
                str++;
            result.emplace_back(begin, str);
        } while (0 != *str++);
        return result;
    }

    Element::Element(String &line, String type, vector<string> &result, LabelList &labels, ListaObj &lista, Elements e) {
        this->cPositiveN = this->cNegativeN = -1;
        if (e == FONTE_VCVS || e == FONTE_VCCS || e == FONTE_CCCS || e == FONTE_CCVS){
            this->setType(ELEMENT);
            this->setElementType(type);
            if (d) cout << line << endl;
            this->c = line.c_str();
            result = split();
            if (result.size() == 6) {
                this->setAlias(result[0].erase(0, 1));
                labels.insert(result[1]);
                labels.insert(result[2]);
                labels.insert(result[3]);
                labels.insert(result[4]);
                this->setPositiveNode(std::distance(labels.begin(), labels.find(result[1])));
                this->setNegativeNode(std::distance(labels.begin(), labels.find(result[2])));
                this->setControlledPositiveNode(std::distance(labels.begin(), labels.find(result[3])));
                this->setControlledNegativeNode(std::distance(labels.begin(), labels.find(result[4])));
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
                this->setAlias(result[0].erase(0, 1));
                labels.insert(result[1]);
                labels.insert(result[2]);
                labels.insert(result[3]);
                this->setnC(std::distance(labels.begin(), labels.find(result[1])));
                this->setnB(std::distance(labels.begin(), labels.find(result[2])));
                this->setnE(std::distance(labels.begin(), labels.find(result[3])));
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
                this->setAlias(result[0].erase(0, 1));
                labels.insert(result[1]);
                labels.insert(result[2]);
                labels.insert(result[3]);
                this->setnD(std::distance(labels.begin(), labels.find(result[1])));
                this->setnG(std::distance(labels.begin(), labels.find(result[2])));
                this->setnS(std::distance(labels.begin(), labels.find(result[3])));
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
                this->setAlias(result[0].erase(0, 1));
                labels.insert(result[1]);
                labels.insert(result[2]);
                this->setPositiveNode(std::distance(labels.begin(), labels.find(result[1])));
                this->setNegativeNode(std::distance(labels.begin(), labels.find(result[2])));
                this->setValue(result[3]);
                lista.push_back(this);
            }else {
                cerr << "invalid " << type << " type" << endl;
                exit(0);
            }


        }
    }
