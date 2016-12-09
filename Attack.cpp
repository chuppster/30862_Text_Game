//
// Created by adria_000 on 12/8/2016.
//

#include <iostream>
#include "Attack.h"

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
            cout<<"Setup Condition"<<endl;

            cout<<"Made new Condition"<<endl;
            xml_node<>* subnode = currnode->first_node();
            while(true)
            {
                cout<<"Enter While for Condition"<<endl;
                if(string(subnode->name())== string("has"))
                {
                    cout<<"Has"<<endl;
                    condition.has = subnode->value();
                }
                else if(string(subnode->name())== string("object"))
                {
                    cout<<"Object"<<endl;
                    condition.object = subnode->value();
                }
                else if(string(subnode->name())== string("owner"))
                {
                    cout<<"Owner"<<endl;
                    condition.owner = subnode->value();
                }
                else if(string(subnode->name())== string("status"))
                {
                    cout<<"status"<<endl;
                    condition.status = subnode->value();
                }
                cout<<"Check Condition for NULL"<<endl;
                if(subnode->next_sibling() == NULL)
                {break;}
                subnode = subnode->next_sibling();
            }

        }
        cout<<"check for null"<<endl;
        if(currnode->next_sibling() == NULL)
        {break;}
        currnode = currnode->next_sibling();
    }
    //cout << currnode->name() << currnode->value() <<endl;
    cout<<"Finish setting up attack"<<endl;
}