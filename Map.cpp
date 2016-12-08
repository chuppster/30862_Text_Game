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
    vector<string> inventory;
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

        //check if triggers override command

        //execute command if not overridden

        //check if the effects of command activate trigger

        //if the command activates the trigger, perform the indicated actions

        if(in1 == string("n") || in1 == string("s") || in1 == string("e") || in1 == string("w"))
        {
            triggered = room->checkTrigger(in1);
            if(!triggered)
            {
                cout<<"didn't find a trigger"<<endl;
                border_room = room->getBorderRoom(in1);//gets you the name of the room in that direction
                if(border_room == string(""))//if you can't find the room
                {
                    cout<<"Can't go that way."<<endl;
                } else{//if you can, move to the next room
                    room = getRoom(border_room);
                    cout << room->getDescription() << endl;
                }
            } else{
                //cout<<"found a trigger"<<endl;
                room->pullTrigger();
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
                //cout<<"iterate for i= "<<i<<endl;
               if(itemVec.operator[](i)->getName() == curritem)
               {
                   if(room->hasItem(curritem)){
                       //cout<<"Has the Item"<<endl;
                       inventory.push_back(curritem);
                       //cout<<"Inventory: "<<inventory.operator[](0)<<endl;
                       //cout<<"Removing Item"<<endl;
                       room->removeItem(curritem);
                       //cout<<"Removed Item"<<endl;
                   }
               }
            }
        }

        if(in1 == string("exit"))
        {exit = true;}
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