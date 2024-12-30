#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <vector>
#include <string>
#include "Book.h"

class BookManager {
private:
    std::vector<Book> books;

public:
    BookManager();
    ~BookManager();

    // Adds a new book
    void addBook();

    // Deletes a book by bookId
    void deleteBook(long long bookId);

    void printBookHeader();
    // Searches books by keyword (for demonstration, only matches bookId as string)
    void searchBooks(const std::string &keyword);

    // Prints all book info
    void printBooks();

    // Loads data from file
    void loadData();
};

#endif
