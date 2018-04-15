//
// Created by Delton on 12/04/18.
//

#include <cstring>
#include "Comment.h"

//    Comment::Comment(char *str)
//    {
//        strcat(str, "\0");
//        comment = str;
//    }

    Comment::Comment() {
        this->type = COMMENT;
        this->comment = "";
    }

    int Comment::getType() {
        return type;
    }

    void Comment::setType(int t){
        this->type = t;
    }

    string Comment::getComment()
    {
        return this->comment;
    }

    void Comment::setComment(String comment){
        this->comment = comment;
    }
