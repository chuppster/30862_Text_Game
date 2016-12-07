//
// Created by adria_000 on 12/5/2016.
//

#include <string>
#include "Turnon.h"

Turnon::Turnon() {}
Turnon::~Turnon() {}

void Turnon::set(xml_node<>* node)
{
    xml_node<>* currnode = node->first_node();
    while(true)
    {
    if(string(currnode->name()) == string("print"))
    {
        print = currnode->value();
    }
    else if (string(currnode->name()) == string("action"))
    {
        action = currnode->value();
    }
    if(currnode->next_sibling() == NULL)
    {break;}
    currnode = currnode->next_sibling();
    }
}