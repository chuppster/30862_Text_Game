#include <iostream>
#include "Base.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "I'm gonna make a game" << std::endl;

    std::string tmp1 ("Test1");
    std::string tmp2 ("Test 2");

    Base* test = new Base();

    test->addTrigger(tmp2);
    test->setName(tmp1);

    std::cout << "Output ---------------------" << std::endl;
    test->printVec(test->getTrigger());
    std::cout << test->getName() << std::endl;


    return 0;
}