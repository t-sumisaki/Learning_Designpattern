#pragma once

#include <iostream>


// Memento
class Memento {
private:
    int m_num;
public:
    Memento(int num) : m_num(num) {}
    // Memmentoから情報を再取得する
    int getNum() {
        return this->m_num;
    }
};


class NumberContainer {
private:
    // Memento
    Memento* m_default;
    int m_num;
public:
    NumberContainer(int num) {
        this->m_num = num;
        this->overwriteDefault();
    }
    // デフォルト値に戻す
    void restoreDefault() {
        this->m_num = m_default->getNum();
    }
    // デフォルト値を上書き
    void overwriteDefault() {

        this->m_default = new Memento(this->m_num);
    }

    // 数字を設定
    void setNumber(int num) {
        this->m_num = num;
    }
    // 数字を取得
    int getNumber() {
        return this->m_num;
    }

};