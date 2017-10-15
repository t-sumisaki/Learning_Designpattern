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
		: m_str(str) {
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


/// <summary>
/// �󎚐���p�N���X
/// </summary>
class CPrintingFactory {

public:
	/// <summary>
	/// ���͂��󎚂���
	/// </summary>
	/// <param name="str">����</param>
	void print(std::string str) {

		// �󎚃C���X�^���X�ێ��p�̕ϐ�
		CPrintingType* pPrintingType;

		// ���͂̒��������[�v
		for (int i = 0; i < str.length(); ++i) {
			
			// �P�������o��
			std::string s = str.substr(i, 1);

			// �󎚃L���b�V�����ɃC���X�^���X�����݂��邩���ׂ�
			if (m_printingTypes.find(s) == m_printingTypes.end()) {
				// ������PrintingType��������Ȃ������ꍇ
				pPrintingType = new CPrintingType(s);
				m_printingTypes[s] = pPrintingType;
			}
			else {
				// �����̃C���X�^���X������ꍇ���o��
				pPrintingType = m_printingTypes[s];
			}

			// ��
			pPrintingType->print();

		}

	}

	void clear() {
		// �L���b�V�����Ă���󎚂����ׂĔj������
		for (auto itr = this->m_printingTypes.begin(); itr != this->m_printingTypes.end(); ++itr) {
			SAFE_DELETE(itr->second);
		}
		this->m_printingTypes.clear();
	}


private:
	// �󎚃C���X�^���X�L���b�V���p��map
	std::map<std::string, CPrintingType*> m_printingTypes;

};


int main() {
	// �󎚂��镶��
	std::string str = "CCAABCABCCC";
	
	// �󎚐���p�N���X���쐬
	CPrintingFactory* pFactory = new CPrintingFactory();

	// �󎚂���
	pFactory->print(str);
	
	// ��Еt��
	pFactory->clear();
	SAFE_DELETE(pFactory);

	return 0;
}
