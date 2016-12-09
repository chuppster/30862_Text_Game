//
// Created by adria_000 on 12/8/2016.
//

#ifndef INC_30862_TEXT_GAME_ATTACK_H
#define INC_30862_TEXT_GAME_ATTACK_H


#include "Condition.h"
#include "rapidxml.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace rapidxml;

class Attack {
public:
    Condition condition;
    string print;
    vector<string> action;

    void setup(xml_node<>* node);

};


#endif //INC_30862_TEXT_GAME_ATTACK_H
