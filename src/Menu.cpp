#include "Menu.h" // Menu.h has included AdminManager.h
#include <iostream>
#include <limits>

Menu::Menu() : isLoggedIn(false), isAdmin(false)
{
}

Menu::~Menu()
{
}

void Menu::displayMainMenu()
{
    if (!isLoggedIn)
    {
        std::cout << "\n---------- Main Menu ----------" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "0. Exit (退出)" << std::endl;
    }
    else
    {
        if (isAdmin)
        {
            std::cout << "\n---------- Main Menu ----------" << std::endl;
            std::cout << "1. Logout (退出登录)" << std::endl;
            std::cout << "2. Add Book (添加图书)" << std::endl;
            std::cout << "3. Delete Book (删除图书)" << std::endl;
            std::cout << "4. Search Books (搜索图书)" << std::endl;
            std::cout << "5. Print Books (打印所有图书信息)" << std::endl;
            std::cout << "6. View Lend Logs (查看借还日志)" << std::endl;
            std::cout << "0. Exit (退出)" << std::endl;
        }
        else
        {
            std::cout << "\n---------- Main Menu ----------" << std::endl;
            std::cout << "1. Logout (退出登录)" << std::endl;
            std::cout << "2. Search Books (搜索图书)" << std::endl;
            std::cout << "3. Print Books (打印所有图书信息)" << std::endl;
            std::cout << "4. Lend Book (借书)" << std::endl;
            std::cout << "5. Return Book (还书)" << std::endl;
            std::cout << "0. Exit (退出)" << std::endl;
        }
    }
}

void Menu::login()
{
    // In a real system, you would check username/password
    // Here we just set adminisLoggedIn to true

    // enter user id
    std::cout << "[info]Enter user ID: ";
    long long userId;
    std::cin >> userId;
    // enter password
    std::cout << "[info]Enter password: ";
    std::string password;
    std::cin >> password;
    User user = adminManager.validateLogin(userId, password);
    if (user.getUserId() == 0)
    {
        std::cout << "[info]Invalid login credentials." << std::endl;
        isLoggedIn = false;
    }
    else
    {
        printLine();
        std::cout << "[info]Logged in successfully." << std::endl;
        std::cout << "[info]Welcome, " << user.getRole() << " " << user.getUsername() << "!" << std::endl;
        isLoggedIn = true;
        isAdmin = (user.getRole() == "admin");
        adminManager.loadBookData();
    }
}

void Menu::logout()
{
    isLoggedIn = false;
    isAdmin = false;
    std::cout << "[info]Logged out." << std::endl;
    adminManager.saveBookData();
}
void Menu::switch_based_on_role(int &choice)
{
    if (!isLoggedIn)
    {

        switch (choice)
        {
        case 1:
            login();
            break;
        case 0:
            std::cout << "[info]Exiting..." << std::endl;
            break;
        default:
            std::cout << "[info]Invalid choice." << std::endl;
            break;
        }
    }
    else
    {
        if (isAdmin)
        {
            switch (choice)
            {
            case 1://logout
                logout();
                break;
            case 2://add book
                adminManager.addBook();
                break;
            case 3://delete book
                adminManager.deleteBook();
                break;
            case 4://search book
                adminManager.searchBooks();
                break;
            case 5://print book
                adminManager.printBooks();
                break;
            case 6:
                adminManager.viewLogs();
                break;
            case 0:
                std::cout << "[info]Exiting..." << std::endl;
                break;
            default:
                std::cout << "[info]Invalid choice." << std::endl;
                break;
            }
        }
        else
        {
            switch (choice)
            {
            case 1:
                logout();
                break;
            case 2:
                adminManager.searchBooks();
                break;
            case 3:
                adminManager.printBooks();
                break;
            case 4:
                adminManager.lendBook();
                break;
            case 5:
                adminManager.returnBook();
                break;
            case 0:
                std::cout << "[info]Exiting..." << std::endl;
                break;
            default:
                std::cout << "[info]Invalid choice." << std::endl;
                break;
            }
        }
    }
}
void Menu::run()
{
    adminManager.loadUserData();
    isAdmin = false;
    isLoggedIn = false;
    int choice = -1;
    while (choice != 0)
    {
        displayMainMenu();
        std::cout << "[info]Please choose an option: ";
        while (!(std::cin >> choice))
        {
            // Clear the error flags
            std::cin.clear();
            // Discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[error]Invalid input. Please enter a valid integer choice: ";
        }
        switch_based_on_role(choice);
        printLine();
        std::cout << "[info]Hit <enter> to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}
