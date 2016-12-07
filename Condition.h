//
// Created by adria_000 on 12/5/2016.
//

#ifndef INC_30862_TEXT_GAME_CONDITION_H
#define INC_30862_TEXT_GAME_CONDITION_H


class Condition {
public:
    char* has;
    char* object;
    char* owner;
    char* status;
    Condition();
    virtual ~Condition();
};


#endif //INC_30862_TEXT_GAME_CONDITION_H
