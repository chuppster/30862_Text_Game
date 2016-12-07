//
// Created by adria_000 on 11/20/2016.
//

#include "Creature.h"

Creature::Creature() {}
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
char* Creature::getAttack(){
    return attack;
}
void Creature::setAttack(char* _attack){
    attack=_attack;
}