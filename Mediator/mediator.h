#pragma once

#include <iostream>
#include <vector>

class AColleague;

// Mediatorクラス
class AMediator {
public:
    // Colleagueを登録する
    virtual void addColleague(AColleague* colleague) = 0;
    // Colleagueの変更を通知する
    virtual void onCollagueChanged(AColleague* colleague) = 0;
};

// Colleagueクラス
class AColleague {
private:
    AMediator* m_mediator;
public:
    // Mediatorを確保
    void setMediator(AMediator* mediator) {
        this->m_mediator = mediator;
    }
    // Mediatorを通じて変更通知を配信する
    void noticeChanged() {
        if (this->m_mediator != nullptr) {
            this->m_mediator->onCollagueChanged(this);
        }
    }
    // 名前を取得
    virtual std::string getName() = 0;
    // 変更通知を受け取るメソッド
    virtual void receiveChanged(AColleague* colleague) = 0;
};

// 入力モジュール
class InputModule : public AColleague {
public:
    void update() {
        // 省略
        std::cout << "Input anything." << std::endl;
        this->noticeChanged();
    }

    void receiveChanged(AColleague* colleague) override {
        std::cout << "InputModule received from " << colleague->getName().c_str() << std::endl;
    }

    std::string getName() override {
        return "InputModule";
    }
};

// アニメーションモジュール
class AnimModule : public AColleague {
public:
    void receiveChanged(AColleague* colleague) override {
        std::cout << "AnimModule received from " << colleague->getName().c_str() << std::endl;
    }
    std::string getName() override {
        return "AnimModule";
    }
};

// サウンドモジュール
class SoundModule : public AColleague {
public:
    void receiveChanged(AColleague* colleague) override {
        std::cout << "SoundModule received from " << colleague->getName().c_str() << std::endl;
    }

    std::string getName() override {
        return "SoundModule";
    }
};

class CharacterMediator : public AMediator {
private:
    std::vector<AColleague*> m_colleagues;

public:
    void addColleague(AColleague* colleague) override {
        this->m_colleagues.push_back(colleague);
        colleague->setMediator(this);
    }

    void onCollagueChanged(AColleague* colleague) override {
        for (AColleague* _c : this->m_colleagues) {
            if (_c != colleague) {
                _c->receiveChanged(colleague);
            }
        }
    }
};