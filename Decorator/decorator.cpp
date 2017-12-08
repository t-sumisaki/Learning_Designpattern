#include <iostream>
#include "decorator.h"

// オーク
class Orc : public AMonster {
public:
    virtual void attack() override {
        std::cout << "オークの攻撃" << std::endl;
    }
};

int main() {

    AMonster* monster;

    std::cout << "---通常---" << std::endl;
    monster = new Orc();
    monster->attack();

    std::cout << "---毒効果追加---" << std::endl;

    monster = new PoisonMonsterDecorator(monster);
    monster->attack();

    std::cout << "---麻痺効果を追加---" << std::endl;

    monster = new ParalysisMonsterDecorator(monster);
    monster->attack();

    std::cout << "---気絶効果を追加---" << std::endl;

    monster = new StanMonsterDecorator(monster);
    monster->attack();

	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();

    return 0;
}