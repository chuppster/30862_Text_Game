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

using namespace std;

class Room : public Base{
private:
    string type;
    std::vector<std::string> border;
    vector<Container> container;
    vector<Item> item;
    vector<Creature> creature;
public:
    string getType();
    std::vector<std::string> getBorder();
    vector<Container> getContainer();
    vector<Item> getItem();
    vector<Creature> getCreature();
    void setType(string _type);
    void addBorder(std::string _border);
    void addContainer(Container _container);
    void addItem(Item _item);
    void addCreature(Creature _creature);
    void removeBorder(std::string _border);
    void removeContainer(Container _container);
    void removeItem(Item _item);
    void removeCreature(Creature _creature);

    Room();
    virtual ~Room();
};

#endif //INC_30862_TEXT_GAME_ROOM_H
