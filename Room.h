//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_ROOM_H
#define INC_30862_TEXT_GAME_ROOM_H

#include <iostream>
#include <string>
#include "Base.h"
#include "Creature.h"
#include "Item.h"
#include "Container.h"
#include "Border.h"

using namespace std;

class Room : public Base{
private:
    string type;
    std::vector<Border*> border;
    vector<char*> container;
    vector<char*> item;
    vector<char*> creature;
public:
    string getType();
    vector<Border*> getBorder();
    vector<char*> getContainer();
    vector<char*> getItem();
    vector<char*> getCreature();
    void setType(string _type);
    void addBorder(xml_node<>* node);
    void addContainer(char* _container);
    void addItem(char* _item);
    void addCreature(char* _creature);
    void removeContainer(char* _container);
    void removeItem(char* _item);
    void removeCreature(char* _creature);

    Room();
    virtual ~Room();
};

#endif //INC_30862_TEXT_GAME_ROOM_H
