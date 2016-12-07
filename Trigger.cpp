//
// Created by adria_000 on 12/5/2016.
//

#include "Trigger.h"

Trigger::~Trigger(){};
Trigger::Trigger() {}

void Trigger::setup(xml_node<>* node)
{
    xml_node<>* currnode = node->first_node();
    while(true)
    {
        if(string(currnode->name()) == string("type"))
        {
            type = currnode->value();
        }
        if(string(currnode->name()) == string("command"))
        {
            command = currnode->value();
        }
        if(string(currnode->name()) == string("print"))
        {
            print = currnode->value();
        }
        if(string(currnode->name()) == string("action"))
        {
            action = currnode->value();
        }
        if(string(currnode->name()) == string("condition"))
        {
            xml_node<>* subnode = currnode->first_node();
            while(true)
            {
                if(string(subnode->name())== string("has"))
                {
                    condition.has = subnode->value();
                }
                if(string(subnode->name())== string("object"))
                {
                    condition.object = subnode->value();
                }
                if(string(subnode->name())== string("owner"))
                {
                    condition.owner = subnode->value();
                }
                if(string(subnode->name())== string("status"))
                {
                    condition.status = subnode->value();
                }
                if(subnode->next_sibling() == NULL)
                {break;}
                subnode = subnode->next_sibling();
            }

        }
        if(currnode->next_sibling() == NULL)
        {break;}
        currnode = currnode->next_sibling();
    }
    //cout << currnode->name() << currnode->value() <<endl;
}