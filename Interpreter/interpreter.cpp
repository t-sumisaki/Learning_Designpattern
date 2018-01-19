#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


// 解析用Contextクラス
class Context {
private:
    std::string _input;
    int _output;
public:
    Context(std::string input)
        : _input(input), _output(0) {}
    
    std::string getInput() {
        return _input;
    }
    void setInput(std::string input) {
        _input = input;
    }
    int getOutput() {
        return _output;
    }
    void setOutput(int output) {
        _output = output;
    }
};

// 解析用クラス
class Expression {
public:
    void Interpret(Context* context) {
        if (context->getInput().empty()) {
            return;
        }

        if (context->getInput().find(Nine()) == 0) {
            // 9のときは2文字で表すため、2文字飛ばす
            context->setOutput(context->getOutput() + 9 * getMultiplier());
            context->setInput(context->getInput().substr(2));
        }
        else if (context->getInput().find(Four()) == 0) {
            // 4のときは2文字で表すため、2文字飛ばす
            context->setOutput(context->getOutput() + 4 * getMultiplier());
            context->setInput(context->getInput().substr(2));
        }
        else if (context->getInput().find(Five()) == 0) {
            // 5のときは1文字飛ばす
            context->setOutput(context->getOutput() + 5 * getMultiplier());
            context->setInput(context->getInput().substr(1));
        }

        while(context->getInput().find(One()) == 0) {
            // 1は複数存在する場合があるため、ループでチェックする
            context->setOutput(context->getOutput() + 1 * getMultiplier());
            context->setInput(context->getInput().substr(1));
        }

    }

    virtual std::string One() = 0;
    virtual std::string Four() = 0;
    virtual std::string Five() = 0;
    virtual std::string Nine() = 0;
    virtual int getMultiplier() = 0;
};

// 千の位のローマ数字解析クラス
class ThousandExpression : public Expression {
public:
    std::string One() override {
        return "M";
    }
    std::string Four() override {
        return " ";
    }
    std::string Five() override {
        return " ";
    }
    std::string Nine() override {
        return " ";
    }
    int getMultiplier() override {
        return 1000;
    }
};

// 百の位のローマ数字解析クラス
class HundledExpression : public Expression {
public:
    std::string One() override {
        return "C";
    }
    std::string Four() override {
        return "CD";
    }
    std::string Five() override {
        return "D";
    }
    std::string Nine() override {
        return "CM";
    }
    int getMultiplier() override {
        return 100;
    }
};

// 十の位のローマ数字解析クラス
class TenExpression : public Expression {
public:
    std::string One() override {
        return "X";
    }
    std::string Four() override {
        return "XL";
    }
    std::string Five() override {
        return "C";
    }
    std::string Nine() override {
        return "XC";
    }
    int getMultiplier() override {
        return 10;
    }
};

// 一の位のローマ数字解析クラス
class OneExpression : public Expression {
public:
    std::string One() override {
        return "I";
    }
    std::string Four() override {
        return "IV";
    }
    std::string Five() override {
        return "V";
    }
    std::string Nine() override {
        return "IX";
    }
    int getMultiplier() override {
        return 1;
    }
};


int main() {

    std::cout << "Interpreterによるローマ数字解析サンプル" << std::endl;

    std::string roman = "MCMXVIII";
    Context context(roman);

    // 解析用の構造木にセットする
    std::vector<Expression*> tree;
    tree.push_back(new ThousandExpression());
    tree.push_back(new HundledExpression());
    tree.push_back(new TenExpression());
    tree.push_back(new OneExpression());

    // 構造木をループして解析を行う
    for (auto exp : tree) {
        exp->Interpret(&context);
    }

    // 解答を出力
    std::cout << roman << " = " << context.getOutput() << std::endl;

	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();
    return 0;
}
