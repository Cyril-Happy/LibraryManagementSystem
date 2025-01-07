#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

#include "BookManager.h"
#include "ReaderManager.h"
#include "LendManager.h"

// Manages admin functionalities such as book, reader, and lend management
class AdminManager
{
private:
    BookManager bookManager;
    ReaderManager readerManager;
    LendManager lendManager;

public:
    AdminManager();
    ~AdminManager();

    // Book management
    void loadBookData();
    void saveBookData();
    void addBook();
    void deleteBook();
    void searchBooks();
    void printBooks();

    // Reader management
    void addReader();
    void deleteReader();
    void searchReaders();
    void printReaders();

    // Lend management
    void lendBook();
    void returnBook();
    void viewLogs();
};

#endif
