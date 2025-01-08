#include "AdminManager.h"
#include <algorithm>

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
    bookManager.saveData("../data/books.csv", bookManager.getBooks());
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
    std::string searchType;
    do
    {
        std::vector<Book> foundBook;
        std::cout << "[info]You can enter the [number] or [the name of the option]\n";
        std::cout << "[info]Search by what? (1: name, 2: author, 3: book ID, q: quit): ";
        std::cin >> searchType;
        if (searchType.size() != 1)
            searchType = correctInput(searchType, {"name", "author", "book ID", "quit"});
        printf("[info]You selected: [%s]\n", searchType.c_str());
        if (searchType == "1" || searchType == "name")
        {
            std::cout << "[info]Enter name of the book: \n";
            std::string keyword;
            std::cin >> keyword;
            foundBook = bookManager.searchBooks(1, keyword);
        }
        else if (searchType == "2" || searchType == "author")
        {
            std::cout << "[info]Enter author of the book: \n";
            std::string keyword;
            std::cin >> keyword;
            foundBook = bookManager.searchBooks(2, keyword);
        }
        else if (searchType == "3" || searchType == "book ID")
        {
            std::cout << "[info]Enter book ID: \n";
            long long keyword;
            std::cin >> keyword;
            foundBook = bookManager.searchBooks(3, std::to_string(keyword));
        }
        else if (searchType == "q" || searchType == "quit")
        {
            std::cout << "[info]Quitting search." << std::endl;
            return;
        }
        else
        {
            std::cout << "[info]Invalid search type." << std::endl;
        }
        if (foundBook.size() == 0)
        {
            std::cout << "[info]No books found." << std::endl;
        }
        else
        {
            // print the top 10 books
            printBookHeader();
            for (int i = 0; i < min((int)foundBook.size(), 100); i++)
            {
                foundBook[i].displayBookData();
                printLine();
            }
        }
        printLine();
    } while (searchType != "q" || searchType != "quit");
}
void AdminManager::printBooks()
{
    bookManager.printAllBooks();
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

void AdminManager::classifyByLanguage()
{
    bookManager.classifyByLanguage();
}

void AdminManager::classifyByBookType()
{
    bookManager.classifyByBookType();
}

void AdminManager::organizeBooks()
{
    string choice;
    do
    {
        printLine();
        std::cout << "[info]You can enter the [number] or [the name of the option]\n";
        std::cout << "[info]Classify books by: (1: language, 2: bookType, q: quit): \n";
        std::cin >> choice;
        if (choice.size() != 1)
            choice = correctInput(choice, {"language", "bookType", "quit"});
        printf("[info]You selected: [%s]\n", choice.c_str());   
        if (choice == "1" || choice == "language")
        {
            classifyByLanguage();
        }
        else if (choice == "2" || choice == "bookType")
        {
            classifyByBookType();
        }
        else if (choice == "q" || choice == "quit")
        {
            std::cout << "[info]Quitting organize books." << std::endl;
            break;
        }
        else
        {
            std::cout << "[info]Invalid choice." << std::endl;
        }
    } while (choice != "q"||choice!="quit");
}
void AdminManager::viewBooks()
{
    string choice;
    do
    {
        printLine();
        std::cout << "[info]Enter the option to view books by: \n";
        std::cout << "[info]You can enter the [number] or [the name of the option]\n";
        std::cout << "1. Language\n";
        std::cout << "2. BookType\n";
        std::cout << "3. All Books\n";
        std::cout << "[info]Enter <q> to quit\n";
        std::cin >> choice;
        if (choice.size() != 1)
            choice = correctInput(choice, {"Language", "BookType", "All Books", "Quit"});
        std::cout<<"[info]You selected: "<<choice<<endl;
        if (choice == "1" || choice == "Language")
        {
            bookManager.viewBooksClassifiedByLanguage();
        }
        else if (choice == "2" || choice == "BookType")
        {
            bookManager.viewBooksClassifiedByBookType();
        }
        else if (choice == "3" || choice == "All Books")
        {
            bookManager.printAllBooks();
        }
        else if (choice == "q" || choice == "Quit")
        {
            std::cout << "[info]Quitting view books\n";
            return;
        }
        else
        {
            std::cout << "[info]Invalid choice\n";
        }
    } while (choice != "q");
}