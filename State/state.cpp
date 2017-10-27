#include <iostream>

class State {
public:
    // 開ける
    virtual State* open() = 0;
    // 閉じる
    virtual State* close() = 0;
    //　状態を出力する
    virtual void showState() = 0;
};

// 状態クラス：オープン
class OpenState : public State {
public:
    State* open() override;
    State* close() override;
    void showState() override {
        std::cout << "(State)OpenState" << std::endl;
    }
};

// 状態クラス：クローズ
class CloseState : public State {
public:
    State* open() override;
    State* close() override;
    void showState() override {
        std::cout << "(State)CloseState" << std::endl;
    }
};

State* OpenState::open() {
    std::cout << "** Already opened. **" << std::endl;
    return NULL;
}
State* OpenState::close() {
    std::cout << "** Close. **" << std::endl;
    return new CloseState();
}

State* CloseState::open() {
    std::cout << "** Open. **" << std::endl;
    return new OpenState();
}
State* CloseState::close() {
    std::cout << "** Already closed. **" << std::endl;
    return NULL;
}


// 宝箱クラス
class TreasureBox {
private:
    State* m_state;

public:

    TreasureBox() {
        m_state = new CloseState();
    }

    void open() {
        State* newstate = this->m_state->open();
        if (newstate != NULL) {
            delete m_state;
            m_state = newstate;
        }
    }
    void close() {
        State* newstate = this->m_state->close();
        if (newstate != NULL) {
            delete m_state;
            m_state = newstate;
        }
    }
    void showState() {
        this->m_state->showState();
    }
};



int main() {
    std::cout << "State Pattern" << std::endl;

    TreasureBox* box = new TreasureBox();
    
    box->open();
    box->open();

    box->close();
    box->close();

    return 0;
}