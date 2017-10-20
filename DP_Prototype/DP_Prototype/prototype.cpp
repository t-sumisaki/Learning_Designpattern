#include <iostream>
#include <vector>

#define SAFE_DELETE(p_) if (p_) { delete p_; p_=NULL; }


class Enemy {
public:
	std::string m_name;

	void printName() {
		std::cout <<  m_name.c_str() << std::endl;
	}

	virtual Enemy* clone() = 0;
};

class Slime : public Enemy {

public:
	Slime() {}
	Slime(std::string name) {
		this->m_name = "Slime:" + name;
	}

	Enemy* clone() override {
		Enemy* _clone = new Slime();

		// ここでパラメータをコピーする
		_clone->m_name = this->m_name + ":clone";

		return _clone;
	}
};

class Wolf : public Enemy {
public:
	Wolf() {}
	Wolf(std::string name) {
		this->m_name = "Wolf:" + name;
	}

	Enemy* clone() override {
		Enemy* _clone = new Wolf();

		// ここでパラメータをコピーする
		_clone->m_name = this->m_name + ":clone";
		return _clone;
	}
};

class Crow : public Enemy {
public:
	Crow() {}
	Crow(std::string name) {
		this->m_name = "Crow:" + name;
	}
	Enemy* clone() override {
		Enemy* _clone = new Crow();

		// ここでパラメータをコピーする
		_clone->m_name = this->m_name + ":clone";

		return _clone;
	}
};


class Spawner {
private:
	std::vector<Enemy*> m_enemies;

public:
	void subscribe(Enemy* enemy) {
		m_enemies.push_back(enemy);
	}

	Enemy* spawn() {
		int idx = std::rand() % m_enemies.size();

		return m_enemies[idx]->clone();
	}
};


int main() {

	Spawner* spawner = new Spawner();

	Slime* protoSlime = new Slime("A");
	spawner->subscribe(protoSlime);

	Wolf* protoWolf = new Wolf("B");
	spawner->subscribe(protoWolf);

	Crow* protoCrow = new Crow("C");
	spawner->subscribe(protoCrow);


	Enemy* _enemy;
	for (int i = 0; i < 10; ++i) {
		_enemy = spawner->spawn();
		_enemy->printName();

		SAFE_DELETE(_enemy);
	}

	SAFE_DELETE(spawner);
	SAFE_DELETE(protoSlime);
	SAFE_DELETE(protoWolf);
	SAFE_DELETE(protoCrow);

	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();

	return 0;


}