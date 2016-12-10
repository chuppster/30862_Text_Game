//
// Created by adria_000 on 11/20/2016.
//

#include "Creature.h"

Creature::Creature() {
    attack = new Attack;
}
Creature::~Creature() {}

vector<char*> Creature::getVulner(){
    return vulner;
}
void Creature::addVulner(char* _vulner){
    vulner.push_back(_vulner);
}
void Creature::removeVulner(char* _vulner){
    for (std::vector<char*>::iterator it = vulner.begin() ; it != vulner.end(); ++it)
    {
        if (*it == _vulner)
        {
            vulner.erase(it);
        }
    }
}
Attack* Creature::getAttack(){
    return attack;
}
void Creature::setAttack(xml_node<>* node){
    if(node == NULL)
    {
        attack = NULL;
    }
    else {
        attack = new Attack;
        attack->setup(node);
    }
}
bool Creature::checkVulner(string weapon) {
    for(unsigned int i = 0; i < vulner.size(); i++)
    {
        if(weapon == string(vulner.operator[](i)))
        {
            return true;
        }
    }
    return false;
}