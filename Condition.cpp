//
// Created by adria_000 on 12/5/2016.
//

#include "Condition.h"
Condition::Condition() {}
Condition::~Condition() {}

void Condition::setup(xml_node<> *node) {
    xml_node<>* subnode = node->first_node();
    while(true)
    {
        cout<<"Enter While for Condition"<<endl;
        if(string(subnode->name())== string("has"))
        {
            cout<<"Has"<<endl;
            has = subnode->value();
        }
        else if(string(subnode->name())== string("object"))
        {
            cout<<"Object"<<endl;
            cout<<subnode->value()<<endl;
            cout<<"try to read object"<<endl;
            cout<<object<<endl;
            cout<<"Fisnish reading object"<<endl;
            object = subnode->value();
            cout<<"Set Object"<<endl;
        }
        else if(string(subnode->name())== string("owner"))
        {
            cout<<"Owner"<<endl;
            owner = subnode->value();
        }
        else if(string(subnode->name())== string("status"))
        {
            cout<<"status"<<endl;
            status = subnode->value();
        }
        cout<<"Check Condition for NULL"<<endl;
        if(subnode->next_sibling() == NULL)
        {break;}
        subnode = subnode->next_sibling();
    }
}