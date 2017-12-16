#pragma once

#include <iostream>

class AThief;

class ABox;

class WoodBox;
class SteelBox;
class BronzeBox;

// 盗賊クラス
class AThief
{
private:
	// スキルレベル
	int m_skillLevel;

public:
	int getSkillLevel() {
		return this->m_skillLevel;
	}
	void setSkillLevel(int skillLevel) {
		this->m_skillLevel = skillLevel;
	}
	virtual void action(WoodBox *box) = 0;
	virtual void action(SteelBox *box) = 0;
	virtual void action(BronzeBox *box) = 0;
};

// 宝箱クラス
class ABox
{
private:
	// 必須スキルレベル
	int m_requireSkillLevel;

public:
	ABox(int requireSkillLevel) : m_requireSkillLevel(requireSkillLevel) {}
	int getRequireSkillLevel() {
		return this->m_requireSkillLevel;
	}
	virtual void accept(AThief *thief) = 0;
};

// 木の宝箱
class WoodBox : public ABox
{
public:
	WoodBox() : ABox(1) {}
	void accept(AThief *thief) override
	{
		thief->action(this);
	}
};

// 鉄の宝箱
class SteelBox : public ABox
{
public:
	SteelBox() : ABox(3) {}
	void accept(AThief *thief) override
	{
		thief->action(this);
	}
};

// 銅の宝箱
class BronzeBox : public ABox
{
public:
	BronzeBox() : ABox(5) {}
	void accept(AThief *thief) override
	{
		thief->action(this);
	}
};

// 新人盗賊
class RookieThief : public AThief
{
public:
	RookieThief()
	{
		std::cout << "--新人盗賊--" << std::endl;
	}
	void action(WoodBox *box) override
	{
		std::cout << "スキルレベル:" << this->getSkillLevel() << std::endl;
		std::cout << "必要スキルレベル:" << box->getRequireSkillLevel() << std::endl;

		if (box->getRequireSkillLevel() <= this->getSkillLevel()) {
			std::cout << "開けられた" << std::endl;
		}
		else {
			std::cout << "開けられない" << std::endl;
		}
	}
	void action(SteelBox *box) override
	{
		std::cout << "開けられない" << std::endl;
	}
	void action(BronzeBox *box) override
	{
		std::cout << "開けられない" << std::endl;
	}
};

// 中堅盗賊
class MiddleThief : public AThief
{
public:
	MiddleThief()
	{
		std::cout << "--中堅盗賊--" << std::endl;
	}
	void action(WoodBox *box) override
	{
		std::cout << "開けられた" << std::endl;
	}
	void action(SteelBox *box) override
	{
		std::cout << "開けられた" << std::endl;
	}
	void action(BronzeBox *box) override
	{
		std::cout << "開けられない" << std::endl;
	}
};
