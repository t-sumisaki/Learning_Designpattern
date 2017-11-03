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
		: m_str(str) {
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


/// <summary>
/// 印字制御用クラス
/// </summary>
class CPrintingFactory {

public:
	/// <summary>
	/// 文章を印字する
	/// </summary>
	/// <param name="str">文章</param>
	void print(std::string str) {

		// 印字インスタンス保持用の変数
		CPrintingType* pPrintingType;

		// 文章の長さ分ループ
		for (int i = 0; i < str.length(); ++i) {
			
			// １文字取り出す
			std::string s = str.substr(i, 1);

			// 印字キャッシュ内にインスタンスが存在するか調べる
			if (m_printingTypes.find(s) == m_printingTypes.end()) {
				// 既存のPrintingTypeが見つからなかった場合
				pPrintingType = new CPrintingType(s);
				m_printingTypes[s] = pPrintingType;
			}
			else {
				// 既存のインスタンスがある場合取り出す
				pPrintingType = m_printingTypes[s];
			}

			// 印字
			pPrintingType->print();

		}

	}

	/// <summary>
	/// キャッシュした
	/// </summary>
	void clear() {
		// キャッシュしている印字をすべて破棄する
		for (auto itr = this->m_printingTypes.begin(); itr != this->m_printingTypes.end(); ++itr) {
			SAFE_DELETE(itr->second);
		}
		this->m_printingTypes.clear();
	}


private:
	// 印字インスタンスキャッシュ用のmap
	std::map<std::string, CPrintingType*> m_printingTypes;

};


int main() {
	// 印字する文章
	std::string str = "CCAABCABCCC";
	
	// 印字制御用クラスを作成
	CPrintingFactory* pFactory = new CPrintingFactory();

	// 印字する
	pFactory->print(str);
	
	// 後片付け
	pFactory->clear();
	SAFE_DELETE(pFactory);

	return 0;
}
