//
// Created by adria_000 on 11/20/2016.
//
#include "Container.h"

Container::Container(){}
Container::~Container(){}

vector<char*> Container::getItem(){
    return item;
}
vector<char*> Container::getAccept(){
    return accept;
}
void Container::removeItem(char* _item){
    for (std::vector<char*>::iterator it = item.begin() ; it != item.end(); ++it)
    {
        if (string(*it) == string(_item))
        {
            item.erase(it);
        }
    }
}
void Container::removeAccept(char* _item) {
    for (std::vector<char*>::iterator it = accept.begin(); it != accept.end(); ++it) {
        if (string(*it) == string(_item)) {
            accept.erase(it);
        }
    }
}
bool Container::isAccepted(string _item){
    for (std::vector<char*>::iterator it = accept.begin(); it != accept.end(); ++it) {
        if (string(*it) == _item) {
            return true;
        }
    }
    return false;
}
void Container::addItem(char* _item){
    item.push_back(_item);
}
void Container::addAccept(char* _item){
    accept.push_back(_item);
}
bool Container::contains(char *_item) {
    for(auto i = item.begin(); i != item.end(); i++)
    {
        if(string(*i) == string(_item))
        {
            return true;
        }
    }
    return false;
}