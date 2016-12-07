//
// Created by adria_000 on 12/5/2016.
//

#ifndef INC_30862_TEXT_GAME_TURNON_H
#define INC_30862_TEXT_GAME_TURNON_H

#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Turnon {
public:
    Turnon();
    virtual ~Turnon();
    char* print;
    char* action;
    void set(xml_node<>* node);
};


#endif //INC_30862_TEXT_GAME_TURNON_H
