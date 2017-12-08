#pragma once
#include <iostream>
#include <random>

// キャラクタークラス
class Character
{
  private:
    int m_hp;
    float m_atk;
    float m_def;
    float m_avoid;

  public:
    void setHP(int hp)
    {
        this->m_hp = hp;
    }
    int getHP()
    {
        return this->m_hp;
    }
    void setAtk(float atk)
    {
        this->m_atk = atk;
    }
    float getAtk()
    {
        return this->m_atk;
    }
    void setDef(float def)
    {
        this->m_def = def;
    }
    float getDef()
    {
        return this->m_def;
    }
    void setAvoid(float avoid)
    {
        this->m_avoid = avoid;
    }
    float getAvoid()
    {
        return this->m_avoid;
    }
};

// スキル基底クラス
class ASkill
{
  private:
    float m_accuracy;
    float m_power;

  public:
    ASkill(float power, float accuracy) : m_power(power), m_accuracy(accuracy) {}

    float getAccuracy()
    {
        return this->m_accuracy;
    }
    float getPower()
    {
        return this->m_power;
    }
};

// 通常攻撃
class NormalAttack : public ASkill
{
  public:
    NormalAttack() : ASkill(5, 0.7) {}
};

// 強攻撃
class HeavyAttack : public ASkill
{
  public:
    HeavyAttack() : ASkill(10, 0.5) {}
};

// スキルチェック基底クラス
class ASkillCheck
{
  private:
    ASkillCheck *m_next;

  protected:
    virtual bool isSkillCheckSuccess(Character *src, Character *dst, ASkill *skill)
    {
        return false;
    }

  public:
    // 次のスキルチェックをセットする
    void setNext(ASkillCheck *next)
    {
        this->m_next = next;
    }

    // スキルチェックを行う
    bool check(Character *src, Character *dst, ASkill *skill)
    {
        if (this->isSkillCheckSuccess(src, dst, skill))
        {
            return true;
        }

        // 次のスキルチェックが登録されている場合は、次のスキルチェックを実行する
        if (this->m_next != nullptr)
        {
            return this->m_next->check(src, dst, skill);
        }

        std::cout << "スキルチェックがありません" << std::endl;
        return false;
    }
};

// 命中スキルチェック
class AccuracySkillCheck : public ASkillCheck
{
  private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_real_distribution<double> score;

  protected:
    bool isSkillCheckSuccess(Character *src, Character *dst, ASkill *skill) override
    {
        std::cout << "命中スキルチェック：";
        if (score(mt) < skill->getAccuracy()) {
            std::cout << "成功" << std::endl;
            return true;
        } else {
            std::cout << "失敗" <<std::endl;
            return false;
        }
    }

  public:
    AccuracySkillCheck() : mt(rd()), score(0.0, 1.0) {}
};

// 回避スキルチェック
class AvoidanceSkillCheck : public ASkillCheck
{
  private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_real_distribution<double> score;

  protected:
    bool isSkillCheckSuccess(Character *src, Character *dst, ASkill *skill) override
    {
        std::cout << "回避スキルチェック：";
        if (score(mt) > (1 - dst->getAvoid())) {
            std::cout << "成功" << std::endl;
            return true;
        } else {
            std::cout << "失敗" <<std::endl;
            return false;
        }
    }

  public:
    AvoidanceSkillCheck() : mt(rd()), score(0.0, 1.0) {}
};

// 防御スキルチェック
class GuardSkillCheck : public ASkillCheck
{
  protected:
    bool isSkillCheckSuccess(Character *src, Character *dst, ASkill *skill) override
    {
        std::cout << "防御スキルチェック：";
        if ((src->getAtk() + skill->getPower()) > dst->getDef()) {
            std::cout << "成功" << std::endl;
            return true;
        } else {
            std::cout << "失敗" << std::endl;
            return false;
        }
    }
};
