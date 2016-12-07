//
// Created by adria_000 on 12/5/2016.
//

#include "Border.h"
#include <string>

Border::Border() {}
Border::~Border() {}

void Border::set(xml_node<> *node) {
    xml_node<>* currnode = node->first_node();
    while(true)
    {
        if(string(currnode->name()) == string("direction"))
        {
            direction = currnode->value();
        }
        else if (string(currnode->name()) == string("name"))
        {
            name = currnode->value();
        }
        if(currnode->next_sibling() == NULL)
        {break;}
        currnode = currnode->next_sibling();
    }
}