//
// Created by Adrian on 12/5/2016.
//

#ifndef INC_30862_TEXT_GAME_MAP_H
#define INC_30862_TEXT_GAME_MAP_H

#include <iostream>
#include <string>
#include "Room.h"
#include "rapidxml.hpp"
#include <sstream>
#include <vector>

using namespace std;
using namespace rapidxml;

class Map
{
private:
    vector<xml_node<>*> rooms;
    vector<xml_node<>*> items;
    vector<xml_node<>*> containers;
    vector<xml_node<>*> creatures;
public:
    vector<string> inventory;
    Room* getRoom(string name);
    vector<Room*> roomVec;
    vector<Item*> itemVec;
    vector<Container*> containVec;
    vector<Creature*> creatureVec;
    void printRoomObj();
    void node2obj();
    void build_map(xml_node<>* firstnode);
    void run();
    Map();
    virtual ~Map();
    vector<string> split(string &s, char delim);
    void readItem(string _name);
    void turnOnItem(string _name);
    void updateItem(string _item, string _status);
    bool checkCreatureTriggers(Room* _room);
    void pullTrigger(Base* _item);
    bool inventoryContains(string _item);
    Container* getContainer(string _cont);
    Creature* getCreature(string _creature);
    Item* getItemInv(string _item);
    Item* getItemCont(string _item, string _cont);
    Item* getItem(string _item);
    bool handleRoomTrig(Room* room, string input);
    void add(Item* _obj, Container* _cont);
    void del(string _obj);
    void removeFromInv(string _item);
    void checkContTriggers();
    void add(string _obj, string _room_or_container);
};





#endif //INC_30862_TEXT_GAME_MAP_H
