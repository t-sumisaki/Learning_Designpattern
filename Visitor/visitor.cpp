#include <iostream>
#include "visitor.h"

int main()
{

    AThief *thief;
    WoodBox *wood = new WoodBox();
    SteelBox *steel = new SteelBox();
    BronzeBox *bronze = new BronzeBox();

    thief = new RookieThief();
    wood->accept(thief);
    steel->accept(thief);
    bronze->accept(thief);

    thief = new MiddleThief();
    wood->accept(thief);
    steel->accept(thief);
    bronze->accept(thief);

    // ストッパー（Enterを押すと続く）
    std::cout << "Press ENTER KEY to continue..." << std::endl;
    getchar();

    return 0;
}