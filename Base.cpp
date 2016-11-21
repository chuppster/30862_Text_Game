//
// Created by adria_000 on 11/20/2016.
//

#include "Base.h"

Base::Base(){}
Base::~Base(){}

std::string Base::getName(){
    return name;
}
std::string Base::getStatus(){
    return status;
}
std::string Base::getDescription(){
    return  description;
}
std::vector<std::string> Base::getTrigger(){
    return trigger;
}
void Base::setName(std::string _name){
    name = _name;
}
void Base::setStatus(std::string _status){
    status = _status;
}
void Base::setDescription(std::string _description){
    description = _description;
}
void Base::addTrigger(std::string _trigger){
    trigger.push_back(_trigger);
}
void Base::removeTrigger(std::string _trigger) {
    for (std::vector<std::string>::iterator it = trigger.begin() ; it != trigger.end(); ++it)
    {
        if (*it == _trigger)
        {
            trigger.erase(it);
        }
    }
}

void Base::printVec(std::vector<std::string> vec){
    for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end(); ++it)
        std::cout << *it<< ' ' ;
    std::cout << '\n';
}
