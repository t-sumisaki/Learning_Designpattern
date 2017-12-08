#pragma once

#include <iostream>

// モンスターベースクラス
class AMonster
{
  public:
    virtual void attack()
    {
        std::cout << "攻撃" << std::endl;
    }
};

// モンスターデコレータクラス
class AMonsterDecorator : public AMonster
{
  protected:
    AMonster *m_monster;

  public:
    AMonsterDecorator(AMonster *monster)
        : m_monster(monster) {}

    virtual void attack() override
    {
        m_monster->attack();
    }
};

// 毒効果追加用のデコレータ
class PoisonMonsterDecorator : public AMonsterDecorator
{
  public:
    PoisonMonsterDecorator(AMonster *monster) : AMonsterDecorator(monster) {}
    virtual void attack() override
    {
        m_monster->attack();
        std::cout << "毒効果を+1する" << std::endl;
    }
};

// マヒ効果追加用のデコレータ
class ParalysisMonsterDecorator : public AMonsterDecorator
{
  public:
    ParalysisMonsterDecorator(AMonster *monster) : AMonsterDecorator(monster) {}
    virtual void attack() override
    {
        m_monster->attack();
        std::cout << "マヒ効果を+1する" << std::endl;
    }
};

// 気絶効果追加用のデコレータ
class StanMonsterDecorator : public AMonsterDecorator
{
  public:
    StanMonsterDecorator(AMonster *monster) : AMonsterDecorator(monster) {}
    virtual void attack() override
    {
        m_monster->attack();
        std::cout << "気絶効果を+1する" << std::endl;
    }
};
