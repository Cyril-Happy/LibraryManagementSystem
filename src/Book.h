#ifndef BOOK_H
#define BOOK_H

#include <string>

void printBookHeader();
void printLine();
class Book
{
private:
    long long book_id;
    std::string name;
    std::string author;
    std::string publish;
    std::string ISBN;
    std::string language;
    double price;
    std::string pub_date;
    int class_id;
    int quantity; // inventory

public:
    Book();
    Book(long long id, const std::string &name, const std::string &author,
         const std::string &publish, const std::string &ISBN,
         const std::string &lang, double price,
         const std::string &date, int classID, int quantity);
    ~Book();

    // Displays detailed info of the book
    void displayBookData();


    // Inputs book info from user
    void inputInfo();
    long long getBookId() const;
    // Additional getters/setters can be defined if needed
    std::string getName() const;
    std::string getAuthor() const;
    std::string getPublish() const;
    std::string getISBN() const;
    std::string getLanguage() const;
    double getPrice() const;
    std::string getPubDate() const;
    int getClassId() const;
    int getQuantity() const;
    
    // modify book info
    void modifyBook(Book &book);
    void setBookIdFromInput();
    void setNameFromInput();
    void setAuthorFromInput();
    void setPublishFromInput();
    void setISBNFromInput();
    void setLanguageFromInput();
    void setPriceFromInput();
    void setPubDateFromInput();
    void setClassIdFromInput();
    void setQuantityFromInput();


};

#endif
