//
// Created by Delton on 12/04/18.
//

#include <string>
#include "Object.h"

#ifndef TOPICOSI_COMMENT_H
#define TOPICOSI_COMMENT_H


class Comment : public Object{
private:
    string comment;
    int type;

public:
    int getType() override;
    void setType(int t) override;
    void setComment(String comment);
    string getComment();
    Comment();
    ~Comment();

};


#endif //TOPICOSI_COMMENT_H