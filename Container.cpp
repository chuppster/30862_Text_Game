//
// Created by adria_000 on 11/20/2016.
//
#include "Container.h"

Container::Container(){}
Container::~Container(){}

vector<Item> Container::getItem(){
    return item;
}
vector<Item> Container::getAccept(){
    return accept;
}
void Container::removeItem(Item _item){
    for (std::vector<Item>::iterator it = item.begin() ; it != item.end(); ++it)
    {
        if ((it)->getName() == _item.getName())
        {
            item.erase(it);
        }
    }
}
void Container::removeAccept(Item _item) {
    for (std::vector<Item>::iterator it = accept.begin(); it != accept.end(); ++it) {
        if ((it)->getName() == _item.getName()) {
            accept.erase(it);
        }
    }
}
bool Container::isAccepted(Item _item){
    for (std::vector<Item>::iterator it = accept.begin(); it != accept.end(); ++it) {
        if ((it)->getName() == _item.getName()) {
            return true;
        }
    }
    return false;
}

void Container::addItem(Item _item){
    item.push_back(_item);
}
void Container::addAccept(Item _item){
    accept.push_back(_item);
}