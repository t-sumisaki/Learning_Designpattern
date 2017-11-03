#pragma once
#include <iostream>

class Enemy {
private:
    int m_attack = 50;

public:
    void enemyAttack() {
        std::cout << "攻撃" << std::endl;
        std::cout << this->m_attack << std::endl;
    }

    int getAttackPoint() {
        return this->m_attack;
    }
}

class Weapon {

private:
    int m_point = 10;

public:

    void use() {
        std::cout << this->m_point << std::endl;
    }

    int getPoint() {
        return m_point;
    }

}