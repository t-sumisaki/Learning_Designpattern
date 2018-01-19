#include <iostream>

// ContentServer用Interface
class IContentServer {
public:
    virtual std::string getPrimaryContent() = 0;
    virtual std::string getSecondaryContent() = 0;
    virtual std::string getRawContent() = 0;
};

// ContentServer実装クラス
class ContentServer : public IContentServer {
public:
    // PrimaryContentを取得する
    virtual std::string getPrimaryContent() override {
        return "Primary Content";
    }
    // SecondaryContentを取得する
    virtual std::string getSecondaryContent() override {
        return "Secondary Content";
    }
    // RawContentを取得する
    virtual std::string getRawContent() override {
        return "Raw Content";
    }
};

// ContentServerProxyクラス
class ContentServerProxy : public IContentServer {
private:
    // サーバインスタンス用変数
    ContentServer *server;
public:
    // PrimaryContentを取得する
    virtual std::string getPrimaryContent() override {
        return "Proxy Primary Content";
    }
    // SecondaryContentを取得する
    virtual std::string getSecondaryContent() override {
        return "Proxy Secondary Content";
    }
    // RawContentを取得する
    virtual std::string getRawContent() override {
        // RawContentでは、サーバからのデータを取得するため、サーバのインスタンスを作成する
        if (server == NULL) {
            server = new ContentServer();
        }
        // サーバインスタンスのRawContentを取得して返却する
        return server->getRawContent();
    }
};