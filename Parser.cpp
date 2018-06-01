//
// Created by delton on 30/05/18.
//

#include "Parser.h"
#include "Element.h"
#include "Comment.h"
#include "Command.h"
#include <algorithm>
#include <map>

set<string> ELEMENTTYPO{"R","C","L","V","I","D","E","F","G","H","Q","M"};

vector<string> Parser::split(string str){
    vector<string> result;
    std::istringstream iss(str);
    std::string token;
    while(iss >> token)
        result.push_back(token);
    return result;
}

bool checkVector(vector<string> el, string str){
    return std::find(el.begin(), el.end(), str) != el.end();
}

bool validElement(string str){
    return std::find(ELEMENTTYPO.begin(), ELEMENTTYPO.end(), str) != ELEMENTTYPO.end();
}

Object* parseElementType(char c, int lineCount){
    string s(1, toupper(c));
    if (c == '*')
        return new Comment();
    else if(validElement(s)) {
        Element* element = new Element();
        element->setElementType(s);
        return element;
    }
    else if(c == '.')
        return new Command();
    else{
        cout << "invalid parameter at line " << lineCount << endl;
        exit(1);
    }
}

int getVectorIndex(vector<string> vec, string str){
    ptrdiff_t pos = distance(vec.begin(), find(vec.begin(), vec.end(), str));
    return pos;
}

bool is_number(std::string src){
    std::stringstream ss;
    ss << src;
    double doub = 0;
    ss >> doub;
    if (ss){
        return true;
    }
    else{
        return false;
    }
}

value getValue(string v){
    value returnValue;
    if (!(is_number(v))) {
        returnValue.type = STRING;
        returnValue.stringValue = v;
        return returnValue;
    }
    else {
        returnValue.type = FLOAT;
        double temp = stod(v);
        returnValue.floatValue = stod(v);
        for (unsigned int i = 0; i < v.length(); ++i) {
            v[i] = tolower(v[i]);
        }
        if (v.size() > 3) {
            if ((v.substr(v.size() - 3) == "meg")) {
                string b = v.erase(v.size() - 3);
                returnValue.floatValue = std::stod(b);
                returnValue.floatValue = returnValue.floatValue * 10E5;
            }
        }
        switch (v.back()) {
            case 'k': {
                returnValue.floatValue = returnValue.floatValue * 10E2;
                break;
            }
            case 'm': {
                returnValue.floatValue = temp * 10E-4;
                break;
            }
            case 'f': {
                returnValue.floatValue = returnValue.floatValue * 10E-16;
                break;
            }
            case 'p': {
                returnValue.floatValue = returnValue.floatValue * 10E-13;
                break;
            }
            case 'n': {
                returnValue.floatValue = returnValue.floatValue * 10E-10;
                break;
            }
            case 'u': {
                returnValue.floatValue = returnValue.floatValue * 10E-7;
                break;
            }
            case 'g': {
                returnValue.floatValue = returnValue.floatValue * 10E8;
                break;
            }
            case 't': {
                returnValue.floatValue = returnValue.floatValue * 10E11;
                break;
            }
        }
        if (d) cout << returnValue.floatValue << endl;
        return returnValue;
    }
}

