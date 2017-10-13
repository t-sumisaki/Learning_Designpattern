#include <iostream>
#include <vector>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

// �R�}���h���N���X
class CCommand {
public:
	virtual ~CCommand() {}
	virtual void execute() = 0;
};

// �L�����N�^�[�N���X
class CCharacter {
public:
	virtual void animationFunc() {
		std::cout << "�A�j���[�V��������" << std::endl;
	}

	virtual void applyFunc() {
		std::cout << "���f����" << std::endl;
	}
};

// �A�j���[�V���������R�}���h�̎���
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

// ���f�����R�}���h�̎���
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
	// ���ߌQ
	std::vector<CCommand*> m_commands;

public:
	// ���߂̒ǉ�
	void add(CCommand* pCommand) {
		this->m_commands.push_back(pCommand);
	}

	// ���߂̎��s
	void execute() {
		for (CCommand* pCommand : this->m_commands) {
			pCommand->execute();
		}
	}
};

/*

int main() {

	// �L�����N�^�[�̐���
	CCharacter* pChara = new CCharacter();

	// �A�j���[�V�����������߂̐���
	CCommand* pAnimeCommand = new CAnimationCommand(pChara);


	// ���f�������߂̐���
	CCommand* pApplyCommand = new CApplyCommand(pChara);


	// ���ߋN����(Invoker)�𐶐���
	// �A�j���[�V�����Ɣ��f�̖��߂����t����
	CInvoker* pInvoker = new CInvoker();
	pInvoker->add(pAnimeCommand);
	pInvoker->add(pApplyCommand);

	// �N���҂��N��
	pInvoker->execute();

	SAFE_DELETE(pInvoker);
	SAFE_DELETE(pAnimeCommand);
	SAFE_DELETE(pApplyCommand);
	SAFE_DELETE(pChara);

	return 0;
}
*/