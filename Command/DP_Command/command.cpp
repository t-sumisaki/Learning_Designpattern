#include <iostream>
#include <vector>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }

/// <summary>
/// �R�}���h���N���X
/// </summary>
class CCommand {
public:
	virtual ~CCommand() {}
	virtual void execute() = 0;
protected:
	/// <summary>
	/// �Ă񂾉񐔂��J�E���g
	/// </summary>
	int m_callCount = 0;
};

/// <summary>
/// �L�����N�^�[�N���X
/// </summary>
class CCharacter {
public:

	/// <summary>
	/// �A�j���[�V��������
	/// </summary>
	virtual void animationFunc() {
		std::cout << "�A�j���[�V��������" << std::endl;
	}
	/// <summary>
	/// ���f����
	/// </summary>
	virtual void applyFunc() {
		std::cout << "���f����" << std::endl;
	}
	/// <summary>
	/// ���͏���
	/// </summary>
	virtual void inputFunc() {
		std::cout << "���͏���" << std::endl;
	}
};

/// <summary>
/// �G�N���X�̎���
/// </summary>
class CEnemy : public CCharacter {
	void animationFunc() override {
		std::cout << "Enemy:�A�j���[�V��������" << std::endl;
	}
};


/// <summary>
/// �A�j���[�V���������R�}���h�̎���
/// </summary>
class CAnimationCommand : public CCommand {
private:
	CCharacter* m_pChara = NULL;

public:
	CAnimationCommand(CCharacter* pChara)
		: m_pChara(pChara) {}

	void execute() override {
		this->m_pChara->animationFunc();
		// �Ă񂾉񐔂��o��
		std::cout << "Call count" << ++this->m_callCount << std::endl;
	}
};

// ���f�����R�}���h�̎���
class CApplyCommand : public CCommand {
private:
	CCharacter* m_pChara = NULL;

public:
	CApplyCommand(CCharacter* pChara)
		: m_pChara(pChara) {}

	virtual void execute() override {
		this->m_pChara->applyFunc();
		// �ǂ񂾉񐔂��o��
		std::cout << "Call count" << ++this->m_callCount << std::endl;
	}
};


// ���͏����R�}���h�̎���
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
/// ���ߎ��s�p�N���X
/// </summary>
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
	pInvoker->execute();
	pInvoker->execute();

	// ��Еt��
	SAFE_DELETE(pInvoker);
	SAFE_DELETE(pAnimeCommand);
	SAFE_DELETE(pApplyCommand);
	SAFE_DELETE(pChara);

	return 0;
}
