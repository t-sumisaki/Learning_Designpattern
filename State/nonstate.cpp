#include <iostream>


class TreasureBox {

private:
    
    int m_state;
    
public:
    static const int STATE_OPEN = 1;
    static const int STATE_CLOSE = 0;

    TreasureBox() : m_state(STATE_CLOSE) {
    }

    void open() {
        if (m_state == STATE_CLOSE) {
            std::cout << "** Open. **" << std::endl;
            m_state = STATE_OPEN;
            return;
        }
        if (m_state == STATE_OPEN) {
            std::cout << "** Already opened. **" << std::endl;
            return;
        }
    }

    void close() {
        if (m_state == STATE_CLOSE) {
            std::cout << "** Already closed. **" << std::endl;
            return;
        }

        if (m_state == STATE_OPEN) {
            std::cout << "** Close. **" << std::endl;
            m_state = STATE_CLOSE;
            return;
        }
    }

    void showState() {
        std::cout << "(State)" << this->m_state << std::endl;
    }
};

int main() {

    std::cout << "Non state pattern." << std::endl;

    TreasureBox* box = new TreasureBox();

    box->open();
    box->open();

    box->close();
    box->close();

    return 0;

}