ListaObj* Parser::mapList(vector<string> lines, ofstream *file){
    std::cout.precision(6);

    vector<string> tokens, alias, node;

    ListaObj* objectList = new ListaObj;

    node.push_back("0"); //0 is unique for gnd

    int lineCount = 1;

    for (std::vector<String>::iterator it = lines.begin(); it != lines.end(); it++){
        tokens = this->split(*it); // generate tokens
        if (tokens.size() > 0) {
            auto obj = parseElementType(tokens[0].at(0), lineCount);
            if (obj->getType() == ELEMENT) {
                Element *element = (Element *) obj;
                value elementValue;
                string et = element->getElementType();
                //Setting the alias(string) => int if it doesnt exists
                if (!checkVector(alias, tokens[0]))
                    alias.push_back(tokens[0]);
                //Setting element alias
                element->setAlias(getVectorIndex(alias, tokens[0]));

                if((et.compare("R") == 0 | et.compare("C") == 0 | et.compare("L") == 0 | et.compare("V") == 0 | et.compare("I") == 0 | et.compare("D") == 0) && tokens.size() == 4){
                    for(int k = 1; k < 3; k++){
                        //setting the nodes(string) => int if it doesnt exists
                        if (!checkVector(node, tokens[k]))
                            node.push_back(tokens[k]);
                    }
                    element->setPositiveNode(getVectorIndex(node, tokens[1]));
                    element->setNegativeNode(getVectorIndex(node, tokens[2]));
                    elementValue = getValue(tokens[3]);
                    if(elementValue.type == FLOAT) {
                        element->setFloatValue(elementValue.floatValue);
                        element->setValueType(elementValue.type);
                    }else {
                        element->setStringValue(elementValue.stringValue);
                        element->setValueType(elementValue.type);
                    }

                    if (d) cout << "Elemento:" << element->getAlias() << " "
                         << element->getPositiveNode() << " " << element->getNegativeNode() << " ";

                    if(element->getValueType() == FLOAT) {
                        if (d) cout << scientific << element->getFloatValue() << endl;
                    }else
                        if (d) cout << element->getStringValue() << endl;

                }else if ((et.compare("Q") == 0) && tokens.size() == 5){
                    for(int k = 1; k < 4; k++){
                        //setting the nodes(string) => int if it doesnt exists
                        if (!checkVector(node, tokens[k]))
                            node.push_back(tokens[k]);
                    }
                    element->setnC(getVectorIndex(node, tokens[1]));
                    element->setnB(getVectorIndex(node, tokens[2]));
                    element->setnE(getVectorIndex(node, tokens[3]));
                    elementValue = getValue(tokens[4]);
                    if(elementValue.type == FLOAT) {
                        element->setFloatValue(elementValue.floatValue);
                        element->setValueType(elementValue.type);
                    }else {
                        element->setStringValue(elementValue.stringValue);
                        element->setValueType(elementValue.type);
                    }

                    if (d) cout << "Elemento:" << element->getAlias() << " "
                     << element->getnC() << " " << element->getnB() << " " << element->getnE() << " ";

                    if(element->getValueType() == FLOAT) {
                        if (d) cout << scientific << element->getFloatValue() << endl;
                    }else
                        if (d) cout << element->getStringValue() << endl;
                }else if ((et.compare("M") == 0) && tokens.size() == 5){
                    for(int k = 1; k < 4; k++){
                        //setting the nodes(string) => int if it doesnt exists
                        if (!checkVector(node, tokens[k]))
                            node.push_back(tokens[k]);
                    }
                    element->setnD(getVectorIndex(node, tokens[1]));
                    element->setnG(getVectorIndex(node, tokens[2]));
                    element->setnS(getVectorIndex(node, tokens[3]));
                    elementValue = getValue(tokens[4]);
                    if(elementValue.type == FLOAT) {
                        element->setFloatValue(elementValue.floatValue);
                        element->setValueType(elementValue.type);
                    }else {
                        element->setStringValue(elementValue.stringValue);
                        element->setValueType(elementValue.type);
                    }
                    if (d) cout << "Elemento:" << element->getAlias() << " "
                         << element->getnD() << " " << element->getnG() << " " << element->getnS() << " ";
                    if(element->getValueType() == FLOAT) {
                        if (d) cout << scientific << element->getFloatValue() << endl;
                    }else
                        if (d) cout << element->getStringValue() << endl;
                }else if ((et.compare("E") == 0 | et.compare("F") == 0 | et.compare("G") == 0 | et.compare("H") == 0) && tokens.size() == 6){
                    for(int k = 1; k < 5; k++){
                        //setting the nodes(string) => int if it doesnt exists
                        if (!checkVector(node, tokens[k]))
                            node.push_back(tokens[k]);
                    }
                    element->setPositiveNode(getVectorIndex(node, tokens[1]));
                    element->setNegativeNode(getVectorIndex(node, tokens[2]));
                    element->setControlledPositiveNode(getVectorIndex(node, tokens[3]));
                    element->setControlledNegativeNode(getVectorIndex(node, tokens[4]));
                    elementValue = getValue(tokens[5]);
                    if(elementValue.type == FLOAT) {
                        element->setFloatValue(elementValue.floatValue);
                        element->setValueType(elementValue.type);
                    }else {
                        element->setStringValue(elementValue.stringValue);
                        element->setValueType(elementValue.type);
                    }
                    if (d) cout << "Elemento:" << element->getAlias() << " "
                         << element->getPositiveNode() << " " << element->getNegativeNode()
                         << " " << element->getControlledPositiveNode()
                         << " " << element->getControlledNegativeNode()
                         << " ";
                    if(element->getValueType() == FLOAT) {
                        if (d) cout << scientific << element->getFloatValue() << endl;
                    }else
                        if (d) cout << element->getStringValue() << endl;
                }else{
                    cout << "invalid file" << endl;
                    exit(1);
                }
                objectList->push_back(element);
            }
        }
        lineCount++;
    }

    this->setAlias(alias);
    this->setNodes(node);
    return objectList;
}

const vector<string> &Parser::getAlias() const {
    return alias;
}

void Parser::setAlias(const vector<string> &alias) {
    Parser::alias = alias;
}

const vector<string> &Parser::getNodes() const {
    return nodes;
}

void Parser::setNodes(const vector<string> &node) {
    Parser::nodes = node;
}



