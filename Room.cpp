//
// Created by adria_000 on 11/20/2016.
//

#include "Room.h"

Room::Room(){}
Room::~Room(){}

string Room::getBorderRoom(string dir) {
    for(unsigned int i = 0; i < border.size(); i++)
    {
        if(dir == "n")
        {
            if(string(border.operator[](i)->direction) == string("north"))
            {
                return string(border.operator[](i)->name);
            }
        }
        if(dir == "s")
        {
            if(string(border.operator[](i)->direction) == string("south"))
            {
                return string(border.operator[](i)->name);
            }
        }
        if(dir == "e")
        {
            if(string(border.operator[](i)->direction) == string("east"))
            {
                return string(border.operator[](i)->name);
            }
        }
        if(dir == "w")
        {
            if(string(border.operator[](i)->direction) == string("west"))
            {
                return string(border.operator[](i)->name);
            }
        }
    }

    return string("");
}
bool Room::hasItem(string _item) {
    for(unsigned int i = 0;i<item.size();i++)
    {
        if(string(item.operator[](i)) == _item)
        {return true;}
    }
    return false;
}
char* Room::getType() {
    return type;
}
vector<Border*> Room::getBorder() {
    return border;
}
vector<char*> Room::getContainer() {
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
void Room::removeItem(string _item){
    vector<char*>::iterator i = find(item.begin(), item.end(), (char*)_item.c_str());
    if(i != item.end())
    {
        item.erase(i);
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
bool Room::containsCreature(string _creature) {
    if(_creature == "")
    {
        return false;
    }
    for(auto i = creature.begin(); i != creature.end(); ++i)
    {
        if(string(*i) == _creature)
        {
            return true;
        }
    }
    return false;
}

