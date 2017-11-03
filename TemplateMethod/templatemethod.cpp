#include <iostream>

// TemplateMethod抽象クラス
class IPrintTemplate
{

  protected:
    virtual void printHeader() = 0;
    virtual void printBody() = 0;
    virtual void printFooter() = 0;

  public:
    void print()
    {
        printHeader();
        printBody();
        printFooter();
    }
};

// TemplateMethod実装クラス
class DocumentPrint : public IPrintTemplate
{

  protected:
    void printHeader() override
    {
        std::string _str;

        _str += "**************************************************\n";
        _str += "* document                                       *\n";
        _str += "**************************************************\n";

        std::cout << _str.c_str() << std::endl;
    }

    void printBody() override
    {
        std::string _str;

        _str += "テスト用ドキュメントです\n";

        std::cout << _str.c_str() << std::endl;
    }

    void printFooter() override
    {
        std::string _str;

        _str += "**************************************************\n";
        _str += "* footer                                         *\n";
        _str += "**************************************************\n";

        std::cout << _str.c_str() << std::endl;
    }
};

// TemplateMethod実装クラス２
class HtmlPrint : public IPrintTemplate
{

  protected:
    void printHeader() override
    {
        std::string _str;

        _str += "<!doctype html>\n";
        _str += "<html>\n";
        _str += "<head>>\n";
        _str += "<meta charset='utf-8'>\n";
        _str += "</head>\n";
        
        std::cout << _str.c_str() << std::endl;
    }

    void printBody() override {
        std::string _str;

        _str += "<body>\n";
        _str += "<p>テスト用ドキュメントです</p>\n";
        _str += "</body>\n";

        std::cout << _str.c_str() << std::endl;
    }

    void printFooter() override {
        std::string _str;

        _str += "</html>\n";

        std::cout << _str.c_str() <<std::endl;
    }

};

int main()
{

    std::cout << "TemplateMethod sample." << std::endl;

    IPrintTemplate *doc = new DocumentPrint();
    IPrintTemplate *html = new HtmlPrint();

    doc->print();
    html->print();

    delete doc;
    delete html;


    // ストッパー（Enterを押すと続く）
	std::cout << "Press ENTER KEY to continue..." << std::endl;
	getchar();


    return 0;
}