#include <iostream>



class IBuilder {
public:
    virtual void makeHeader(std::string& _text, std::string value) = 0;
    virtual void makeText(std::string& _text, std::string value) = 0;
    virtual void makeFooter(std::string& _text, std::string value) = 0;
};

class TextBuilder : public IBuilder {
public:
    void makeHeader(std::string& _text, std::string value) override {
        _text += "**************************************************\n";
        _text += value + "\n";
        _text += "**************************************************\n";
    }

    void makeText(std::string& _text, std::string value) override {
        _text += value + "\n";
    }

    void makeFooter(std::string& _text, std::string value) override {
        _text += "**************************************************\n";
        _text += value + "\n";
        _text += "**************************************************\n";
    }
};

class HtmlBuilder : public IBuilder {
public:
    void makeHeader(std::string& _text, std::string value) override {
        _text += "<!doctype html>\n";
        _text += "<html>\n";
        _text += "<head>>\n";
        _text += "<meta charset='utf-8'>\n";
        _text += "<title>" + value + "</title>\n";
        _text += "</head>\n";
    }
    
    void makeText(std::string& _text, std::string value) override {
        _text += "<body>\n";
        _text += "<p>テスト用ドキュメントです</p>\n";
        _text += "</body>\n";
    }

    void makeFooter(std::string& _text, std::string value) override {
        _text += "<!-- " + value + " -->\n";
        _text += "</html>\n";
    }
};

class Director {
private:
    IBuilder* m_builder;
    std::string m_text;
public:
    const std::string& getText() {
        return m_text;
    }

    void construct(std::string _title, std::string _text, std::string _author) {
        m_text = "";
        m_builder->makeHeader(m_text, _title);
        m_builder->makeText(m_text, _text);
        m_builder->makeFooter(m_text, _author);
    }

    void setBuilder(IBuilder* builder) {
        m_builder = builder;
    }
};


int main() {

    std::cout << "Builder sample." << std::endl;

    IBuilder* textBuilder = new TextBuilder();
    IBuilder* htmlBuilder = new HtmlBuilder();

    Director director;

    std::cout << "(TextBuilder)" << std::endl;
    director.setBuilder(textBuilder);
    director.construct("Builderパターン", "Builderパターンのサンプル", "sample");
    std::cout << director.getText().c_str() << std::endl;

    std::cout << "(HtmlBuilder)" << std::endl;
    director.setBuilder(htmlBuilder);
    director.construct("Builderパターン", "Builderパターンのサンプル", "sample");
    std::cout << director.getText().c_str() << std::endl;


    // ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
    getchar();
    
    return 0;

}