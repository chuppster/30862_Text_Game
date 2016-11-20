//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_BASE_H
#define INC_30862_TEXT_GAME_BASE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base{
private:
    std::string name;
    std::string status;
    std::string description;
    std::vector<std::string> trigger;
public:
    std::string getName();
    std::string getStatus();
    std::string getDescription();
    std::vector<std::string> getTrigger();
    void setName(std::string _name);
    void setStatus(std::string _status);
    void setDescription(std::string _description);
    void addTrigger(std::string _trigger);
    void removeTrigger(std::string _trigger);
    void printVec(std::vector<std::string> vec);

    Base();
    virtual ~Base();

};
#endif //INC_30862_TEXT_GAME_BASE_H
