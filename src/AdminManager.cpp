#include "AdminManager.h"
#include <iostream>
#include "Book.h"

AdminManager::AdminManager() {
}

AdminManager::~AdminManager() {
}

void AdminManager::addBook() {
    // Example of adding a new book directly
    Book b(1, "C++ Programming (C++编程)", "Stroustrup", 
           "Some Publisher (出版社)", "123-456-789",
           "An introduction to C++ (简介)", "English (英语)",
           59.99, "2024-01-01", 100, 10);
    bookManager.addBook(b);
    std::cout << "A new book has been added successfully." << std::endl;
}

void AdminManager::deleteBook() {
    std::cout << "Enter book ID to delete: ";
    long long bookId;
    std::cin >> bookId;
    bookManager.deleteBook(bookId);
    std::cout << "Book deletion attempt completed." << std::endl;
}

void AdminManager::searchBooks() {
    std::cout << "Enter keyword to search in book ID: ";
    std::string keyword;
    std::cin >> keyword;
    bookManager.searchBooks(keyword);
}

void AdminManager::printBooks() {
    bookManager.printBooks();
}

void AdminManager::addReader() {
    // Example of adding a reader
    readerManager.addReader(1, "Alice", "F", "2000-01-01", 
                            "Somewhere", "123456", 
                            "alice", "alice123");
    std::cout << "A new reader has been added successfully." << std::endl;
}

void AdminManager::deleteReader() {
    std::cout << "Enter reader ID to delete: ";
    long long readerId;
    std::cin >> readerId;
    readerManager.deleteReader(readerId);
    std::cout << "Reader deletion attempt completed." << std::endl;
}

void AdminManager::searchReaders() {
    std::cout << "Enter keyword to search in reader info: ";
    std::string keyword;
    std::cin >> keyword;
    readerManager.searchReaders(keyword);
}

void AdminManager::printReaders() {
    readerManager.printReaders();
}

void AdminManager::viewLogs() {
    lendManager.viewLogs();
}
