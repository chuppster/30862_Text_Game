//
// Created by adria_000 on 11/20/2016.
//

#include "Base.h"

Base::Base(){}
Base::~Base(){}

void Base::removeTrigger()
{
    this->trigger = NULL;
}

void Base::printDesc() {
    cout << description << endl;
}

std::string Base::getName(){
    return name;
}
std::string Base::getStatus(){
    return status;
}
std::string Base::getDescription(){
    return  description;
}
Trigger* Base::getTrigger(){
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
void Base::setTrigger(xml_node<>* node){
    trigger = new Trigger;
    trigger->setup(node);
}

