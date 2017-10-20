#include <iostream>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }


// Singletonクラス
class Singleton {
public:

	// インスタンスを取得する
	static Singleton& getInstance() {
		static Singleton* instance = new Singleton();
		return *instance;
	}

	// 値をセットする
	void setNum(int num) {
		num_ = num;
	}

	// 値を取得する
	int getNum() {
		return num_;
	}

private:
	// コンストラクタ
	// SingletonのコンストラクタはPrivateにして外部からインスタンス化されないようにする
	Singleton() {};
	int num_;

};

int main() {

	// Singletonを取得
	Singleton& singleton1 = Singleton::getInstance();
	Singleton& singleton2 = Singleton::getInstance();

	// Singleton1に数値を入力
	singleton1.setNum(10);

	// Singleton1の中身を参照
	std::cout << "Singleton1:" << singleton1.getNum() << std::endl;
	// Singleton2の中身を参照
	std::cout << "Singleton2:" << singleton2.getNum() << std::endl;

	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();


	return 0;

}