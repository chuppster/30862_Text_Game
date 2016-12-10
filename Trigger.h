//
// Created by Adrian on 12/5/2016.
//

#ifndef INC_30862_TEXT_GAME_TRIGGER_H
#define INC_30862_TEXT_GAME_TRIGGER_H
#include <iostream>
#include <string>
#include "rapidxml.hpp"
#include "Condition.h"

using namespace std;
using namespace rapidxml;
class Trigger
{
public:
    char* type;
    char* command;
    char* print;
    char* action;
    bool used;
    Condition* condition;

    Trigger();
    virtual ~Trigger();
    void setup(xml_node<>* node);
    void printTrigger();
    void use();
    Condition* getCondition();

};

#endif //INC_30862_TEXT_GAME_TRIGGER_H
