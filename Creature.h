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
    vector<char*> vulner;
    char* attack;
public:
    vector<char*> getVulner();
    void addVulner(char* _vulner);
    void removeVulner(char* _vulner);
    char* getAttack();
    void setAttack(char* _attack);

    Creature();
    virtual ~Creature();

};

#endif //INC_30862_TEXT_GAME_CREATURE_H
