#include <iostream>

class AStrategy {
private:
    virtual void move() = 0;
    virtual void attack() = 0;
    virtual void useItem() = 0;

public:
    void execute() {
        useItem();
        move();
        attack();
    }
};


class Actor {
private:
    int m_hp;
    AStrategy* m_strategy;
public:
    void setHP(int _hp) {
        m_hp = _hp;
    }

    void setStrategy(AStrategy* _strategy) {
        m_strategy = _strategy;
    }

    void action() {
        std::cout << "Action!" << std::endl;
        if (m_strategy) {
            m_strategy->execute();
        }
    }
};



int main() {

    Actor actor;


    // HPに余裕がある場合
    actor.setHP(10);
    actor.action();


    // HPに余裕がない場合
    actor.setHP(3);
    actor.action();


    // ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();

    return 0;
}




