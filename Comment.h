//
// Created by dev on 12/04/18.
//

#include <string>

#define MAX_CHAR 5000
#ifndef TOPICOSI_COMMENT_H
#define TOPICOSI_COMMENT_H


class Comment {
private:
    char *comment;

public:
    Comment(char *str);
    char* getComment();

};


#endif //TOPICOSI_COMMENT_H
