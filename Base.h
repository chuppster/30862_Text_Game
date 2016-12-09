//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_BASE_H
#define INC_30862_TEXT_GAME_BASE_H
#include <iostream>
#include <string>
#include <vector>
#include "Trigger.h"
using namespace rapidxml;
using namespace std;

class Base{
private:
    std::string name;
    std::string status;
    std::string description;
    Trigger* trigger;
    bool alive;
public:
    void revive();
    void removeTrigger();
    void printDesc();
    std::string getName();
    std::string getStatus();
    std::string getDescription();
    bool exists();
    Trigger* getTrigger();
    void setName(std::string _name);
    void setStatus(std::string _status);
    void setDescription(std::string _description);
    void setTrigger(xml_node<>* node);
    bool checkTrigger(string _command);
    void delTrigger();
    bool hasTrigger();
    void del();
    Base();
    virtual ~Base();
};
#endif //INC_30862_TEXT_GAME_BASE_H
