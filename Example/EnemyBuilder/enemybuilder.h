#pragma once

#include <iostream>

// パラメータ入力用の構造体
struct EnemyParams {
    float hp;
    float atk;
    float def;
};

// 敵クラス
// 実際は継承して使う
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

// Builderインターフェース
class IEnemyBuilder {
public:
    virtual void setHP(AEnemy* _enemy, float _hp) = 0;
    virtual void setAtk(AEnemy* _enemy, float _atk) = 0;
    virtual void setDef(AEnemy* _enemy, float _def) = 0;
};

// Director基底クラス
// 今回はFactoryMethodと継承で実装しているが、テンプレート構文などを使ったほうが良いかも
class ADirector {
private:
    IEnemyBuilder* m_builder;

    // FactoryMethod。継承先でどのEnemyのインスタンスを作成するか指定
    virtual AEnemy* createInstance() = 0;

public:
    // Builderのインスタンスをセットする
    void setBuilder(IEnemyBuilder* _builder) {
        m_builder = _builder;
    }

    // Enemyを作成
    // Director-Builderパターン
    AEnemy* construct(EnemyParams param) {

        AEnemy* _enemy = createInstance();
        if (m_builder) {
            m_builder->setHP(_enemy, param.hp);
            m_builder->setAtk(_enemy, param.atk);
            m_builder->setDef(_enemy, param.def);
        }

        return _enemy;
    }

};

// Enemyクラスのパラメータを出力するだけのクラス
class AEnemyDocment {
public:
    static void PrintStatus(AEnemy* _enemy) {

        std::cout << "HP: " << _enemy->getHP() << std::endl;
        std::cout << "ATK: " << _enemy->getAtk() << std::endl;
        std::cout << "DEF: " << _enemy->getDef() << std::endl;

    }
};
