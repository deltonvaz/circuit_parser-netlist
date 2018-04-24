#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <list>
#include <vector>
#include <set>
#include "Constants.h"
#include "Comment.h"
#include "Command.h"
#include "Object.h"
#include "Element.h"
typedef std::set<string> LabelList;
typedef std::list<Object*> ListaObj;
typedef std::vector<string> Result;

int main(int argc, const char * argv[]) {
    LabelList* nodeLabels = new LabelList();
    LabelList* labelsRotulo = new LabelList();
//    labelsRotulo->insert("0"); //initialize vector of labels
//    nodeLabels->insert("0"); //initialize vector of node labels
    ListaObj* lista = new ListaObj();
    Result* result = new Result();
    if (argc != 3) {
        cerr << "Invalid input usage, use [input] [output]" << endl;
        exit(1);
    }else{
        fileStd inputFileStream(argv[1], fstream::in);
        if(inputFileStream.is_open()){
            if (d) cout << "File open... parsing\n";
            string line, word, sts;
            int line_count = 0;
            getline(inputFileStream, line); // skip the first line
            while(getline(inputFileStream, line))
            {
                string token;
                const char * c;
                ++line_count;
                istringstream iss(line);
                if (d) cout << "\n" << line << "\n";
                if (d) cout << "\n" << line[0] << "\n";
                switch(line[0]) {
                    case '.':{
                        if (d) cout << "\ncomand l:[" << line_count << "]";
                        getline(iss, word);
                        auto * command = new Command();
                        command->setCommand(word);
                        command->setType(COMMAND);
                        lista->push_back(command);
                        break;
                    }
                    case '*': {
                        if (d) cout << "\ncomment l:[" << line_count << "]";
                        getline(iss, word);
                        auto * comment = new Comment();
                        comment->setComment(word);
                        comment->setType(COMMENT);
                        lista->push_back(comment);
                        break;
                    }
                    case 'R': {
                        if (d) cout << "\nresistor l:[" << line_count << "]";
                        auto *element = new Element(line, "RES", *result, *nodeLabels, *lista, RESISTOR, *labelsRotulo);
                        break;
                    }
                    case 'C': {
                        if (d) cout << "\ncapacitor l:[" << line_count << "]";
                        auto *element = new Element(line, "CAP", *result, *nodeLabels, *lista, CAPACITOR, *labelsRotulo);
                        break;
                    }
                    case 'L': {
                        if (d) cout << "\nindutor l:[" << line_count << "]";
                        auto *element = new Element(line, "IND", *result, *nodeLabels, *lista, INDUTOR, *labelsRotulo);
                        break;
                    }
                    case 'V':{
                        //if (d) cout << "\nvolt l:[" << line_count << "]";
                        auto *element = new Element(line, "VS", *result, *nodeLabels, *lista, FONTE_TENSAO, *labelsRotulo);
                        break;
                    }
                    case 'I':{
                        auto *element = new Element(line, "IS", *result, *nodeLabels, *lista, FONTE_CORRENTE, *labelsRotulo);
                        break;
                    }
                    case 'E':{
                        if (d) cout << "\nVCVS source:[" << line_count << "]" << endl;
                        auto *element = new Element(line, "VCVS", *result, *nodeLabels, *lista, FONTE_VCVS, *labelsRotulo);
                        break;
                    }
                    case 'F':{
                        if (d) cout << "\nCCCS source:[" << line_count << "]" << endl;
                        auto *element = new Element(line, "CCCS", *result, *nodeLabels, *lista, FONTE_CCCS, *labelsRotulo);
                        break;
                    }
                    case 'G':{
                        if (d) cout << "\nVCCS source:[" << line_count << "]" << endl;
                        auto *element = new Element(line, "VCCS", *result, *nodeLabels, *lista, FONTE_VCCS, *labelsRotulo);
                        break;
                    }
                    case 'H':{
                        if (d) cout << "\nCCVS source:[" << line_count << "]" << endl;
                        auto *element = new Element(line, "CCVS", *result, *nodeLabels, *lista, FONTE_CCVS, *labelsRotulo);
                        break;
                    }
                    case 'D':{
                        auto *element = new Element(line, "DIO", *result, *nodeLabels, *lista, DIODO, *labelsRotulo);
                        break;
                    }
                    case 'Q':{
                        auto *element = new Element(line, "TJB", *result, *nodeLabels, *lista, TJB, *labelsRotulo);
                        break;
                    }
                    case 'M':{
                        auto *element = new Element(line, "MOSFET", *result, *nodeLabels, *lista, MOSFET, *labelsRotulo);
                        break;
                    }
                    default:
                        if (d) cout << "\ndef l:[" << line_count << "]\n";
                        break;
                };
            }
            inputFileStream.close();
        } else cerr << "Unable to open file, use [input] [output] sintaxe\n";


    }

    string fileNameOutput;
    ofstream outputFile(argv[2]);



    int cont = 0;
    std::cout.precision(6);
    outputFile << "Lista encadeada de elementos:" << endl << endl;
    for(ListaObj::const_iterator iter = lista->begin(),
        endIter = lista->end();
        iter != endIter;
        ++iter)
    {
        Object *object = *iter;
        outputFile << "#" << cont << ": ";
        if (object->getType() == COMMAND){
            auto *command = (Command *) *iter;
            outputFile << "Command \t " << command->getCommand() << "\n";
        }
        else if (object->getType() == COMMENT){
            auto *comment = (Comment *) *iter;
            outputFile << "Comment \t " << comment->getComment() << "\n";
        }
        else if (object->getType() == ELEMENT){
            auto *element = (Element *) *iter;
            outputFile << "Element \t ";
            if(element->getElementType() == "VCVS" || element->getElementType() == "CCCS" || element->getElementType() == "VCCS" || element->getElementType() == "CCVS") {
                outputFile << element->getElementType() <<
                     "[" <<
                     element->getAlias() <<
                     "] \t ; na[" <<
                     element->getPositiveNode() <<
                     "], nb[" <<
                     element->getNegativeNode();
                    outputFile << "], nc[" << element->getControlledPositiveNode() <<
                         "], nd[" << element->getControlledNegativeNode();
            }else{
                outputFile << element->getElementType() <<
                     "[" <<
                     element->getAlias() <<
                     "] \t ; n+[" <<

                     element->getPositiveNode() <<
                     "], n-[" <<
                     element->getNegativeNode();
            }
            outputFile << "]; value=" << scientific << element->getValue() << endl;
        }
        cont++;
    }

    if(nodeLabels->size() > 0) {
        outputFile << "\nVetor id do no => rotulo do no: (size = " << nodeLabels->size() << "):" << endl;
        for (std::set<std::string>::iterator it = nodeLabels->begin(); it != nodeLabels->end(); ++it)
            outputFile << "No " << distance(nodeLabels->begin(), it) << " : " << *it << endl;
        outputFile << "\n";
    }

    if(labelsRotulo->size() > 0) {
        for (std::set<std::string>::iterator it = labelsRotulo->begin(); it != labelsRotulo->end(); ++it)
            outputFile << "Rotulo " << distance(labelsRotulo->cbegin(), it) << " : " << *it << endl;
        outputFile << "\n";
    }

    outputFile.close();


    //free memory
    delete(labelsRotulo);
    delete(nodeLabels);
    delete(lista);
    delete(result);

    return 0;
}


