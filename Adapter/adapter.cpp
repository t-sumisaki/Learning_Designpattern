#include <iostream>
#include <string>

// Adapter用のInterface
class PrintInterface
{
  public:
    //一重角括弧
    virtual std::string Kakko(std::string str) = 0;
    //二重角括弧
    virtual std::string DaburuKakko(std::string str) = 0;
};

// 英語Printクラス（もとのウラス）
class EnglishPrint
{
  public:
    std::string Brackets(std::string str)
    {
        return ("[" + str + "]");
    }

    std::string DoubleBrackets(std::string str)
    {
        return ("[[" + str + "]]");
    }
};

// インスタンスを持つタイプの日本語Adapter
class JapanesePrint : public PrintInterface
{
  public:
    std::string Kakko(std::string str)
    {
        return (eng_.Brackets(str));
    }

    std::string DaburuKakko(std::string str)
    {
        return (eng_.DoubleBrackets(str));
    }

  private:
    EnglishPrint eng_;
};

int main(void)
{
    std::cout << "Adapter Pattern Sample Start!!" << std::endl;

    //英語命令のクラスをそのまま使った場合
    EnglishPrint eng;
    std::cout << eng.Brackets("Hi!") << std::endl;
    std::cout << eng.DoubleBrackets("Ho!") << std::endl;

    //日本語アダプタを使用した場合
    JapanesePrint jap;
    std::cout << jap.Kakko("こんにちは!") << std::endl;
    std::cout << jap.DaburuKakko("ほー!") << std::endl;

    return 0;
}