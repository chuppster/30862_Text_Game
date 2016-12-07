//
// Created by Adrian on 12/5/2016.
//

#ifndef INC_30862_TEXT_GAME_MAP_H
#define INC_30862_TEXT_GAME_MAP_H

#include <iostream>
#include <string>
#include "Room.h"
#include "rapidxml.hpp"

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
};



#endif //INC_30862_TEXT_GAME_MAP_H
