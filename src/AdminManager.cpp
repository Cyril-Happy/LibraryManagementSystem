#include "AdminManager.h"
#include <iostream>
#include "Book.h"

AdminManager::AdminManager()
{
}

AdminManager::~AdminManager()
{
}

void AdminManager::loadBookData()
{
    bookManager.loadData();
}

void AdminManager::saveBookData()
{
    bookManager.saveData();
}
void AdminManager::addBook()
{
    bookManager.addBook();
    std::cout << "A new book has been added successfully." << std::endl;
}

void AdminManager::deleteBook()
{
    std::cout << "Enter book ID to delete: ";
    long long bookId;
    std::cin >> bookId;
    bookManager.deleteBook(bookId);
    std::cout << "Book deletion attempt completed." << std::endl;
}

void AdminManager::searchBooks()
{
    // search by book name
    std::cout << "Enter keyword to search in book name: ";
    std::string keyword;
    std::cin >> keyword;
    bookManager.searchBooks(keyword);
}

void AdminManager::printBooks()
{
    bookManager.printBooks();
}

void AdminManager::addReader()
{
    // Example of adding a reader
    readerManager.addReader(1, "Alice", "F", "2000-01-01",
                            "Somewhere", "123456",
                            "alice", "alice123");
    std::cout << "A new reader has been added successfully." << std::endl;
}

void AdminManager::deleteReader()
{
    std::cout << "Enter reader ID to delete: ";
    long long readerId;
    std::cin >> readerId;
    readerManager.deleteReader(readerId);
    std::cout << "Reader deletion attempt completed." << std::endl;
}

void AdminManager::searchReaders()
{
    std::cout << "Enter keyword to search in reader info: ";
    std::string keyword;
    std::cin >> keyword;
    readerManager.searchReaders(keyword);
}

void AdminManager::printReaders()
{
    readerManager.printReaders();
}

void AdminManager::viewLogs()
{
    lendManager.viewLogs();
}
void AdminManager::lendBook()
{
    // lendManager.addLend(1, 1, 1, "2024-01-01", "2024-02-01");
    std::cout << "A new lend record has been added successfully." << std::endl;
}
void AdminManager::returnBook()
{
    // lendManager.returnBook(1, "2024-02-01");
    std::cout << "Book return attempt completed." << std::endl;
}
