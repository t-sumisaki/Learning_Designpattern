#pragma once
#include <iostream>

// ロボットパーツのベースクラス
class ARobotPart {
private:
    std::string m_name;

public:
    ARobotPart(std::string _name) : m_name(_name) {}
    virtual void showSpec() {
        std::cout << "Name:" << m_name.c_str() << std::endl;
    } 
};

class MissileArm : public ARobotPart {
public:
    MissileArm() : ARobotPart("MissleArm") {}
};

class ChainsawArm : public ARobotPart {
public:
    ChainsawArm() : ARobotPart("Chainsaw") {}
};

class ShieldArm : public ARobotPart {
public:
    ShieldArm() : ARobotPart("Shield") {}
};

class NormalLegs : public ARobotPart {
public:
    NormalLegs() : ARobotPart("NormalLegs"){}
};

class Booster : public ARobotPart {
public:
    Booster() : ARobotPart("Booster"){}
};

class NormalBody : public ARobotPart {
public:
    NormalBody(): ARobotPart("NormalBody"){}
};

class HeavyBody : public ARobotPart {
public:
    HeavyBody(): ARobotPart("HeavyBody"){}
};

