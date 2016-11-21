//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_ITEM_H
#define INC_30862_TEXT_GAME_ITEM_H
#include <iostream>
#include <string>
#include "Base.h"

using namespace std;

class Item : public Base{
private:
    string writing;
    string turn_on;
public:
    void setWriting(string _writing);
    void setTurn_on(string _turn_on);
    string getWriting();
    string getTurn_on();

    void Item();
    virtual void ~Item();

};

#endif //INC_30862_TEXT_GAME_ITEM_H
