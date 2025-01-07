#include "Book.h"
#include <iostream>
#include <iomanip>
// book_id,name,author,publish,ISBN,language,price,pub_date,class_id,quantity


Book::Book()
    : book_id(0), name(""), author(""), publish(""), ISBN(""),
      language(""), price(0.0), pub_date(""), class_id(0), quantity(0)
{
}

Book::Book(long long id, const std::string &n, const std::string &a,
           const std::string &p, const std::string &isbn,
           const std::string &lang, double pr, const std::string &date,
           int c_id, int qty)
    : book_id(id), name(n), author(a), publish(p), ISBN(isbn),
      language(lang), price(pr), pub_date(date), class_id(c_id), quantity(qty)
{
}

Book::~Book()
{
}

void Book::displayBookData()
{
    // in table format 
    // book_id,name,author,publish,ISBN,language,price,pub_date,class_id,quantity 
    // Printing the data
    std::cout << std::setw(5) << book_id
              << std::setw(30) << name
              << std::setw(20) << author
              << std::setw(20) << publish
              << std::setw(20) << ISBN
              << std::setw(15) << language
              << std::setw(15) << price
              << std::setw(15) << pub_date
              << std::setw(12) << class_id
              << std::setw(12) << quantity
              << std::endl;
}

long long Book::getBookId() const
{
    return book_id;
}

std::string Book::getName() const
{
    return name;
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getPublish() const
{
    return publish;
}

std::string Book::getISBN() const
{
    return ISBN;
}

std::string Book::getLanguage() const
{
    return language;
}

double Book::getPrice() const
{
    return price;
}

std::string Book::getPubDate() const
{
    return pub_date;
}

int Book::getClassId() const
{
    return class_id;
}

int Book::getQuantity() const
{
    return quantity;
}

void Book::setName(const std::string &n)
{
    name = n;
}

void Book::setAuthor(const std::string &a)
{
    author = a;
}

void Book::setPublish(const std::string &p)
{
    publish = p;
}

void Book::setISBN(const std::string &isbn)
{
    ISBN = isbn;
}

void Book::setLanguage(const std::string &lang)
{
    language = lang;
}

void Book::setPrice(double pr)
{
    price = pr;
}

void Book::setPubDate(const std::string &date)
{
    pub_date = date;
}

void Book::setClassId(int c_id)
{
    class_id = c_id;
}

void Book::setQuantity(int qty)
{
    quantity = qty;
}



void Book::inputInfo()
{
    // book_id,name,author,publish,ISBN,language,price,pub_date,class_id,quantity
    std::cout << "Enter book ID: ";
    std::cin >> book_id;
    std::cout << "Enter book name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter author: ";
    std::getline(std::cin, author);
    std::cout << "Enter publisher: ";
    std::getline(std::cin, publish);
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, ISBN);
    std::cout << "Enter langeuage: ";
    std::getline(std::cin, language);
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter publication date: ";
    std::cin.ignore();
    std::getline(std::cin, pub_date);
    std::cout << "Enter class ID: ";
    std::cin >> class_id;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
}
