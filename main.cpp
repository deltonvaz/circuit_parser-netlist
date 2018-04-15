#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <list>
#include "Constants.h"
#include "Comment.h"
#include "Command.h"
#include "Object.h"

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
    typedef std::list<Object*> ListaObj;
    ListaObj lista;
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
                ++line_count;
                istringstream iss(line);


//                std::istringstream lineStream(line);
//
//                String nameOfGame;
//                String leastFav;
//                String fav;
//                String bestCharacter;
//
//                std::getline(iss, leastFav, ' ');

                switch(line[0]) {
                    case '.':
                        if (d) cout << "\ncomand l:[" << line_count << "]";
                        getline(iss, word);
                        cout << word << "AAAAAAAAAAAAA";
                        //Command command = new Command();
                        //command.setCommand(word);
                        //Command* command = new Command();
                        lista.push_back(new Command(10));
                        //lista->insert(command);
                        //list->add(command);
                        break;

                    case '*':
                        if (d) cout << "\ncomment l:[" << line_count << "]";
                        lista.push_back(new Comment(50));
                        break;

                    case 'R':
                        if (d) cout << "\nresistor l:[" << line_count << "]";

                        break;

                    case 'C':
                        if (d) cout << "\ncapacitor l:[" << line_count << "]";

                        break;

                    case 'L':
                        if (d) cout << "\nindutor l:[" << line_count << "]";

                        break;
                    default: break;
                };

                //cout << line[0] << "\n Linha completa: " << line << " | " << word_count(line);

                string token;


                while (getline(iss, token, ' '))
                {

                    if (token[0] == 'V'){
                        if (d) cout << "\nFonte de tensao";

                    }

                    // process each token
                    //cout << token << " ";
                }
                //cout << endl;
            }
        } else cerr << "Unable to open file, use [input] [output] sintaxe\n";
    }

    for(ListaObj::const_iterator iter = lista.begin(),
        endIter = lista.end();
        iter != endIter;
        ++iter)
    {
        Object *object = *iter;
        printf("\nAQUI: %d", object->getType());
        //cout << "aqui!" << object->getType();
    }

    return 0;
}

