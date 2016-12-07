#include <iostream>
#include <fstream>
#include <cstring>
#include "Base.h"
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
//#include "rapidxml_iterators.hpp"
//#include "rapidxml_print.hpp"
#include "Map.h"
#include <iostream>
#include <string>
using namespace rapidxml;

void print_xml(xml_node<>* node);
Map* build_map(xml_node<>* firstnode);

int main() {
    std::ifstream f;
    int len;
    f.open("C:/xmls/sample.xml", std::ifstream::in);
    f.seekg(0, std::ios::end);
    len = f.tellg();
    f.seekg(0, std::ios::beg);
    char currxml[len];
    f.read(currxml, len);
    f.close();

    xml_document<> doc;
    try {
        doc.parse<0>(currxml);
    }catch(parse_error e)
    {
        cout << "Parse Exception: "<< e.what() << endl;
    }

    Map * map;

    xml_node<> *node = doc.first_node();

    //print_xml(node);

    map = build_map(node);
    map->node2obj();

    return 0;
}

Map* build_map(xml_node<>* firstnode) {
    xml_node<> *currnode = firstnode;
    if ((strcmp("map", currnode->name())) == 0) {
        currnode = currnode->first_node();
    }

    Map *map = new Map();

    while (true)
    {
        if(string(currnode->name())== string("room"))
        {
            map->rooms.push_back(currnode);
            //cout << "Added Room " << currnode->name() << endl;
        }
        else if(string(currnode->name())== string("item"))
        {
            map->items.push_back(currnode);
            //cout << "Added Item " << currnode->name() << endl;
        }
        else if(string(currnode->name())== string("container"))
        {
            map->containers.push_back(currnode);
            //cout << "Added Container " << currnode->name() << endl;
        }
        else if(string(currnode->name())== string("creature"))
        {
            map->creatures.push_back(currnode);
            //cout << "Added Creature " << currnode->name() << endl;
        }
        if(currnode->next_sibling() == NULL)
        {break;}
        currnode = currnode->next_sibling();

    }

    return map;
}

void print_xml(xml_node<>* node)
{
    if(node == NULL)
    {
        return;
    }
    if(strcmp(node->name(), "") != 0)
    {
        cout << "Name: (" << node->name() << ") Parent: (" << node->parent()->name() << ")" << endl;
    }

    if(node -> first_node() != NULL)
    {
        print_xml(node -> first_node());
    }
    if(node -> next_sibling() != NULL)
    {
        print_xml(node->next_sibling());
    }
    return;
}
