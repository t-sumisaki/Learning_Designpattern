#pragma once
#include <iostream>


// FactoryMethodはTemplateMethodとも相性が良い

// キャラクターの基底クラス
class ICharacter {
public:
    virtual void printName() = 0;
};

// ICharacterの実装クラス
class Enemy : public ICharacter {
public:
    void printName() override {
        std::cout << "Enemy class" << std::endl;
    }
};

// Enemy系のインスタンスを取得するクラス
class EnemyFactory  {
public:
    ICharacter* createInstance()　{
        return new Enemy();
    }
};



int main() {

    std::cout << "FactoryMethod sample." << std::endl;

    EnemyFactory _enemy;

    // インスタンスを取得
    ICharacter* enemyInstance = _enemy.createInstance();

    // インスタンスのメソッドを使う
    enemyInstance->printName();

	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();


    return 0;

}