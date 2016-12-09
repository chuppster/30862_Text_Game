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
    vector<char*> item;
    vector<char*> accept;
public:
    vector<char*> getItem();
    vector<char*> getAccept();
    void removeItem(char* _item);
    void removeAccept(char* _item);
    bool isAccepted(char* _item);
    void addItem(char* _item);
    void addAccept(char* _item);
    bool contains(char* _item);

    Container();
    virtual ~Container();

};

#endif //INC_30862_TEXT_GAME_CONTAINER_H
