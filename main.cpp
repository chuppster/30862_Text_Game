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
void printVec(std::vector<std::string> vec);

int main() {
    std::ifstream f;
    int len;
    string filename;
    cout << "Enter Map Name in C:/xmls/:";
    cin >> filename;
    cout << "\n";
    f.open("C:/xmls/"+filename, std::ifstream::in);
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

    xml_node<> *node = doc.first_node();
    Map* map = new Map;
    map->build_map(node);   //create a list of each type of element from the XML tree
    map->node2obj();        //parse list into objects
    map->run();


    return 0;
}

void printVec(std::vector<std::string> vec){
    for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end(); ++it)
        std::cout << *it<< ' ' ;
    std::cout << '\n';
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
