#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <vector>
#include <string>
#include "Book.h"
using namespace std;
class BookManager
{
private:
    std::vector<Book> books;

public:
    BookManager();
    ~BookManager();

    // Adds a new book
    void addBook();

    // Deletes a book by bookId
    void deleteBook(long long bookId);

    // Searches books by keyword (for demonstration, only matches bookId as string)
    std::vector<Book> searchBooks(int searchType, const string &keyword);

    // Prints all book info
    void printBooks();

    // Loads data from file
    void loadDatad();

    vector<Book> getBooks() const;
    // Saves data to file
    void saveData(string filename, vector<Book> books);
    // 
    void classifyByLanguage();
    void classifyByClassId();
};

#endif
