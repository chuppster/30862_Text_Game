//
// Created by adria_000 on 11/20/2016.
//

#include "Room.h"

Room::Room(){}
Room::~Room(){}

string Room::getType()
{
    return type;
}

std::vector<std::string> Room::getBorder()
{
    return border;
}
vector<Container> Room::getContainer()
{
    return container;
}
vector<Item> Room::getItem(){
    return item;
}
vector<Creature> Room::getCreature(){
    return creature;
}
void Room::setType(string _type){
    type = _type;
}
void Room::addBorder(std::string _border){
    border.push_back(_border);
}
void Room::addContainer(Container _container){
    container.push_back(_container);
}
void Room::addItem(Item _item){
    item.push_back(_item);
}
void Room::addCreature(Creature _creature){
    creature.push_back(_creature);
}
void Room::removeBorder(std::string _border){
    for (std::vector<std::string>::iterator it = border.begin() ; it != border.end(); ++it)
    {
        if (*it == _border)
        {
            border.erase(it);
        }
    }
}
void Room::removeContainer(Container _container){
    for (std::vector<Container>::iterator it = container.begin() ; it != container.end(); ++it)
    {
        if (((Container*)*it)->getName() == _container.getName())
        {
            container.erase(it);
        }
    }
}
void Room::removeItem(Item _item){
    for (std::vector<Item>::iterator it = item.begin() ; it != item.end(); ++it)
    {
        if (((Item*)*it)->getName() == _item.getName())
        {
            item.erase(it);
        }
    }
}
void Room::removeCreature(Creature _creature){
    for (std::vector<Creature>::iterator it = creature.begin() ; it != creature.end(); ++it)
    {
        if (((Creature*)*it)->getName() == _creature.getName())
        {
            creature.erase(it);
        }
    }
}

