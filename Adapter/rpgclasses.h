#pragma once
#include <iostream>

class Character() {
private:
    float m_power = 5;

public:
    void attack() {
        std::cout << "攻撃" << std::endl;
        std::cout << this->m_power << std::endl;
    }

    float getPower() {
        return this->m_power;
    }
}

