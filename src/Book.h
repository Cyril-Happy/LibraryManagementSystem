#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    long long book_id;
    std::string name;
    std::string author;
    std::string publish;
    std::string ISBN;
    std::string introduction;
    std::string language;
    double price;
    std::string pub_date;
    int class_id;
    int number; // inventory

public:
    Book();
    Book(long long id, const std::string &name, const std::string &author,
         const std::string &publish, const std::string &ISBN,
         const std::string &intro, const std::string &lang, double price,
         const std::string &date, int classID, int num);
    ~Book();

    // Displays detailed info of the book
    void displayInfo();

    long long getBookId() const;
    // Additional getters/setters can be defined if needed
};

#endif
