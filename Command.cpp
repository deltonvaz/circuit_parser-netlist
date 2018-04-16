//
// Created by Delton on 13/04/18.
//

#include "Command.h"
#include <utility>

Command::Command(){
    this->type = COMMAND;
};

void Command::setCommand(String command){
    this->command = std::move(command);
};

string Command::getCommand(){
    return this->command;
};

void Command::setType(int t){
};

int Command::getType() {
    return COMMAND;
}

Command::~Command() {

}

