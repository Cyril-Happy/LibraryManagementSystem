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
}

void AdminManager::deleteBook()
{
    std::cout << "[info]Enter book ID to delete: ";
    long long bookId;
    std::cin >> bookId;
    // make sure to check if the book exists before deleting
    bool is_book_found = bookManager.searchBooks(3,std::to_string(bookId));
    if(is_book_found)bookManager.deleteBook(bookId);
    else std::cout << "[info]Book not found." << std::endl;
    std::cout << "[info]Book deletion attempt completed." << std::endl;
}

void AdminManager::searchBooks()
{
    // choose search by book name or author
    std::cout << "[info]Search by book name or author? (1: name, 2: author, 3: book ID, q: quit): ";
    int searchType;
    std::cin >> searchType;
    if (searchType == 1)
    {
        std::cout<<"[info]Enter name of the book: \n";
        std::string keyword;
        std::cin>>keyword;
        bookManager.searchBooks(searchType,keyword);
    }
    else if (searchType == 2)
    {
        std::cout<<"[info]Enter author of the book: \n";
        std::string keyword;
        std::cin>>keyword;
        bookManager.searchBooks(searchType,keyword);
    }
    else if (searchType == 3)
    {
        std::cout<<"[info]Enter book ID: \n";
        long long keyword;
        std::cin>>keyword;
        bookManager.searchBooks(searchType,std::to_string(keyword));
    }
    else if (searchType == 'q')
    {
        std::cout << "[info]Quitting search." << std::endl;
        return;
    }
    else
    {
        std::cout << "[info]Invalid search type." << std::endl;
    }
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
    std::cout << "[info]A new reader has been added successfully." << std::endl;
}

void AdminManager::deleteReader()
{ std::cout << "[info]Enter reader ID to delete: ";
    long long readerId;
    std::cin >> readerId;
    readerManager.deleteReader(readerId);
    std::cout << "Reader deletion attempt completed." << std::endl;
}

void AdminManager::searchReaders()
{
    std::cout << "[info]Enter keyword to search in reader info: ";
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
    std::cout << "[info]A new lend record has been added successfully." << std::endl;
}
void AdminManager::returnBook()
{
    // lendManager.returnBook(1, "2024-02-01");
    std::cout << "[info]Book return attempt completed." << std::endl;
}
