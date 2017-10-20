#include <iostream>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_ = NULL; }



// Observer�i�ώ@�ҁj���N���X
class Observer {
public:
	// �ʒm��M
	virtual void update() = 0;
};



// �W�����v����Observer
class JumpAchievementObserver : public Observer {

private:
	// �W�����v�񐔃J�E���g�p
	int m_jumpCount = 0;
	// �W�����v�̎��т��擾�������H
	bool m_jumpAchievement = false;
	// �W�����v�̎��т̂������l
	const int ACHIEVEMENT_JUMP = 10;

public:
	// �ʒm��M
	void update() override {

		// �J�E���g�A�b�v
		++this->m_jumpCount;

		// ���т��܂��������Ă��Ȃ�&�W�����v�񐔂��������l�ɒB�����ꍇ�͎��т��擾
		if (!this->m_jumpAchievement && this->m_jumpCount >= this->ACHIEVEMENT_JUMP) {
			this->subscribeAchievement("Jump!");
			this->m_jumpAchievement = true;
		}	
	}

	// ���ю擾
	void subscribeAchievement(std::string achievement) {

		// NOTE: �{���͎��т̊��N���X������Ă�����ɒu������
		std::cout << "Achievement: " << achievement.c_str() << std::endl;
	}
};

// �v���C���[�N���X
class Player {

private:
	Observer* m_jumpAchievement = NULL;

public:

	void setJumpAchievement(Observer* observer) {
		m_jumpAchievement = observer;
	}

	// �W�����v����
	void jump() {

		// �W�����v���ăJ�E���g�A�b�v
		std::cout << "Jump" << std::endl;

		// Observer���o�^����Ă���Ƃ��AObserver�ɒʒm
		if (m_jumpAchievement) {
			this->m_jumpAchievement->update();
		}
	}
};

/*
int main() {

	// Player�𐶐�
	Player* pPlayer = new Player();

	// �W�����v���їp��Observer
	Observer* jumpAchievementObserver = new JumpAchievementObserver();

	// �W�����v���їp��Observer���Z�b�g����
	pPlayer->setJumpAchievement(jumpAchievementObserver);

	// �W�����v����
	for (int i = 0; i < 15; ++i) {
		pPlayer->jump();
	}


	// ��Еt��
	SAFE_DELETE(pPlayer);
	SAFE_DELETE(jumpAchievementObserver);

	// �X�g�b�p�[�iEnter�������Ƒ����j
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();

	return 0;

}
*/