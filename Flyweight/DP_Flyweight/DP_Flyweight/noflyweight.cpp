#include <iostream>
#include <vector>
#include <map>


#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

class CPrintingType {
private:
	std::string m_str;
public:
	CPrintingType(std::string str)
	: m_str(str){
		std::cout << "Create Instance" << std::endl;
	}
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