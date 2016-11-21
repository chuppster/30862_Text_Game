//
// Created by adria_000 on 11/20/2016.
//

#include "Creature.h"

Creature::Creature() {}
Creature::~Creature() {}

vector<string> Creature::getVulner(){
    return vulner;
}
void Creature::addVulner(string _vulner){
    vulner.push_back(_vulner);
}
void Creature::removeVulner(string _vulner){
    for (std::vector<std::string>::iterator it = vulner.begin() ; it != vulner.end(); ++it)
    {
        if (*it == _vulner)
        {
            vulner.erase(it);
        }
    }
}
string Creature::getAttack(){
    return attack;
}
void Creature::setAttack(string _attack){
    attack=_attack;
}