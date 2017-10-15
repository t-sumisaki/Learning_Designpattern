#include <iostream>
#include <vector>


#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

/// <summary>
/// �L�����N�^�[�N���X
/// </summary>
class CCharacter {
public:
	/// <summary>
	/// �X�V�����i���t���[���Ă΂��j
	/// </summary>
	virtual void update() {
		this->inputFunc();
		this->animationFunc();
		this->applyFunc();
	}

	virtual void animationFunc() {
		std::cout << "�A�j���[�V��������" << std::endl;
	}

	virtual void applyFunc() {
		std::cout << "���f����" << std::endl;
	}

	virtual void inputFunc() {
		std::cout << "���͏���" << std::endl;
	}
};


/*
int main() {

	CCharacter* pChara = new CCharacter();


	pChara->update();

	SAFE_DELETE(pChara);

	return 0;
}
*/
