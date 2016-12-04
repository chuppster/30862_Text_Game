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
#include "rapidxml_print.hpp"
#include <iostream>
#include <string>
using namespace rapidxml;

void print_xml(xml_node<>* node);

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
    int i = 0;
    while(i<len){
        std::cout << currxml[i];
        i++;
    }
    xml_document<> doc;
    try {
        doc.parse<0>(currxml);
    }catch(parse_error e)
    {
        cout << "Parse Exception: "<< e.what() << endl;
    }

    vector<Room> rooms;

    xml_node<> *node = doc.first_node();

    print_xml(node);


    cout<<node->name()<<endl;
    node = node->first_node();
    cout<<node->name()<<endl;
    node = node->first_node();
    cout<<node->name()<<endl;
    node = node->next_sibling();
    cout<<node->name()<<endl;
    node = node->next_sibling();
    cout<<node->name()<<endl;
    node = node->next_sibling();
    cout<<node->name()<<endl;
    node = node->next_sibling();
    cout<<node->name()<<endl;







    //cout << node->name() << endl;
    /*if(strcmp(node->name(),"room") == 0)
    {
        cout << "Making a Room" << endl;
        node = node->first_node();
        Room *currRoom = new Room();
        currRoom->setType(node->first_attribute()->value());
        cout << currRoom->getType() << endl;
    }*/
    //cout << node->name() << endl;//this is map
    /*while(node != NULL)
    {
        cout << node->name() << endl;
        if(node -> first_node() == NULL)
        {
            node = node ->next_sibling();
        }
        else{
            node = node->first_node();
        }
    }*/



    return 0;
}

void print_xml(xml_node<>* node)
{
    if(node == NULL)
    {
        return;
    }
    cout << node->name() << endl;

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
