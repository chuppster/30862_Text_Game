//
// Created by Adrian on 12/5/2016.
//

#include <cstring>
#include "Map.h"

Map::Map(){}
Map::~Map(){}

void Map::printRoomObj() {
    cout << "Printing rooms based on objects:" << endl;
    for(unsigned int i=0; i < rooms.size(); i++)
    {
        cout << rooms.operator[](i)->name() << ", ";
    }
    cout << endl;
}

void Map::run()
{

    bool exit = false;
    Room* room;
    string in1;
    string input;
    string border_room;
    vector<string> input_vec;
    string curritem;

    unsigned int i;//finding the entrance
    room = getRoom(string("Entrance"));
    room->printDesc();//print the description of the entrance
    bool triggered = false;
    while(exit == false)//let's loop until we exit
    {
        getline(cin, input);
        if(input != string("")) {
            input_vec = split(input, ' ');
            //cout<<input_vec.operator[](0);
            in1 = input_vec.operator[](0);
        }
        //cout<<"ROOM: "<<room->getName()<<" BORDER 1: " << room->getBorder().operator[](0)->name << endl;

        checkCreatureTriggers(room);

        if(in1 == string("n") || in1 == string("s") || in1 == string("e") || in1 == string("w"))
        {
            triggered = handleRoomTrig(room, in1);
            border_room = room->getBorderRoom(in1);//gets you the name of the room in that direction
            //cout<<"================BORDER ROOM========="<<border_room<<endl;
            if(!triggered){
                if(border_room == string(""))//if you can't find the room
                {
                    cout<<"Can't go that way."<<endl;
                }
                else
                {//if you can, move to the next room
                    room = getRoom(border_room);
                    cout << room->getDescription() << endl;
                }
            }
        }
        else if(in1 == string("i"))
        {
            cout << "Inventory: ";
            if(inventory.size() == 0)
            {
                cout << "empty" << endl;
            }
            else
            {
                for(auto i = inventory.begin(); i != inventory.end(); ++i)
                {cout << *i << ", ";}
                cout<<endl;
            }
        }
        else if(in1 == string("take"))//take command
        {
            curritem=input_vec.operator[](1);
            for(i=0;i<itemVec.size();i++)
            {
               if(itemVec.operator[](i)->getName() == curritem)
               {
                   if(room->hasItem(curritem)){
                       inventory.push_back(curritem);
                       room->removeItem(curritem);
                       cout<<"Item "<<curritem<<" added to inventory"<<endl;
                   }
               }
            }
        }
        else if(in1 == string("read"))//read command
        {
            curritem=input_vec.operator[](1);
            for(auto a = inventory.begin(); a != inventory.end(); ++a)
            {
                if(*a == curritem)
                {
                    readItem(curritem);
                }
            }
        }
        else if(in1 == string("turn"))//read command
        {
            curritem=input_vec.operator[](2);
            for(auto a = inventory.begin(); a != inventory.end(); ++a)
            {
                if(*a == curritem)
                {
                    turnOnItem(curritem);
                }
            }
        }
        else if(in1 == string("exit"))
        {exit = true;}
        else {
            if (in1 != string("")) {
            cout << "Error" << endl;
            }
        }
    }


}
bool Map::handleRoomTrig(Room* room, string input){
    bool triggered = false;
    if(room->checkTrigger(input) == false)//if there isn't a trigger for the given input, return false
    {
        return false;
    }
    //cout<<"found a trigger"<<endl;
    //need to check condiditon
    Condition* cond = room->getTrigger()->condition;
    if(string(cond->has) == string("no"))
    {
        //cout<<"Trigger with a (NO) condition"<<endl;
        if(string(cond->owner) == string("inventory")) {
            if (!inventoryContains(string(cond->object)))
            {
                triggered = true;
            }
        }
        else
        {
            Container* curr = getContainer(cond->owner);
            if(!curr->contains(cond->object))
            {
                triggered = true;
            }
        }
    }
    else if(string(cond->has) == string("yes"))
    {
        if(string(cond->owner) == string("inventory")) {
            if (inventoryContains(string(cond->object)))
            {
                triggered = true;
            }
        }
        else
        {
            Container* curr = getContainer(cond->owner);
            if(curr->contains(cond->object))
            {
                triggered = true;
            }
        }
    }
    else if (string(cond->object) != string(""))
    {
        for(unsigned int currobj = 0; currobj < itemVec.size(); currobj++)
        {
            if(itemVec.operator[](currobj)->getName() == string(cond->object))
            {
                if(itemVec.operator[](currobj)->getStatus() == string(cond->status))
                {
                    triggered = true;
                }
            }
        }
        for(unsigned int currobj = 0; currobj < containVec.size(); currobj++)
        {
            if(containVec.operator[](currobj)->getName() == string(cond->object))
            {
                if(containVec.operator[](currobj)->getStatus() == string(cond->status))
                {
                    triggered = true;
                }
            }
        }
        for(unsigned int currobj = 0; currobj < creatureVec.size(); currobj++)
        {
            if(creatureVec.operator[](currobj)->getName() == string(cond->object))
            {
                if(creatureVec.operator[](currobj)->getStatus() == string(cond->status))
                {
                    triggered = true;
                }
            }
        }
    }
    if(triggered)
    {
        pullTrigger(room);
        return true;
    }
    return false;
}
Container* Map::getContainer(string _cont) {
    for(unsigned int i = 0; i < containVec.size(); i++)
    {
        if(_cont == string(containVec.operator[](i)->getName()))
        {
            return containVec.operator[](i);
        }
    }
    return NULL;
}
bool Map::inventoryContains(string _item) {
    for(auto i = inventory.begin(); i != inventory.end(); ++i)
    {
        if(*i == _item)
        {
            return true;
        }
    }
    return false;
}
void Map::pullTrigger(Base *_item) {
    if(_item != NULL) {
        _item->getTrigger()->printTrigger();
        if (string(_item->getTrigger()->type) != ("permanent")) {
            _item->removeTrigger();
        }
    }
}
bool Map::checkCreatureTriggers(Room* _room) {
    Trigger* currtrig;
    Condition* cond;//the current condition
    Item* obj;//the current object
    bool fired = false;
    for(unsigned int i = 0; i<creatureVec.size(); i++) {//for each creature
        //if the cureature is in the current room
        if(_room->containsCreature(string(creatureVec.operator[](i)->getName()))) {
            currtrig = creatureVec.operator[](i)->getTrigger();
            if (currtrig != NULL)
            {//if they have a trigger
                cond = currtrig->condition;
                for (unsigned int j = 0;
                     j < itemVec.size(); j++)//check the items to see if it matches with the condition
                {
                    obj = itemVec.operator[](j);
                    if (obj == NULL) { cout << "NULL POINTER" << endl; }
                    if (obj->getName() == string(cond->object))//if it does, check the status
                    {
                        if (obj->getStatus() == string(cond->status))//if the status is right
                        {
                            cout << currtrig->print << endl;
                            if ((currtrig->type) != string("permanent")) {
                                obj->setTrigger(NULL);
                            }
                            fired = true;
                        }
                    }
                }

            }
        }
    }
    return fired;
}
void Map::updateItem(string _item, string _status) {
    for(unsigned int i = 0; i<itemVec.size(); i++)
    {
        if(itemVec.operator[](i)->getName() == _item) {
            itemVec.operator[](i)->setStatus(_status);
        }
    }
}
void Map::turnOnItem(string _name) {
    string action;
    vector<string> actions;
    string item;
    string status;
    for(unsigned int i = 0; i<itemVec.size(); i++)
    {
        if(itemVec.operator[](i)->getName() == _name)
        {
            Turnon* curr = itemVec.operator[](i)->getTurnon();
            if(curr != NULL)
            {
                cout<<curr->print<<endl;
                action = curr->action;
                actions = split(action, ' ');
                item = actions.operator[](1);
                status = actions.operator[](3);
                updateItem(item, status);
            }
            else
            {cout<<"You can't turn that on"<<endl;}
        }

    }

}
void Map::readItem(string _name) {
    for(unsigned int i = 0; i<itemVec.size(); i++)
    {
        if(itemVec.operator[](i)->getName() == _name)
        {
            if(itemVec.operator[](i)->getWriting() != NULL)
            {
                cout<<itemVec.operator[](i)->getWriting()<<endl;
            }
            else
            {
                cout<<"Nothing Written"<<endl;
            }
        }

    }
}
void Map::build_map(xml_node<>* firstnode) {
    xml_node<> *currnode = firstnode;

    if (string("map") == string(currnode->name())) {
        currnode = currnode->first_node();
    }

    while (true)
    {
        if(string(currnode->name())== string("room"))
        {
            rooms.push_back(currnode);
        }
        else if(string(currnode->name())== string("item"))
        {
            items.push_back(currnode);
        }
        else if(string(currnode->name())== string("container"))
        {
            containers.push_back(currnode);
        }
        else if(string(currnode->name())== string("creature"))
        {
            creatures.push_back(currnode);
        }
        if(currnode->next_sibling() == NULL)
        {break;}
        currnode = currnode->next_sibling();

    }
}
void Map::node2obj() {
    unsigned int i = 0;
    xml_node<>* currnode;
    Room* room;
    for(i = 0; i < rooms.size(); i++)
    {
        room = new Room();
        char* typ = (char*)"regular";
        room->setType(typ);
        currnode = rooms.operator[](i)->first_node();
        while(true)
        {
            if(string(currnode->name()) == string("name"))
            {
                room->setName(currnode->value());
            }
            else if(string(currnode->name()) == string("description"))
            {
                room->setDescription(currnode->value());
            }
            else if(string(currnode->name()) == string("item"))
            {
                room->addItem(currnode->value());
            }
            else if(string(currnode->name()) == string("trigger"))
            {
                room->setTrigger(currnode);
            }
            else if(string(currnode->name())== string("border"))
            {
                room->addBorder(currnode);
            }
            else if(string(currnode->name())== string("container"))
            {
                room->addContainer(currnode->value());
            }
            else if(string(currnode->name())== string("creature"))
            {
                room->addCreature(currnode->value());
            }
            else if(string(currnode->name())== string("type"))
            {
                room->setType(currnode->value());
            }
            else if(string(currnode->name())== string("status"))
            {
                room->setStatus(currnode->value());
            }
            if(currnode->next_sibling() == NULL)
            {break;}
            currnode = currnode->next_sibling();
        }
        roomVec.push_back(room);
    }

    Item* item;

    for(i=0;i < items.size(); i++)
    {
        item = new Item();
        currnode = items.operator[](i)->first_node();
        while(true)
        {
            if(string(currnode->name()) == string("name"))
            {
                item->setName(currnode->value());
            }
            else if(string(currnode->name()) == string("writing"))
            {
                item->setWriting(currnode->value());
            }
            else if(string(currnode->name()) == string("status"))
            {
                item->setStatus(currnode->value());
            }
            else if(string(currnode->name()) == string("turnon"))
            {
                item->setTurn_on(currnode);
            }
            else if(string(currnode->name()) == string("description"))
            {
                item->setDescription(currnode->value());
            }
            else if(string(currnode->name()) == string("trigger"))
            {
                item->setTrigger(currnode);
            }

            if(currnode->next_sibling() == NULL)
            {break;}
            currnode = currnode->next_sibling();
        }
        itemVec.push_back(item);

    }

    Container* container;

    for(i=0;i < containers.size(); i++)
    {
        container = new Container();
        currnode = containers.operator[](i)->first_node();
        while (true) {
            if (string(currnode->name()) == string("name")) {
                container->setName(currnode->value());
            } else if (string(currnode->name()) == string("item")) {
                container->addItem(currnode->value());
            } else if (string(currnode->name()) == string("status")) {
                container->setStatus(currnode->value());
            } else if (string(currnode->name()) == string("accept")) {
                container->addAccept(currnode->value());
            } else if (string(currnode->name()) == string("trigger")) {
                container->setTrigger(currnode);
            } else if (string(currnode->name()) == string("description")) {
                container->setDescription(currnode->value());
            }


            if (currnode->next_sibling() == NULL) { break; }
            currnode = currnode->next_sibling();
        }
        containVec.push_back(container);
    }

        Creature *creature;

        for (i = 0; i < creatures.size(); i++)
        {
            creature = new Creature();
            currnode = creatures.operator[](i)->first_node();
            while (true) {
                if (string(currnode->name()) == string("name")) {
                    creature->setName(currnode->value());
                } else if (string(currnode->name()) == string("status")) {
                    creature->setStatus(currnode->value());
                } else if (string(currnode->name()) == string("trigger")) {
                    creature->setTrigger(currnode);
                } else if (string(currnode->name()) == string("description")) {
                    creature->setDescription(currnode->value());
                } else if (string(currnode->name()) == string("vulnerability")) {
                    creature->addVulner(currnode->value());
                } else if (string(currnode->name()) == string("attack")) {
                    creature->setAttack(currnode->value());
                }


                if (currnode->next_sibling() == NULL) { break; }
                currnode = currnode->next_sibling();
            }
            creatureVec.push_back(creature);

        }


}
Room* Map::getRoom(string name) {
    for(unsigned int i = 0; i < roomVec.size(); i++)
    {
        if(string(roomVec.operator[](i)->getName()) == name)
        {
            return(roomVec.operator[](i));
        }
    }
}
vector<string> Map::split(string &s, char delim) {
    vector<string> elems;
    stringstream stream(s);
    string curr;
    while(getline(stream, curr, delim))
    {
        elems.push_back(curr);
    }
    return elems;
}