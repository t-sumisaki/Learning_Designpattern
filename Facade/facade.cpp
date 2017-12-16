#include <iostream>
#include "facade.h"




int main() {

    CharacterManager& manager = CharacterManager::getInstance();

    // Facadeがない場合
    std::cout << "Run normal worker" << std::endl;
    DataLoader loader;
    CharacterBuilder builder;

    auto data = loader.loadParam();
    Character* character = builder.create(data);

    manager.entry(character);
    manager.update();


    std::cout << std::endl;


    // Facadeがある場合
    CharacterFacade* worker = new CharacterFacade();
    character = worker->create();
    manager.update();

	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();


	return 0;

}