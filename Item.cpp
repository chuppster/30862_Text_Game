//
// Created by adria_000 on 11/20/2016.
//

#include "Item.h"

Item::Item() {}
Item::~Item(){}

void Item::setWriting(char* _writing){
    writing = _writing;
}
void Item::setTurn_on(xml_node<>* node){
    turn_on.set(node);
}
char* Item::getWriting(){
    return writing;
}
