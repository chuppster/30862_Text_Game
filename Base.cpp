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
    if(node == NULL)
    {
        trigger = NULL;
    }
    else {
        trigger = new Trigger;
        trigger->setup(node);
    }
}
bool Base::hasTrigger() {
    if(trigger != NULL)
    {
        return true;
    }
    return false;
}
bool Base::checkTrigger(string _command) {
    if(trigger == NULL)
    { return false;}
    if(string(trigger->command) == _command)
    {
        return true;
    }
    return false;
}
void Base::delTrigger() {

}

