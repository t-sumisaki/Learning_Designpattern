#include <iostream>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_ = NULL; }


// �v���C���[�N���X
class Player {

private:
	// �W�����v�񐔃J�E���g�p
	int m_jumpCount = 0;
	// �W�����v�̎��т��擾�������H
	bool m_jumpAchievement = false;
	// �W�����v�̎��т̂������l
	const int ACHIEVEMENT_JUMP = 10;

public:

	// �W�����v����
	void jump() {

		// �W�����v���ăJ�E���g�A�b�v
		std::cout << "Jump" << std::endl;
		++this->m_jumpCount;

		// ���т��܂��������Ă��Ȃ�&�W�����v�񐔂��������l�ɒB�����ꍇ�͎��т��擾
		if (!this->m_jumpAchievement && this->m_jumpCount >= this->ACHIEVEMENT_JUMP) {
			this->subscribeAchievement("Jump!");
			this->m_jumpAchievement = true;
		}

	}

	// ���ю擾
	void subscribeAchievement(std::string achievement) {
		std::cout << "Achievement: " << achievement.c_str() << std::endl;
	}

};

/*

int main() {

	// �v���C���[�N���X���쐬
	Player* player = new Player();

	// �W�����v����
	for (int i = 0; i < 15; ++i) {
		player->jump();
	}

	// ��Еt��
	SAFE_DELETE(player);

	// �X�g�b�p�[�iEnter�������Ƒ����j
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();

	return 0;
}
*/