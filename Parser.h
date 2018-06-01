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

        const vector<string> &getAlias() const;

        void setAlias(const vector<string> &alias);

        const vector<string> &getNodes() const;

        void setNodes(const vector<string> &node);

        ListaObj* mapList(vector<string> lines, ofstream *file);

        vector<string> split(string str);

};


#endif //TOPICOSI_PARSER_H
