//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_CREATURE_H
#define INC_30862_TEXT_GAME_CREATURE_H
#include <iostream>
#include <string>
#include <vector>
#include "Base.h"

using namespace std;

class Creature : public Base{
private:
    vector<string> vulner;
    string attack;
public:
    vector<string> getVulner();
    void addVulner(string _vulner);
    void removeVulner(string _vulner);
    string getAttack();
    void setAttack(string _attack);

    void Creature();
    virtual void ~Creature();

};

#endif //INC_30862_TEXT_GAME_CREATURE_H
