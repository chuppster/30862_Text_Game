#include <iostream>
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
        printf("%c",currxml[i]);
        i++;
    }
    xml_document<> doc;
    doc.parse<0>(currxml);

    return 0;
}