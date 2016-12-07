//
// Created by adria_000 on 11/20/2016.
//

#include "Room.h"

Room::Room(){}
Room::~Room(){}

string Room::getBorderRoom(string dir)
{
    for(unsigned int i = 0; i < border.size(); i++)
    {
        if(dir == "n")
        {
            if(border.operator[](i)->direction == "north")
            {
                return string(border.operator[](i)->name);
            }
        }
        if(dir == "s")
        {
            if(border.operator[](i)->direction == "south")
            {
                return string(border.operator[](i)->name);
            }
        }
        if(dir == "e")
        {
            if(border.operator[](i)->direction == "east")
            {
                return string(border.operator[](i)->name);
            }
        }
        if(dir == "w")
        {
            if(border.operator[](i)->direction == "west")
            {
                return string(border.operator[](i)->name);
            }
        }
    }

    return string("");
}

void Room::pullTrigger(){
    getTrigger()->printTrigger();
    if(string(getTrigger()->type) != ("permanent"))
    {
        removeTrigger();
    }
}

bool Room::checkTrigger(string _command)
{
    if(string(getTrigger()->command) == _command)
    {
        return true;
    }
    return false;
}

char* Room::getType()
{
    return type;
}

vector<Border*> Room::getBorder()
{
    return border;
}
vector<char*> Room::getContainer()
{
    return container;
}
vector<char*> Room::getItem(){
    return item;
}
vector<char*> Room::getCreature(){
    return creature;
}
void Room::setType(char* _type){
    type = _type;
}
void Room::addBorder(xml_node<>* node){
    Border* currborder = new Border;
    currborder->set(node);
    border.push_back(currborder);
}
void Room::addContainer(char* _container){
    container.push_back(_container);
}
void Room::addItem(char* _item){
    item.push_back(_item);
}
void Room::addCreature(char* _creature){
    creature.push_back(_creature);
}

void Room::removeContainer(char* _container){
    for (std::vector<char*>::iterator it = container.begin() ; it != container.end(); ++it)
    {
        if (string(*it) == string(_container))
        {
            container.erase(it);
        }
    }
}
void Room::removeItem(char* _item){
    for (std::vector<char*>::iterator it = item.begin() ; it != item.end(); ++it)
    {
        if (string(*it) == string(_item))
        {
            item.erase(it);
        }
    }
}
void Room::removeCreature(char* _creature){
    for (std::vector<char*>::iterator it = creature.begin() ; it != creature.end(); ++it)
    {
        if (string(*it) == string(_creature))
        {
            creature.erase(it);
        }
    }
}

