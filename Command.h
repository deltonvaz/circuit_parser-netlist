//
// Created by Delton on 13/04/18.
//

#ifndef TOPICOSI_COMMAND_H
#define TOPICOSI_COMMAND_H

#include "Constants.h"
#include "Object.h"
#include "Matrix.h"
#include "Element.h"
#include "Parser.h"

class Command : public Object{
    private:
        String command;
    public:
        Command();
        ~Command();
        void setCommand(String command);
        string getCommand();

        Matrix generateResult(Parser* p, ofstream* outputFile);
        int getType() override;
        void setType(int t) override;




};


#endif //TOPICOSI_COMMAND_H