#include <iostream>
#include <vector>


#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

/// <summary>
/// キャラクタークラス
/// </summary>
class CCharacter {
public:
	/// <summary>
	/// 更新処理（毎フレーム呼ばれる）
	/// </summary>
	virtual void update() {
		this->inputFunc();
		this->animationFunc();
		this->applyFunc();
	}

	virtual void animationFunc() {
		std::cout << "アニメーション処理" << std::endl;
	}

	virtual void applyFunc() {
		std::cout << "反映処理" << std::endl;
	}

	virtual void inputFunc() {
		std::cout << "入力処理" << std::endl;
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
