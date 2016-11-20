//
// Created by adria_000 on 11/20/2016.
//

#ifndef INC_30862_TEXT_GAME_ROOM_H
#define INC_30862_TEXT_GAME_ROOM_H

#include <iostream>
#include <string>
using namespace std;

class Room{
private:
    String name;
    String status;
    String type;
    String description;
    std::vector<std::string> border;
    std::vector<std::string> container;
    std::vector<std::string> item;
    std::vector<std::string> creature;
    std::vector<std::string> trigger;
public:
    String getName();
    String getStatus();
    String getType();
    String getDescription;
    std::vector<std::string> getBorder();
    std::vector<std::string> getContainer();
    std::vector<std::string> getItem();
    std::vector<std::string> getCreature();
    std::vector<std::string> getTrigger();
    void setName(String name);
    void setStatus(String status);
    void setType(String type);
    void setDescription(String description);
    void addBorder(std::string border);
    void addContainer(std::string container);
    void addItem(std::string item);
    void addCreature(std::string creature);
    void addTrigger(std::string trigger);
    void removeBorder(std::string border);
    void removeContainer(std::string container);
    void removeItem(std::string item);
    void removeCreature(std::string creature);
    void removeTrigger(std::string trigger);
};

#endif //INC_30862_TEXT_GAME_ROOM_H
