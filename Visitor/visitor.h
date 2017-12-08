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
  public:
    virtual void action(WoodBox *box) = 0;
    virtual void action(SteelBox *box) = 0;
    virtual void action(BronzeBox *box) = 0;
};

// 宝箱クラス
class ABox
{
  public:
    virtual void accept(AThief *thief) = 0;
};

// 木の宝箱
class WoodBox : public ABox
{
  public:
    void accept(AThief *thief) override
    {
        thief->action(this);
    }
};

// 鉄の宝箱
class SteelBox : public ABox
{
  public:
    void accept(AThief *thief) override
    {

        thief->action(this);
    }
};

// 銅の宝箱
class BronzeBox : public ABox
{
  public:
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
        std::cout << "開けられた" << std::endl;
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
