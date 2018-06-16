//
// Created by delton on 30/05/18.
//

#ifndef TOPICOSI_PARSER_H
#define TOPICOSI_PARSER_H


#include "Constants.h"
#include "Element.h"

class Parser {
    public:
        vector<string> alias, nodes;
        ListaObj* objectList;

        Parser(vector<string> lines);


        ListaObj *getObjectList() const;

        void setObjectList(ListaObj* objectList);

        const vector<string> &getAlias() const;

        void setAlias(const vector<string> &alias);

        const vector<string> &getNodes() const;

        void setNodes(const vector<string> &node);

        ListaObj* mapList(vector<string> lines);

        vector<string> split(string str);

        bool checkVector(vector<string> el, string str);

        int getVectorIndex(vector<string> vec, string str);

        void checkGroupTwo();
};


#endif //TOPICOSI_PARSER_H
