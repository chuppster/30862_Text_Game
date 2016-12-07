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
    Trigger trigger;
public:
    std::string getName();
    std::string getStatus();
    std::string getDescription();
    Trigger getTrigger();
    void setName(std::string _name);
    void setStatus(std::string _status);
    void setDescription(std::string _description);
    void setTrigger(xml_node<>* node);
    void printVec(std::vector<std::string> vec);

    Base();
    virtual ~Base();

};
#endif //INC_30862_TEXT_GAME_BASE_H
