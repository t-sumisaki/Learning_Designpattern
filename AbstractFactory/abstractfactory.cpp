#include <iostream>

#include "robotparts.h"

class Robot {

private:
    ARobotPart* m_righthand;
    ARobotPart* m_lefthand;
    ARobotPart* m_body;
    ARobotPart* m_legs;

public:
    void setRightHand(ARobotPart* _part) {
        m_righthand = _part;
    }
    void setLeftHand(ARobotPart* _part) {
        m_lefthand = _part;
    }
    void setBody(ARobotPart* _part) {
        m_body = _part;
    }
    void setLegs(ARobotPart* _part) {
        m_legs = _part;
    }
    void showSpec() {
        std::cout << "------ ROBOT SPEC ------" << std::endl;
        m_righthand->showSpec();
        m_lefthand->showSpec();
        m_body->showSpec();
        m_legs->showSpec();
    }
};


int main() {


    std::cout << "AbstractFactory pattern sample..." << std::endl;

    Robot robot;

    ARobotPart* righthand = new MissileArm();
    robot.setRightHand(righthand);

    ARobotPart* lefthand = new ShieldArm();
    robot.setLeftHand(lefthand);

    ARobotPart* body = new NormalBody();
    robot.setBody(body);

    ARobotPart* legs = new NormalLegs();
    robot.setLegs(legs);


    robot.showSpec();

    // ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();

    return 0;
}