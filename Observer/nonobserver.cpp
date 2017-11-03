#include <iostream>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_ = NULL; }


// プレイヤークラス
class Player {

private:
	// ジャンプ回数カウント用
	int m_jumpCount = 0;
	// ジャンプの実績を取得したか？
	bool m_jumpAchievement = false;
	// ジャンプの実績のしきい値
	const int ACHIEVEMENT_JUMP = 10;

public:

	// ジャンプする
	void jump() {

		// ジャンプしてカウントアップ
		std::cout << "Jump" << std::endl;
		++this->m_jumpCount;

		// 実績をまだ解除していない&ジャンプ回数がしきい値に達した場合は実績を取得
		if (!this->m_jumpAchievement && this->m_jumpCount >= this->ACHIEVEMENT_JUMP) {
			this->subscribeAchievement("Jump!");
			this->m_jumpAchievement = true;
		}

	}

	// 実績取得
	void subscribeAchievement(std::string achievement) {
		std::cout << "Achievement: " << achievement.c_str() << std::endl;
	}

};

/*

int main() {

	// プレイヤークラスを作成
	Player* player = new Player();

	// ジャンプする
	for (int i = 0; i < 15; ++i) {
		player->jump();
	}

	// 後片付け
	SAFE_DELETE(player);

	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();

	return 0;
}
*/