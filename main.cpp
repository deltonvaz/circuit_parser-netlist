#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <list>
#include <vector>
#include "Constants.h"
#include "Comment.h"
#include "Command.h"
#include "Object.h"
#include "Element.h"

typedef std::list<Object*> ListaObj;

int word_count(string s) {
    int w = 0;
    int l = s.length();
    for(int i = 0; i < l; i++) {
        if ((s[i-1] == ' ' || s[i-1] == '\0') && (s[i] != ' ')) w++;
        if (s[i] == '\0') break;
    }
    return w;
}

int main(int argc, const char * argv[]) {

    typedef std::list<String*> LabelList;
    LabelList labels;
    ListaObj lista;
    vector<string> result;
    if (argc != 3) {
        cerr << "Invalid input usage, use [input] [output]" << endl;
        exit(1);
    }else{

//        for (int i = 0; i < 50; ++i)
//        {
//            list->add(rand() % 100);
//        }
//        list->print();
//        std::cout << "List Length: " << list->length << std::endl;
//        delete list;

        fileStd inputFileStream(argv[1], fstream::in);
        if(inputFileStream.is_open()){
            if (d) cout << "File open... parsing\n";
            string line, word, sts;
            int line_count = 0;
            getline(inputFileStream, line); // skip the first line
            while(getline(inputFileStream, line))
            {
                string token;
                ++line_count;
                istringstream iss(line);
                cout << "\n" << line << "\n";
                //split(result, line, is_any_of(" \t\n\v\f\r"), token_compress_on);
                switch(line[0]) {
                    case '.':{
                        if (d) cout << "\ncomand l:[" << line_count << "]";
                        getline(iss, word);
                        //Command command = new Command();
                        //command.setCommand(word);
                        auto * command = new Command();
                        command->setCommand(word);
                        cout << "\ncomando:" << word;
                        command->setType(COMMAND);
                        lista.push_back(command);
                        //lista->insert(command);
                        //list->add(command);
                        break;
                    }
                    case '*': {
                        if (d) cout << "\ncomment l:[" << line_count << "]";
                        auto * comment = new Comment();
                        lista.push_back(comment);
                        break;
                    }
                    case 'R': {
                        if (d) cout << "\nresistor l:[" << line_count << "]";
                        auto *element = new Element();
                        element->setType(ELEMENT);
                        lista.push_back(element);
                        break;
                    }
                    case 'C':
                        if (d) cout << "\ncapacitor l:[" << line_count << "]";

                        break;

                    case 'L':
                        if (d) cout << "\nindutor l:[" << line_count << "]";

                        break;
                    case 'V':{
                        auto *element = new Element();
                        element->setType(ELEMENT);
                        lista.push_back(element);
                    }
                    default:
                        if (d) cout << "\ndef l:[" << line_count << "]\n";
                        break;
                };

//                while (getline(iss, token, ' '))
//                {
//                    if (d) cout << "\n" << token << "\n";
//                }
//                std::istringstream lineStream(line);
//
//                String nameOfGame;
//                String leastFav;
//                String fav;
//                String bestCharacter;
//
//                std::getline(iss, leastFav, ' ');



                //cout << line[0] << "\n Linha completa: " << line << " | " << word_count(line);



                //cout << endl;
            }
        } else cerr << "Unable to open file, use [input] [output] sintaxe\n";
    }

    int cont = 1;
    for(ListaObj::const_iterator iter = lista.begin(),
        endIter = lista.end();
        iter != endIter;
        ++iter)
    {
        Object *object = *iter;
        cout << "#" << cont << ": ";
        if (object->getType() == COMMAND){
            auto *command = (Command *) *iter;
            //printf("\n Tipo: %d\n", command->getType());
            cout << "Command \t" << command->getCommand() << "\n";
        }
        else if (object->getType() == COMMENT){
            auto *comment = (Comment *) *iter;
            //printf("\n Tipo: %d\n", comment->getType());
            cout << "Comment \t" << comment->getComment() << "\n";
            //printf("\nAQUI: %s", command->getCommand());
        }
        else if (object->getType() == ELEMENT){
            auto *element = (Element *) *iter;
            printf("\n Tipo: %d\n", element->getType());
            //printf("\nAQUI: %s", command->getCommand());
        }

        cont++;
        //cout << "aqui!" << object->getType();
    }

    lista.clear();

    return 0;
}


