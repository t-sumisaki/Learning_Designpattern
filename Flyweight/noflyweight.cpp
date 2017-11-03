#include <iostream>
#include <vector>
#include <map>


#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

/// <summary>
/// 印字クラス
/// </summary>
class CPrintingType {
private:
	/// <summary>
	/// 印字内容
	/// </summary>
	std::string m_str;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="str">印字内容</param>
	CPrintingType(std::string str)
	: m_str(str){
		// インスタンスが生成されたタイミングでメッセージを出力する
		std::cout << "Create Instance" << std::endl;
	}
	/// <summary>
	/// 印字を出力する
	/// </summary>
	void print() {
		std::cout << "====" << this->m_str.c_str() << "====" << std::endl;
	}
};

/*

int main() {
	std::string str = "AABBCCC";
	CPrintingType* pPrintingType;

	for (int i = 0; i < str.length(); ++i) {
		std::string s = str.substr(i, 1);

		pPrintingType = new CPrintingType(s);

		pPrintingType->print();

		SAFE_DELETE(pPrintingType);
	}

	return 0;

}
*/