#include "Book.h"
#include <iostream>

Book::Book()
    : book_id(0), name(""), author(""), publish(""), ISBN(""), introduction(""),
      language(""), price(0.0), pub_date(""), class_id(0), number(0) {
}

Book::Book(long long id, const std::string &n, const std::string &a,
           const std::string &p, const std::string &isbn, const std::string &intro,
           const std::string &lang, double pr, const std::string &date,
           int c_id, int num)
    : book_id(id), name(n), author(a), publish(p), ISBN(isbn), introduction(intro),
      language(lang), price(pr), pub_date(date), class_id(c_id), number(num) {
}

Book::~Book() {
}

void Book::displayInfo() {
    std::cout << "Book ID: " << book_id 
              << "\nName: " << name
              << "\nAuthor: " << author
              << "\nPublisher (出版社): " << publish
              << "\nISBN: " << ISBN
              << "\nIntroduction (简介): " << introduction
              << "\nLanguage (语言): " << language
              << "\nPrice: " << price
              << "\nPublication Date: " << pub_date
              << "\nClass ID: " << class_id
              << "\nNumber (库存数量): " << number << std::endl;
}

long long Book::getBookId() const {
    return book_id;
}
