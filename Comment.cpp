//
// Created by dev on 12/04/18.
//

#include <cstring>
#include "Comment.h"

    Comment::Comment(char *str)
    {
        strcat(str, "\0");
        comment = str;
    }

    char* Comment::getComment()
    {
        return comment;
    }
