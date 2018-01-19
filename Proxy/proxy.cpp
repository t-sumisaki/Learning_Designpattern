#include <iostream>
#include "proxy.h"




int main() {

    bool useProxy = true;
    IContentServer* server;
    
    if (useProxy) {
        // Proxyを使用するパターン
        server = new ContentServerProxy();
    } else {
        // Proxyを使用しないパターン
        server = new ContentServer();
    }

    std::string content;

    std::cout << "Primary Contentを取得" << std::endl;
    content = server->getPrimaryContent();
    std::cout << content.c_str() << std::endl;

    std::cout << "SecondaryContentを取得" << std::endl;
    content = server->getSecondaryContent();
    std::cout << content.c_str() << std::endl;

    std::cout << "RawContentを取得" << std::endl;
    content = server->getRawContent();
    std::cout << content.c_str() << std::endl;


	// ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();
    return 0;
}