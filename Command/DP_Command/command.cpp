#include <iostream>
#include <vector>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

/// <summary>
/// コマンド基底クラス
/// </summary>
class CCommand {
public:
	virtual ~CCommand() {}
	virtual void execute() = 0;
protected:
	/// <summary>
	/// 呼んだ回数をカウント
	/// </summary>
	int m_callCount = 0;
};

/// <summary>
/// キャラクタークラス
/// </summary>
class CCharacter {
public:

	/// <summary>
	/// アニメーション処理
	/// </summary>
	virtual void animationFunc() {
		std::cout << "アニメーション処理" << std::endl;
	}
	/// <summary>
	/// 反映処理
	/// </summary>
	virtual void applyFunc() {
		std::cout << "反映処理" << std::endl;
	}
	/// <summary>
	/// 入力処理
	/// </summary>
	virtual void inputFunc() {
		std::cout << "入力処理" << std::endl;
	}
};

/// <summary>
/// 敵クラスの実装
/// </summary>
class CEnemy : public CCharacter {
	void animationFunc() override {
		std::cout << "Enemy:アニメーション処理" << std::endl;
	}
};


/// <summary>
/// アニメーション処理コマンドの実装
/// </summary>
class CAnimationCommand : public CCommand {
private:
	CCharacter* m_pChara = NULL;

public:
	CAnimationCommand(CCharacter* pChara)
		: m_pChara(pChara) {}

	void execute() override {
		this->m_pChara->animationFunc();
		// 呼んだ回数を出力
		std::cout << "Call count" << ++this->m_callCount << std::endl;
	}
};

// 反映処理コマンドの実装
class CApplyCommand : public CCommand {
private:
	CCharacter* m_pChara = NULL;

public:
	CApplyCommand(CCharacter* pChara)
		: m_pChara(pChara) {}

	virtual void execute() override {
		this->m_pChara->applyFunc();
		// 読んだ回数を出力
		std::cout << "Call count" << ++this->m_callCount << std::endl;
	}
};


// 入力処理コマンドの実装
class CInputCommand : public CCommand {
private:
	CCharacter* m_pChara = NULL;

public:
	CInputCommand(CCharacter* pChara)
		: m_pChara(pChara) {}
	
	void execute() override {
		this->m_pChara->inputFunc();
	}
};


/// <summary>
/// 命令実行用クラス
/// </summary>
class CInvoker {
private:
	// 命令群
	std::vector<CCommand*> m_commands;

public:
	// 命令の追加
	void add(CCommand* pCommand) {
		this->m_commands.push_back(pCommand);
	}

	// 命令の実行
	void execute() {
		for (CCommand* pCommand : this->m_commands) {
			pCommand->execute();
		}
	}
};



int main() {

	// キャラクターの生成
	CCharacter* pChara = new CCharacter();

	// アニメーション処理命令の生成
	CCommand* pAnimeCommand = new CAnimationCommand(pChara);

	// 反映処理命令の生成
	CCommand* pApplyCommand = new CApplyCommand(pChara);




	// 命令起動者(Invoker)を生成し
	// アニメーションと反映の命令を取り付ける
	CInvoker* pInvoker = new CInvoker();

	pInvoker->add(pAnimeCommand);
	pInvoker->add(pApplyCommand);



	// 起動者を起動
	pInvoker->execute();
	pInvoker->execute();
	pInvoker->execute();

	// 後片付け
	SAFE_DELETE(pInvoker);
	SAFE_DELETE(pAnimeCommand);
	SAFE_DELETE(pApplyCommand);
	SAFE_DELETE(pChara);

	return 0;
}
