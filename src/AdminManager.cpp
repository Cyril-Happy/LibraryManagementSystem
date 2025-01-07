#include "AdminManager.h"
#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

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
    std::vector<Book> foundBook = bookManager.searchBooks(3, std::to_string(bookId)); // 3 is search by book ID
    if (foundBook.size() > 0)
        bookManager.deleteBook(bookId);
    else
        std::cout << "[info]Book not found." << std::endl;
    std::cout << "[info]Book deletion attempt completed." << std::endl;
}

void AdminManager::searchBooks()
{
    // choose search by book name or author
    std::vector<Book> foundBook;
    std::cout << "[info]Search by book name or author? (1: name, 2: author, 3: book ID, q: quit): ";
    int searchType;
    std::cin >> searchType;
    if (searchType == 1)
    {
        std::cout << "[info]Enter name of the book: \n";
        std::string keyword;
        std::cin >> keyword;
        foundBook = bookManager.searchBooks(searchType, keyword);
    }
    else if (searchType == 2)
    {
        std::cout << "[info]Enter author of the book: \n";
        std::string keyword;
        std::cin >> keyword;
        foundBook = bookManager.searchBooks(searchType, keyword);
    }
    else if (searchType == 3)
    {
        std::cout << "[info]Enter book ID: \n";
        long long keyword;
        std::cin >> keyword;
        foundBook = bookManager.searchBooks(searchType, std::to_string(keyword));
    }
    else if (searchType == 'q')
    {
        std::cout << "[info]Quitting search." << std::endl;
        return;
    }
    else
    {
        std::cout << "[info]Invalid search type." << std::endl;
        return;
    }
    if (foundBook.size() == 0)
    {
        std::cout << "[info]No books found." << std::endl;
    }
    else
    {
        // print the top 10 books
        printBookHeader();
        for (int i = 0; i < min((int)foundBook.size(), 10); i++)
        {
            foundBook[i].displayBookData();
            printLine();
        }
    }
}
void AdminManager::printBooks()
{
    bookManager.printBooks();
}

void AdminManager::loadUserData()
{
    userManager.loadUserData();
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

User AdminManager::validateLogin(const long long &id, const std::string &password)
{
    return userManager.validateLogin(id, password);
}