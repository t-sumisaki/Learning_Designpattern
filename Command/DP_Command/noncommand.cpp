#include <iostream>
#include <vector>


#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

class CCharacter {
public:
	virtual void update() {
		this->animationFunc();
		this->applyFunc();
	}

	virtual void animationFunc() {
		std::cout << "アニメーション処理" << std::endl;
	}

	virtual void applyFunc() {
		std::cout << "反映処理" << std::endl;
	}
};


int main() {

	CCharacter* pChara = new CCharacter();


	pChara->update();

	SAFE_DELETE(pChara);

	return 0;
}