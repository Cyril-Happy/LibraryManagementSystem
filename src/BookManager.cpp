#include "BookManager.h"
#include <iostream>

BookManager::BookManager() {
}

BookManager::~BookManager() {
}

void BookManager::addBook(const Book &book) {
    books.push_back(book);
}

void BookManager::deleteBook(long long bookId) {
    for (auto it = books.begin(); it != books.end();) {
        if (it->getBookId() == bookId) {
            it = books.erase(it);
        } else {
            ++it;
        }
    }
}

void BookManager::searchBooks(const std::string &keyword) {
    for (auto &book : books) {
        // Example: Check if book ID in string form matches keyword
        std::string bookIdStr = std::to_string(book.getBookId());
        if (bookIdStr.find(keyword) != std::string::npos) {
            book.displayInfo();
        }
        // You could also compare other fields (name, author, etc.) if needed
    }
}

void BookManager::printBooks() {
    for (auto &book : books) {
        book.displayInfo();
        std::cout << "------------------------" << std::endl;
    }
}
