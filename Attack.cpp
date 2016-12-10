//
// Created by adria_000 on 12/8/2016.
//

#include <iostream>
#include "Attack.h"

Attack::Attack(){
    print = string("");
    condition = new Condition;
};
Attack::~Attack(){};

void Attack::setup(xml_node<>* node) {
    xml_node<>* currnode = node->first_node();
    while(true)
    {
        if(string(currnode->name()) == string("print"))
        {
            print = string(currnode->value());
        }
        else if(string(currnode->name()) == string("action"))
        {
            action.push_back(string(currnode->value()));
        }
        else if(string(currnode->name()) == string("condition"))
        {
            condition = new Condition;
            xml_node<>* subnode = currnode->first_node();
            while(true)
            {
                if(string(subnode->name())== string("has"))
                {
                    condition->has = subnode->value();
                }
                if(string(subnode->name())== string("object"))
                {
                    condition->object = subnode->value();
                }
                if(string(subnode->name())== string("owner"))
                {
                    condition->owner = subnode->value();
                }
                if(string(subnode->name())== string("status"))
                {
                    condition->status = subnode->value();
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