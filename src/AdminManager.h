#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

#include "BookManager.h"
#include "UserManager.h"
#include "LendManager.h"

// Manages admin functionalities such as book, User, and lend management
class AdminManager
{
private:
    BookManager bookManager;
    UserManager userManager;
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

    // User management
   void loadUserData(); 
   User validateLogin(const long long &id, const std::string &password);    
   // prompt user to enter log in details
    // Lend management
    void lendBook();
    void returnBook();
    void viewLogs();
};

#endif
