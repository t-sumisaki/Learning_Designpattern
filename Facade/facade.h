#pragma once
#include <iostream>
#include <vector>

struct CharacterParameter
{
    int Hp;
    int Atk;
    int Def;
};

class Character
{
  private:
    int m_hp;
    int m_atk;
    int m_def;

  public:
    void setHp(int hp)
    {
        this->m_hp = hp;
    }
    int getHp()
    {
        return this->m_hp;
    }
    void setAtk(int atk)
    {
        this->m_atk = atk;
    }
    int getAtk()
    {
        return this->m_atk;
    }
    void setDef(int def)
    {
        this->m_def = def;
    }
    int getDef()
    {
        return this->m_def;
    }
    void update()
    {
        // dummy
        std::cout << "update." << std::endl;
    }
    void printParam()
    {
        std::cout << "HP:" << this->m_hp << std::endl;
        std::cout << "Atk:" << this->m_atk << std::endl;
        std::cout << "Def:" << this->m_def << std::endl;
    }
};

class DataLoader
{
  public:
    CharacterParameter loadParam()
    {
        std::cout << "Load param" << std::endl;
        CharacterParameter param;
        param.Hp = 10;
        param.Atk = 5;
        param.Def = 3;

        return param;
    }
};

class CharacterBuilder
{
  public:
    Character *create(CharacterParameter param)
    {
        std::cout << "Build character" << std::endl;
        Character *character = new Character();
        character->setHp(param.Hp);
        character->setAtk(param.Atk);
        character->setDef(param.Def);

        return character;
    }
};

class CharacterManager
{
  private:
    std::vector<Character *> m_characters;
    CharacterManager() {
        std::cout << "Instantiate CharacterManager" << std::endl;
    }

  public:
    static CharacterManager &getInstance()
    {
        static CharacterManager *manager = new CharacterManager();
        return *manager;
    }
    void entry(Character *character)
    {
        std::cout << "Entry new character." << std::endl;
        this->m_characters.push_back(character);
    }

    void update()
    {
        for (auto *_chara : this->m_characters)
        {
            _chara->update();
        }
    }
};

// 作業Facadeクラス
class CharacterFacade
{
  private:
    DataLoader loader;
    CharacterBuilder builder;

  public:
    Character *create()
    {
        std::cout << "Run Facade worker." << std::endl;

        auto data = loader.loadParam();
        Character *character = builder.create(data);

        CharacterManager::getInstance().entry(character);

        return character;
    }
};