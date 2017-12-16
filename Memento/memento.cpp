#include <iostream>
#include "memento.h"

int main()
{

    int defaultvalue = 100;

    NumberContainer *container = new NumberContainer(defaultvalue);

    std::cout << "Default value: " << defaultvalue << std::endl;
    std::cout << "Current: " << container->getNumber() << std::endl;
    std::cout << std::endl;

    std::cout << "Change to: 200" << std::endl;
    container->setNumber(200);
    std::cout << "Current:" << container->getNumber() << std::endl;
    std::cout << std::endl;

    std::cout << "Restore default" << std::endl;
    container->restoreDefault();
    std::cout << "Current: " << container->getNumber() << std::endl;
    std::cout << std::endl;

    std::cout << "Change to: 250" << std::endl;
    container->setNumber(250);
    std::cout << "Current: " << container->getNumber() << std::endl;
    std::cout << std::endl;

    std::cout << "Overwrite default" << std::endl;
    container->overwriteDefault();
    std::cout << std::endl;

    std::cout << "Restore default" << std::endl;
    container->restoreDefault();
    std::cout << "Current: " << container->getNumber() << std::endl;
    std::cout << std::endl;

    // ストッパー（Enterを押すと続く）
    std::cout << "Press ENTER KEY to continue..." << std::endl;
    getchar();

    return 0;
}