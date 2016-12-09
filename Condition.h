//
// Created by adria_000 on 12/5/2016.
//

#ifndef INC_30862_TEXT_GAME_CONDITION_H
#define INC_30862_TEXT_GAME_CONDITION_H
#include<string>
#include "rapidxml.hpp"
#include <iostream>

using namespace std;
using namespace rapidxml;

class Condition {
public:
    char* has;
    char* object;
    char* owner;
    char* status;
    Condition();
    virtual ~Condition();

    void setup(xml_node<>* node);
};



#endif //INC_30862_TEXT_GAME_CONDITION_H
