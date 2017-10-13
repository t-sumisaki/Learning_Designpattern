#include <iostream>
#include <vector>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

// コマンド基底クラス
class CCommand {
public:
	virtual ~CCommand() {}
	virtual void execute() = 0;
};

// キャラクタークラス
class CCharacter {
public:
	virtual void animationFunc() {
		std::cout << "アニメーション処理" << std::endl;
	}

	virtual void applyFunc() {
		std::cout << "反映処理" << std::endl;
	}
};

// アニメーション処理コマンドの実装
class CAnimationCommand : public CCommand {
private:
	CCharacter* m_pChara = NULL;

public:
	CAnimationCommand(CCharacter* pChara)
		: m_pChara(pChara) {}

	void execute() override {
		this->m_pChara->animationFunc();
	}
};

// 反映処理コマンドの実装
class CApplyCommand : public CCommand {
private:
	CCharacter* m_pChara = NULL;

public:
	CApplyCommand(CCharacter* pChara)
		: m_pChara(pChara) {}

	void execute() override {
		this->m_pChara->applyFunc();
	}
};



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

/*

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

	SAFE_DELETE(pInvoker);
	SAFE_DELETE(pAnimeCommand);
	SAFE_DELETE(pApplyCommand);
	SAFE_DELETE(pChara);

	return 0;
}
*/