#include <iostream>
#include <vector>
#include <map>


#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

class CPrintingType {
private:
	std::string m_str;
public:
	CPrintingType(std::string str)
		: m_str(str) {
		std::cout << "Create Instance" << std::endl;
	}
	void print() {
		std::cout << "====" << this->m_str.c_str() << "====" << std::endl;
	}
};


class CPrintingFactory {

public:

	void print(std::string str) {
		CPrintingType* pPrintingType;
		for (int i = 0; i < str.length(); ++i) {
			std::string s = str.substr(i, 1);

			if (m_printingTypes.find(s) == m_printingTypes.end()) {
				pPrintingType = new CPrintingType(s);
				m_printingTypes[s] = pPrintingType;
			}
			else {
				pPrintingType = m_printingTypes[s];
			}

			pPrintingType->print();

		}

	}

	void clear() {
		for (auto itr = this->m_printingTypes.begin(); itr != this->m_printingTypes.end(); ++itr) {
			SAFE_DELETE(itr->second);
		}
	}


private:
	std::map<std::string, CPrintingType*> m_printingTypes;

};
/*

int main() {
	std::string str = "AABBCCC";
	
	CPrintingFactory* pFactory = new CPrintingFactory();

	pFactory->print(str);
	pFactory->clear();

	SAFE_DELETE(pFactory);

	return 0;
}
*/