#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include "Constants.h"
#include "Comment.h"
#include "Command.h"
#include "Object.h"
#include "Element.h"
#include "Parser.h"
#include "Matrix.h"

typedef std::list<Object*> ListaObj;
typedef std::vector<string> StrVector;

bool checkExtension(String str);

int main(int argc, const char * argv[]) {
    StrVector lines; //Line of the file to be parsed
    ListaObj* elementList;
    if(testMatrix){
        /* Code part for matrix testing */
    }else {
        /* Open file */
        if (argc != 2) {
            cerr << "Invalid input usage, use [input].sp" << endl;
            exit(1);
        } else {
            if (!checkExtension(argv[1])) {
                cerr << "Invalid extension of netlist file" << endl;
                exit(1);
            }
            fileStd inputFileStream(argv[1], fstream::in);
            if (inputFileStream.is_open()) {
                if (d) cout << "File open... parsing\n";
                String line;
                getline(inputFileStream, line); // skip the first line
                while (getline(inputFileStream, line)) {
                    //istringstream iss(line);
                    lines.push_back(line);
                }
                inputFileStream.close();
            } else {
                cerr << "Unable to open file, use ./programName [input].sp\n";
                exit(1);
            };
        }

        /* Generate outputfile */
        String out("out");
        String fileName = argv[1];
        fileName.pop_back();
        fileName.pop_back(); // reconfigure outputfile
        ofstream outputFile(fileName + out);

        /* Parse file */
        Parser *prsr = new Parser(lines);
        //Check for group 2 elements
        prsr->checkGroupTwo();

        elementList = prsr->getObjectList();
        Command *command = new Command();

        int checkOp = 0;

        if (de) cout << "Lista encadeada de elementos:\n" << endl;
        outputFile << "Lista encadeada de elementos:\n" << endl;
        for (auto it = elementList->begin(); it != elementList->end(); ++it) {
            auto obj = *it;
            if (obj->getType() == ELEMENT) {
                Element *element = (Element *) obj;
                if (de) cout << "#" << distance(elementList->begin(), it) << ": ";
                outputFile << "#" << distance(elementList->begin(), it) << ": ";
                outputFile << *element;
                if (de) cout << endl;
                if(de) cout << *element;
            }else if(obj->getType() == COMMAND){
                command = (Command *) obj;
                if(command->getCommand().compare(".op") == 0){
                    checkOp = 1;
                    break;
                }
            }
        }

        /* Generate id no => alias*/
        vector<string> alias = prsr->getAlias();
        vector<string> nodes = prsr->getNodes();
        //cout << "\nVetor id do no => rotulo do no:\n" << endl;
        outputFile << "\nVetor id do no => rotulo do no:\n" << endl;
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            //std::cout << "No: " << distance(nodes.begin(), it) << ": " << *it << endl;
            outputFile << "No " << distance(nodes.begin(), it) << ": " << *it << endl;
        }

        /* Generate id alias => alias*/
        outputFile << "\nVetor id do rotulo => rotulo:\n" << endl;
        //cout << "\nVetor id do rotulo => rotulo::\n" << endl;
        for (auto it = alias.begin(); it != alias.end(); ++it) {
            //std::cout << "Rotulo: " << distance(alias.begin(), it) << ": " << *it << endl;
            outputFile << "Rotulo " << distance(alias.begin(), it) << ": " << *it << endl;
        }

        if(checkOp)
            command->generateResult(prsr, &outputFile);

        /*close file*/
        outputFile.close();
        cout << fileName + out + " generated!" << endl;

        return 0;
    }
}

bool checkExtension(String str){
    return str.substr(str.find_last_of(".") + 1) == "sp";
}


