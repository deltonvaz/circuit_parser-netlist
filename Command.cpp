//
// Created by dev on 13/04/18.
//

#include "Command.h"

//Command::Command(int command_type) : command_type(command_type) {}
//Command::Command(String command){
//    this->command = command;
//}

Command::Command(){
    this->type = COMMAND;
};

void Command::setCommand(String command){
    if (d) cout << "\nComando setado como:" << command;
    this->command = command;
};

string Command::getCommand(){
    return this->command;
};

void Command::setType(int t){
};

int Command::getType() {
    return COMMAND;
}

