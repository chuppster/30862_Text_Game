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
using namespace rapidxml;

int main() {

    std::ifstream f;
    int len;
    f.open("sample.xml", std::ifstream::in);
    f.seekg(0, std::ios::end);
    len = f.tellg();
    printf("Len: %d\n",len);
    f.seekg(0, std::ios::beg);
    char currxml[len];
    f.read(currxml, len);
    f.close();
    printf("Read File\n");
    int i = 0;
    while(i<len){
        printf("a\n");
        printf("%c",currxml[i]);
        i++;
    }
    xml_document<> doc;
    doc.parse<0>(currxml);

    return 0;
}