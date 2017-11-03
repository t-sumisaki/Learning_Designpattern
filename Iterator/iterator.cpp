#include <iostream>
#include <vector>

class Book {
private:
    std::string m_name;
public:
    void setName(std::string name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
};

class IBookIterator {
public:
    virtual bool isLast() = 0;
    virtual Book next() = 0;
};

class IBookAggregate {
public:
    virtual IBookIterator* iterator() = 0;
};

class BookShelf : public IBookAggregate {
private:
    std::vector<Book> m_books;
    int m_bookNum;

public:
    BookShelf(int maxsize) {
        m_books.resize(maxsize);
        m_bookNum = 0;
    }

    Book getBookAt(int index) {
        return m_books[index];
    }

    void appendBook(Book book) {
        m_books[m_bookNum] = book;
        ++m_bookNum;
    }

    int getBookNum() {
        return m_bookNum;
    }

    IBookIterator* iterator() override;

};

class BookShelfIterator : public IBookIterator {
private:
    BookShelf m_bookshelf;
    int m_index;

public:
    BookShelfIterator(BookShelf bookshelf): m_index(0), m_bookshelf(bookshelf) {}
    
    bool isLast() override;
    Book next() override;
};

IBookIterator* BookShelf::iterator() {
    return new BookShelfIterator(*this);
}

bool BookShelfIterator::isLast() {
    if (m_index > (m_bookshelf.getBookNum())) {
        return true;
    } else {
        return false;
    }
}
Book BookShelfIterator::next() {
    Book book = m_bookshelf.getBookAt(m_index);
    ++m_index;
    return book;
}

int main() {

    BookShelf bookshelf(5);

    Book book1;
    book1.setName("State Pattern");
    bookshelf.appendBook(book1);

    Book book2;
    book2.setName("Iterator Pattern");
    bookshelf.appendBook(book2);

    Book book3;
    book3.setName("Adapter Pattern");
    bookshelf.appendBook(book3);

    IBookIterator *it = bookshelf.iterator();

    while(!it->isLast()) {
        Book _b = it->next();
        std::cout << _b.getName().c_str() << std::endl;
    }

    return 0;

}
