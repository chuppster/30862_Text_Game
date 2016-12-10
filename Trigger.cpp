#include "Trigger.h"

Trigger::~Trigger(){};
Trigger::Trigger() {
    used = false;
    type = (char*)("normal");
    command = (char*)("");
    print = (char*)("");
    action = (char*)("");}
void Trigger::use() {
    if(string(type) != string("permanent"))
    {
        used = true;
    }
}
void Trigger::printTrigger() {
    cout<<print<<endl;
}
void Trigger::setup(xml_node<>* node) {
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
Condition* Trigger::getCondition() {
    return condition;
}