//
// Created by dev on 13/04/18.
//

#ifndef TOPICOSI_COMMAND_H
#define TOPICOSI_COMMAND_H

#include "Constants.h"
#include "Object.h"

class Command : public Object{
    private:
        String command;
        int type;
    public:
        Command();
        ~Command();
        //Command(String command);
        void setCommand(String command);
        string getCommand();
        int getType();
        void setType(int t);




};


#endif //TOPICOSI_COMMAND_H