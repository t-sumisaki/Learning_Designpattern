#pragma once

#include <iostream>
#include "enemybuilder.h"



class EasyEnemyBuilder : public IEnemyBuilder {
private:
    const float m_rate = 0.5;

public:
    void setHP(AEnemy* _enemy, float _hp) override {
        _enemy->setHP(_hp * m_rate);
    }
    void setAtk(AEnemy* _enemy, float _atk) override {
        _enemy->setAtk(_atk * m_rate);
    }
    void setDef(AEnemy* _enemy, float _def) override {
        _enemy->setDef(_def * m_rate);
    }
};

class NormalEnemyBuilder : public IEnemyBuilder {
private:
    const float m_rate = 1.0;

public:
    void setHP(AEnemy* _enemy, float _hp) override {
        _enemy->setHP(_hp * m_rate);
    }
    void setAtk(AEnemy* _enemy, float _atk) override {
        _enemy->setAtk(_atk * m_rate);
    }
    void setDef(AEnemy* _enemy, float _def) override {
        _enemy->setDef(_def * m_rate);
    }
};

class EnemyDirector : public ADirector {

private:
    AEnemy* createInstance() override {
        return new AEnemy();
    }
};


int main() {

    EnemyDirector director;

    IEnemyBuilder* easy = new EasyEnemyBuilder();
    IEnemyBuilder* normal = new NormalEnemyBuilder();

    AEnemy* enemy;

    // Easy版
    std::cout << "-- EASY --" << std::endl;

    director.setBuilder(easy);
    enemy = director.construct(50, 10, 7);

    EnemyDocument::PrintStatus(enemy);

    delete enemy;


    // Normal版
    std::cout << "-- NORMAL --" << std::endl;

    director.setBuilder(normal);
    enemy = director.construct(50, 10, 7);

    EnemyDocument::PrintStatus(enemy);

    delete enemy;


    delete easy;
    delete normal;


    // ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
    getchar();


    return 0;

}