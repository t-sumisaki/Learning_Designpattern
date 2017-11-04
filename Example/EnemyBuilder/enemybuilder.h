#pragma once

#include <iostream>

class AEnemy {
protected:
    float m_hp;
    float m_atk;
    float m_def;

public:
    float getHP() {
        return m_hp;
    }
    void setHP(float _hp) {
        m_hp = _hp;
    }
    float getAtk() {
        return m_atk;
    }
    void setAtk(float _atk) {
        m_atk = _atk;
    }
    float getDef() {
        return m_def;
    }
    void setDef(float _def) {
        m_def = _def;
    }
};


class IEnemyBuilder {
public:
    virtual void setHP(AEnemy* _enemy, float _hp) = 0;
    virtual void setAtk(AEnemy* _enemy, float _atk) = 0;
    virtual void setDef(AEnemy* _enemy, float _def) = 0;
};

class ADirector {
private:
    IEnemyBuilder* m_builder;

    virtual AEnemy* createInstance() = 0;

public:
    void setBuilder(IEnemyBuilder* _builder) {
        m_builder = _builder;
    }
    AEnemy* construct(float _hp, float _atk, float _def) {

        AEnemy* _enemy = createInstance();
        if (m_builder) {
            m_builder->setHP(_enemy, _hp);
            m_builder->setAtk(_enemy, _atk);
            m_builder->setDef(_enemy, _def);
        }

        return _enemy;
    }

};


class EnemyDocument {
public:
    static void PrintStatus(AEnemy* _enemy) {

        std::cout << "HP: " << _enemy->getHP() << std::endl;
        std::cout << "ATK: " << _enemy->getAtk() << std::endl;
        std::cout << "DEF: " << _enemy->getDef() << std::endl;

    }
};