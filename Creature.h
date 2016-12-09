//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_CREATURE_H
#define INC_30862_TEXT_GAME_CREATURE_H
#include <iostream>
#include <string>
#include <vector>
#include "Base.h"
#include "Attack.h"

using namespace std;

class Creature : public Base{
private:
    vector<char*> vulner;
    Attack* attack;
public:
    vector<char*> getVulner();
    void addVulner(char* _vulner);
    void removeVulner(char* _vulner);
    Attack* getAttack();
    void setAttack(xml_node<>* node);
    bool checkVulner(string weapon);

    Creature();
    virtual ~Creature();

};

#endif //INC_30862_TEXT_GAME_CREATURE_H
