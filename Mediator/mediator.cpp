#include <iostream>
#include "mediator.h"


int main() {

    // Mediatorインスタンス
    AMediator* mediator = new CharacterMediator();

    // 各モジュールのインスタンスを生成
    InputModule* input = new InputModule();
    AnimModule* anim = new AnimModule();
    SoundModule* sound = new SoundModule();

    // モジュールをMediatorに登録
    mediator->addColleague(input);
    mediator->addColleague(anim);
    mediator->addColleague(sound);


    // 入力から通知開始
    input->update();

    // ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();


	return 0;

}