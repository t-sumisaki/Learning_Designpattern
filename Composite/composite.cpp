#pragma once

#include <iostream>
#include <vector>


class AEntry {
public:
    virtual std::string* getName() = 0;
    virtual int getSize() = 0;
    virtual void showListInfo(const std::string& prefix) = 0;

    void showInfo(const std::string& prefix) {
        std::cout << prefix + "/" + *(getName()) + " [" + std::to_string(getSize()) + "]" << std::endl;
    }
};

class File : public AEntry {
private:
    std::string m_name;
    int m_size;

public:
    File(const std::string& name, int size) {
        m_name = name;
        m_size = size;
    }

    std::string* getName() override {
        return &m_name;
    }
    int getSize() override {
        return m_size;
    }

    void showListInfo(const std::string& prefix) override {
        showInfo(prefix);
    }
};

class Directory : public AEntry {
private:
    std::string m_name;
    std::vector<AEntry*> m_children;

public:
    Directory(const std::string& name) {
        m_name = name;
    }
    std::string* getName() override {
        return &m_name;
    }
    int getSize() override {
        int size = 0;
        int cSize = m_children.size();

        for (int i = 0; i < cSize; ++i) {
            size += m_children[i]->getSize();
        }

        return size;
    }

    void add(AEntry* entry) {
        m_children.push_back(entry);
    }

    void showListInfo(const std::string& prefix) override {
        showInfo(prefix);
        int cSize = m_children.size();
        for (int i = 0; i < cSize; ++i) {
            m_children[i]->showListInfo(*getName());
        }
    }
    void showListInfo() {
        showListInfo("");
    }
};



int main() {

    std::cout << "Composite pattern sample..." << std::endl;

    std::cout << "Create directories" << std::endl;


    Directory root("root");
    Directory bin("bin");
    Directory tmp("tmp");
    Directory usr("usr");

    // ルートディレクトリにディレクトリを追加
    root.add(&bin);
    root.add(&tmp);
    root.add(&usr);

    File vi("vi", 100);
    File git("git", 1000);

    bin.add(&vi);
    bin.add(&git);

    root.showListInfo();

    // ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
    getchar();
    
    return 0;

}