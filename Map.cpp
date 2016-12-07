//
// Created by Adrian on 12/5/2016.
//

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
    vector<string>* inventory;
    bool exit = false;
    Room* room;
    string in1, in2, in3, in4;
    string border_room;

    unsigned int i;//finding the entrance
    room = getRoom(string("Entrance"));
    room->printDesc();//print the description of the entrance
    bool triggered = false;
    while(exit == false)//let's loop until we exit
    {
        cin >> in1 >> in2 >> in3 >> in4;//get the command

        //check if triggers override command

        //execute command if not overridden

        //check if the effects of command activate trigger

        //if the command activates the trigger, perform the indicated actions

        if(in1 == string("n") || in1 == string("s") || in1 == string("e") || in1 == string("w"))
        {
            triggered = room->checkTrigger(in1);
            if(!triggered)
            {
                border_room = room->getBorderRoom(in1);
                if(border_room == string(""))
                {
                    cout<<"Can't go that way."<<endl;
                } else{
                    room = getRoom(border_room);
                }
            }
        }
        else if(in1 == string("i"))
        {
            cout << "Inventory: ";
            if(inventory->size() == 0)
            {
                cout << "empty" << endl;
            }
            else
            {
                for(unsigned int j = 0; j < inventory->size(); i++)
                {cout << inventory->operator[](i);}
            }
        }
        else if(in1 == string("take"))//take command
        {
            //split the string
            //vector<string> item = split(*string(input), ' ');
            //cout << "Split: " << item.front() << endl;//not splitting properly
        }

            //check for triggers
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

vector<string> Map::split(string &s, char delim) {
    cout<<"Input String = "<< s<<endl;
    vector<string> elems;
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
        cout<<item<<endl;
    }
    return elems;
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
