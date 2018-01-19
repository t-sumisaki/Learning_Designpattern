#include <iostream>
#include "chainofresponsibility.h"


int main() {

    Character* attacker = new Character();
    attacker->setHP(10);
    attacker->setAtk(3);
    attacker->setDef(2);
    attacker->setAvoid(0.2);

    Character* defender = new Character();
    defender->setHP(10);
    defender->setAtk(2);
    defender->setDef(4);
    defender->setAvoid(0.1);

    ASkill* normal = new NormalAttack();
    ASkill* heavy = new HeavyAttack();

    ASkillCheck* skillcheck = new ASkillCheck();
    ASkillCheck* accuracy = new AccuracySkillCheck();
    ASkillCheck* avoidance = new AvoidanceSkillCheck();
    ASkillCheck* guard = new GuardSkillCheck();

    //skillcheck->setNext(accuracy);
    //accuracy->setNext(avoidance);
    //avoidance->setNext(guard);

	skillcheck->setNext(avoidance);
	avoidance->setNext(accuracy);

    std::cout << "---通常攻撃---" << std::endl;
    if (skillcheck->check(attacker, defender, normal)) {
        std::cout << "攻撃成功" << std::endl;
    } else {
        std::cout << "攻撃失敗" <<std::endl;
    }

    std::cout << "---強攻撃---" << std::endl;
    if (skillcheck->check(attacker, defender, heavy)) {
        std::cout << "攻撃成功" <<std::endl;
    } else {
        std::cout << "攻撃失敗" << std::endl;
    }

    // ストッパー（Enterを押すと続く）
    std::cout << "Press ENTER KEY to continue..." << std::endl;
    getchar();

    return 0;

}