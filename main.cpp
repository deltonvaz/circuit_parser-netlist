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
    LabelList* labels = new LabelList();
    labels->insert("0"); //initialize vector
    ListaObj* lista = new ListaObj();
    Result* result = new Result();
    if (argc != 2) {
        cerr << "Invalid input usage, use [input]" << endl;
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
                        auto *element = new Element(line, "RES", *result, *labels, *lista, RESISTOR);
                        break;
                    }
                    case 'C': {
                        if (d) cout << "\ncapacitor l:[" << line_count << "]";
                        auto *element = new Element(line, "CAP", *result, *labels, *lista, CAPACITOR);
                        break;
                    }
                    case 'L': {
                        if (d) cout << "\nindutor l:[" << line_count << "]";
                        auto *element = new Element(line, "IND", *result, *labels, *lista, INDUTOR);
                        break;
                    }
                    case 'V':{
                        auto *element = new Element(line, "VSR", *result, *labels, *lista, FONTE_TENSAO);
                        break;
                    }
                    case 'I':{
                        auto *element = new Element(line, "ISR", *result, *labels, *lista, FONTE_CORRENTE);
                        break;
                    }
                    case 'E':{
                        if (d) cout << "\nVCVS source:[" << line_count << "]" << endl;
                        auto *element = new Element(line, "VCVS", *result, *labels, *lista, FONTE_VCVS);
                        break;
                    }
                    case 'F':{
                        if (d) cout << "\nCCCS source:[" << line_count << "]" << endl;
                        auto *element = new Element(line, "CCCS", *result, *labels, *lista, FONTE_CCCS);
                        break;
                    }
                    case 'G':{
                        if (d) cout << "\nVCCS source:[" << line_count << "]" << endl;
                        auto *element = new Element(line, "VCCS", *result, *labels, *lista, FONTE_VCCS);
                        break;
                    }
                    case 'H':{
                        if (d) cout << "\nCCVS source:[" << line_count << "]" << endl;
                        auto *element = new Element(line, "CCVS", *result, *labels, *lista, FONTE_CCVS);
                        break;
                    }
                    case 'D':{
                        auto *element = new Element(line, "DIO", *result, *labels, *lista, DIODO);
                        break;
                    }
                    case 'Q':{
                        auto *element = new Element(line, "TJB", *result, *labels, *lista, TJB);
                        break;
                    }
                    case 'M':{
                        auto *element = new Element(line, "MOSFET", *result, *labels, *lista, MOSFET);
                        break;
                    }
                    default:
                        if (d) cout << "\ndef l:[" << line_count << "]\n";
                        break;
                };
            }
        } else cerr << "Unable to open file, use [input] [output] sintaxe\n";
    }

    int cont = 1;
    std::cout.precision(2);
    for(ListaObj::const_iterator iter = lista->begin(),
        endIter = lista->end();
        iter != endIter;
        ++iter)
    {
        Object *object = *iter;
        cout << "#" << cont << ": ";
        if (object->getType() == COMMAND){
            auto *command = (Command *) *iter;
            cout << "Command \t" << command->getCommand() << "\n";
        }
        else if (object->getType() == COMMENT){
            auto *comment = (Comment *) *iter;
            cout << "Comment \t" << comment->getComment() << "\n";
        }
        else if (object->getType() == ELEMENT){
            auto *element = (Element *) *iter;
            cout << "Element \t" <<
                 element->getElementType() <<
                 "[" <<
                 element->getAlias() <<
                 "]\t; n+[" <<
                 element->getPositiveNode() <<
                 "], n-[" <<
                 element->getNegativeNode();
                 if (element->getControlledPositiveNode() != -1 && element->getControlledNegativeNode() != -1) {
                     cout << "], nC+[" << element->getControlledPositiveNode() <<
                     "], nC-[" << element->getControlledNegativeNode();
                 }
                 cout << "]; value=" << element->getValue() << scientific << endl;
        }
        cont++;
    }

    std::cout<<"\nLabel list (size = " << labels->size() << "):" << endl ;
    for (std::set<std::string>::iterator it=labels->begin(); it!=labels->end(); ++it)
        std::cout << distance(labels->begin(), it)  << " : "  << *it << endl;
    std::cout<<"\n";

    //free memory
    delete(labels);
    delete(lista);
    delete(result);

    return 0;
}


