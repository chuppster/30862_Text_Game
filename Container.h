//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_CONTAINER_H
#define INC_30862_TEXT_GAME_CONTAINER_H
#include <iostream>
#include <string>
#include "Base.h"
#include "Item.h"

using namespace std;

class Container : public Base{
private:
    vector<Item> item;
    vector<Item> accept;
public:
    vector<Item> getItem();
    vector<Item> getAccept();
    void removeItem(Item _item);
    void removeAccept(Item _item);
    bool isAccepted(Item _item);
    void addItem(Item _item);
    void addAccept(Item _item);

    void Container();
    virtual void ~Container();

};

#endif //INC_30862_TEXT_GAME_CONTAINER_H
