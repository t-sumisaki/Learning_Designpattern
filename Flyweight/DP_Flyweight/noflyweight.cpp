#include <iostream>
#include <vector>
#include <map>


#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

/// <summary>
/// �󎚃N���X
/// </summary>
class CPrintingType {
private:
	/// <summary>
	/// �󎚓��e
	/// </summary>
	std::string m_str;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="str">�󎚓��e</param>
	CPrintingType(std::string str)
	: m_str(str){
		// �C���X�^���X���������ꂽ�^�C�~���O�Ń��b�Z�[�W���o�͂���
		std::cout << "Create Instance" << std::endl;
	}
	/// <summary>
	/// �󎚂��o�͂���
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