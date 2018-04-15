#include <iostream>
#include <fstream>
#include <sstream>
#include "Comment.h"

using String = std::string;

int main(int argc, const char * argv[]) {
    Comment teste("um teste bem louco");


    printf("%s\n",teste.getComment());
    printf("%d \n", argc);
    printf("%s \n", argv[2]);
    std::cout << "Hello, World!" << std::endl;
//
//    std::cout << "filename: ";
//    std::string file_name;
//    std::cin >> file_name;
//
//    //open a file copy.out for input
//    std::ifstream inFile(file_name.c_str() );
//
//    if (! inFile)
//    {
//        std::cerr << "unable to open input file: "
//             << file_name << " --bailing out! \n";
//        return -1;
//    }
//
//    char ch;
//    while (inFile.get(ch))
//        std::cout.put(ch);
//
//    return 0;


    std::ifstream inputFileStream("teste");
    if (inputFileStream.is_open()){
        int count;
        inputFileStream>>count;
        inputFileStream.ignore(1, '\n'); //ignore first line cuz it's a comment

        for(int i = 0; i < count; i++)
        {
            String line;
            std::getline(inputFileStream, line);

            std::istringstream lineStream(line);

            String nameOfGame;
            String leastFav;
            String fav;
            String bestCharacter;

            std::getline(lineStream, leastFav, '|');
            std::getline(lineStream, nameOfGame, '|');
            std::getline(lineStream, fav, '|');
            std::getline(lineStream, bestCharacter, '|');

            std::cout<< leastFav <<"\n"<<nameOfGame<<"\n"<<fav<<"\n"<<bestCharacter<<"\n\n";
        };
    } else std::cout << "Unable to open file";




    return 0;

}