﻿#pragma once

#include <iostream>
#include "enemybuilder.h"


// 難易度Easy用のBuilder
class EasyEnemyBuilder : public IEnemyBuilder {
private:
    const float m_rate = 0.5f;
	const float m_hprate = 0.7f;
	const float m_atkrate = 1.0f;
	const float m_defrate = 0.5f;


public:
    void setHP(AEnemy* _enemy, float _hp) override {
        _enemy->setHP(_hp * m_hprate);
    }
    void setAtk(AEnemy* _enemy, float _atk) override {
        _enemy->setAtk(_atk * m_atkrate);
    }
    void setDef(AEnemy* _enemy, float _def) override {
        _enemy->setDef(_def * m_defrate);
    }
};

// 難易度Normal用のBuilder
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

class HardEnemyBuilder : public IEnemyBuilder {
private:
	const float m_rate = 1.5f;

public:
	void setHP(AEnemy* _enemy, float _hp) override {
		_enemy->setHP(_hp * m_rate + 1000);
	}
	void setAtk(AEnemy* _enemy, float _atk) override {
		_enemy->setAtk(_atk * m_rate);
	}
	void setDef(AEnemy* _enemy, float _def) override {
		_enemy->setDef(_def * m_rate);
	}
};

// 統括用のDirector
// テンプレート構文とかで作ったほうが良いかも
class EnemyDirector : public ADirector {

private:
    AEnemy* createInstance() override {
        return new AEnemy();
    }
};


int main() {

    // Director
    EnemyDirector director;

    // 各難易度ごとのBuilderインスタンスを取得
    IEnemyBuilder* easy = new EasyEnemyBuilder();
    IEnemyBuilder* normal = new NormalEnemyBuilder();
	IEnemyBuilder* hard = new HardEnemyBuilder();

    // Enemyインスタンス用の変数
    AEnemy* enemy;

    // パラメータ
    // 実際はCSVファイルとかから引っ張ってこような
    EnemyParams param;
    param.hp = 50;
    param.atk = 10;
    param.def = 7;

    // Easy版
    std::cout << "-- EASY --" << std::endl;

    director.setBuilder(easy);
    enemy = director.construct(param);

	EnemyDocument::PrintStatus(enemy);

    delete enemy;


    // Normal版
    std::cout << "-- NORMAL --" << std::endl;

    director.setBuilder(normal);
    enemy = director.construct(param);

    EnemyDocument::PrintStatus(enemy);

	delete enemy;

	// Hard版
	std::cout << "-- HARD --" << std::endl;

	director.setBuilder(hard);
	enemy = director.construct(param);

	EnemyDocument::PrintStatus(enemy);


    delete enemy;
    delete easy;
    delete normal;
	delete hard;

    // ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
    getchar();

    return 0;

}