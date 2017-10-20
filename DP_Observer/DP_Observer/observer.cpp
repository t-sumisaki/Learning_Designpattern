#include <iostream>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_ = NULL; }



// Observer（観察者）基底クラス
class Observer {
public:
	// 通知受信
	virtual void update() = 0;
};



// ジャンプ実績Observer
class JumpAchievementObserver : public Observer {

private:
	// ジャンプ回数カウント用
	int m_jumpCount = 0;
	// ジャンプの実績を取得したか？
	bool m_jumpAchievement = false;
	// ジャンプの実績のしきい値
	const int ACHIEVEMENT_JUMP = 10;

public:
	// 通知受信
	void update() override {

		// カウントアップ
		++this->m_jumpCount;

		// 実績をまだ解除していない&ジャンプ回数がしきい値に達した場合は実績を取得
		if (!this->m_jumpAchievement && this->m_jumpCount >= this->ACHIEVEMENT_JUMP) {
			this->subscribeAchievement("Jump!");
			this->m_jumpAchievement = true;
		}	
	}

	// 実績取得
	void subscribeAchievement(std::string achievement) {

		// NOTE: 本当は実績の基底クラスを作ってそちらに置きたい
		std::cout << "Achievement: " << achievement.c_str() << std::endl;
	}
};

// プレイヤークラス
class Player {

private:
	Observer* m_jumpAchievement = NULL;

public:

	void setJumpAchievement(Observer* observer) {
		m_jumpAchievement = observer;
	}

	// ジャンプする
	void jump() {

		// ジャンプしてカウントアップ
		std::cout << "Jump" << std::endl;

		// Observerが登録されているとき、Observerに通知
		if (m_jumpAchievement) {
			this->m_jumpAchievement->update();
		}
	}
};

/*
int main() {

	// Playerを生成
	Player* pPlayer = new Player();

	// ジャンプ実績用のObserver
	Observer* jumpAchievementObserver = new JumpAchievementObserver();

	// ジャンプ実績用のObserverをセットする
	pPlayer->setJumpAchievement(jumpAchievementObserver);

	// ジャンプする
	for (int i = 0; i < 15; ++i) {
		pPlayer->jump();
	}


	// 後片付け
	SAFE_DELETE(pPlayer);
	SAFE_DELETE(jumpAchievementObserver);

	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();

	return 0;

}
*/