//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_ITEM_H
#define INC_30862_TEXT_GAME_ITEM_H
#include <iostream>
#include "Base.h"
#include "Turnon.h"

using namespace std;

class Item : public Base{
private:
    char* writing;
    Turnon* turn_on;
public:
    void setWriting(char* _writing);
    void setTurn_on(xml_node<>* node);
    char* getWriting();
    Turnon* getTurnon();

    Item();
    virtual ~Item();

};

#endif //INC_30862_TEXT_GAME_ITEM_H
