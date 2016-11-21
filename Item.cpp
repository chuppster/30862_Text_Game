//
// Created by adria_000 on 11/20/2016.
//

#include "Item.h"

Item::Item() {}
Item::~Item(){}

void Item::setWriting(string _writing){
    writing = _writing;
}
void Item::setTurn_on(string _turn_on){
    turn_on = _turn_on;
}
string Item::getWriting(){
    return writing;
}
string Item::getTurn_on(){
    return turn_on;
}