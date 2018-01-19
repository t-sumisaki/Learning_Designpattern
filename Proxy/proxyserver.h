#include <iostream>
#include <map>


// ContentServer用Interface
class IContentServer {
public:
    virtual std::string getContent(std::string url) = 0;
};

// ContentServer実装クラス
class ContentServer : public IContentServer {
public:
    virtual std::string getContent(std::string url) override {
        std::cout << "Response from server --->" << std::endl;
        return "ContentServer::getContent url=" + url;
    }
};

// ContentServer用Proxyクラス
class ContentServerProxy : public IContentServer {
private:
    // サーバインスタンス
    ContentServer *server;
    // キャッシュ用
    std::map<std::string, std::string> cache;
    // キャッシュを使用しないフラグ
    bool nocache;

public:
    // Constructor
    ContentServerProxy() : nocache(false) {}
    // Constructor
    // :param nocache: Trueのとき、キャッシュを利用しない
    ContentServerProxy(bool nocache) : nocache(nocache) {}

    // コンテンツ取得
    virtual std::string getContent(std::string url) override {
        // キャッシュを利用する設定の場合、キャッシュから検索する
        if (!nocache) {
            auto itr = cache.find(url);
            if (itr != cache.end()) {
                // キャッシュ内にデータが見つかった場合、キャッシュから返す
                return itr->second;
            }
        }

        // サーバインスタンスの初期化
        if (server == NULL) {
            server = new ContentServer();
        }
        // サーバインスタンスからコンテンツを取得する
        std::string content = server->getContent(url);

        // キャッシュを利用する設定の倍、キャッシュに保存しておく
        if (!nocache) {
            cache[url] = content;
        }

        return content;

    }
};


