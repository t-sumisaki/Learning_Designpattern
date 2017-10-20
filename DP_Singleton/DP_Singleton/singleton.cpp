#include <iostream>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }


// Singleton�N���X
class Singleton {
public:

	// �C���X�^���X���擾����
	static Singleton& getInstance() {
		static Singleton* instance = new Singleton();
		return *instance;
	}

	// �l���Z�b�g����
	void setNum(int num) {
		num_ = num;
	}

	// �l���擾����
	int getNum() {
		return num_;
	}

private:
	// �R���X�g���N�^
	// Singleton�̃R���X�g���N�^��Private�ɂ��ĊO������C���X�^���X������Ȃ��悤�ɂ���
	Singleton() {};
	int num_;

};

int main() {

	// Singleton���擾
	Singleton& singleton1 = Singleton::getInstance();
	Singleton& singleton2 = Singleton::getInstance();

	// Singleton1�ɐ��l�����
	singleton1.setNum(10);

	// Singleton1�̒��g���Q��
	std::cout << "Singleton1:" << singleton1.getNum() << std::endl;
	// Singleton2�̒��g���Q��
	std::cout << "Singleton2:" << singleton2.getNum() << std::endl;

	// �X�g�b�p�[�iEnter�������Ƒ����j
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();


	return 0;

}