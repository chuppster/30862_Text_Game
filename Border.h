//
// Created by adria_000 on 12/5/2016.
//

#ifndef INC_30862_TEXT_GAME_BORDER_H
#define INC_30862_TEXT_GAME_BORDER_H

#include "rapidxml.hpp"

using namespace rapidxml;
using namespace std;

class Border {
public:
    char* direction;
    char* name;
    Border();
    virtual ~Border();
    void set(xml_node<>* node);
};


#endif //INC_30862_TEXT_GAME_BORDER_H
