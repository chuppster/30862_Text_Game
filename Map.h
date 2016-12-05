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
public:
    vector<xml_node<>*> rooms;
    vector<xml_node<>*> items;
    vector<xml_node<>*> containers;
    vector<xml_node<>*> creatures;
    Map();
    virtual ~Map();
};

#endif //INC_30862_TEXT_GAME_MAP_H
