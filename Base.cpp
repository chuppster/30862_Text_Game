//
// Created by adria_000 on 11/20/2016.
//

#include "Base.h"

Base::Base(){}
Base::~Base(){}

std::string getName(){
    return name;
}
std::string getStatus(){
    return status;
}
std::string getDescription(){
    return  this.description;
}
std::vector<std::string> getTrigger(){
    return this.trigger;
}
void setName(std::string _name){
    this.name = _name;
}
void setStatus(std::string _status){
    this.status - _status;
}
void setDescription(std::string _description){
    this.description = _description;
}
void addTrigger(std::string _trigger){
    this.trigger.push_back(_trigger);
}
void removeTrigger(std::string _trigger) {
    int i = 0;
    while (this.trigger[i] != _trigger) {
        i++;
    }
    this.trigger.erase(i);
}

void printVec(std::vector vec){
    int i = 0;
    for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}
