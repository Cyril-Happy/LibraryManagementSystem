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
            std::cout << "6. Add Reader (添加读者)" << std::endl;
            std::cout << "7. Delete Reader (删除读者)" << std::endl;
            std::cout << "8. Search Readers (搜索读者)" << std::endl;
            std::cout << "9. Print Readers (打印所有读者信息)" << std::endl;
            std::cout << "10. View Lend Logs (查看借还日志)" << std::endl;
            std::cout << "0. Exit (退出)" << std::endl;
        }
        else
        {
            std::cout << "\n---------- Main Menu ----------" << std::endl;
            std::cout << "1. Logout (退出登录)" << std::endl;
            std::cout << "2. Search Books (搜索图书)" << std::endl;
            std::cout << "3. Print Books (打印所有图书信息)" << std::endl;
            std::cout << "4. Search Readers (搜索读者)" << std::endl;
            std::cout << "5. Print Readers (打印所有读者信息)" << std::endl;
            std::cout << "6. Lend Book (借书)" << std::endl;
            std::cout << "7. Return Book (还书)" << std::endl;
            std::cout << "8. View Lend Logs (查看借还日志)" << std::endl;
            std::cout << "0. Exit (退出)" << std::endl;
        }
    }
}

void Menu::login()
{
    // In a real system, you would check username/password
    // Here we just set adminisLoggedIn to true
    isLoggedIn = true;
    isAdmin = true;
    std::cout << "[info]Logged in successfully." << std::endl;
    adminManager.loadBookData();
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
            case 1:
                logout();
                break;
            case 2:
                adminManager.addBook();
                break;
            case 3:
                adminManager.deleteBook();
                break;
            case 4:
                adminManager.searchBooks();
                break;
            case 5:
                adminManager.printBooks();
                break;
            case 6:
                adminManager.addReader();
                break;
            case 7:
                adminManager.deleteReader();
                break;
            case 8:
                adminManager.searchReaders();
                break;
            case 9:
                adminManager.printReaders();
                break;
            case 10:
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
                adminManager.searchReaders();
                break;
            case 5:
                adminManager.printReaders();
                break;
            case 6:
                adminManager.lendBook();
                break;
            case 7:
                adminManager.returnBook();
                break;
            case 8:
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
    }
}
void Menu::run()
{

    isAdmin = false;
    isLoggedIn = false;
    int choice = -1;
    while (choice != 0)
    {
        displayMainMenu();
        std::cout << "[info]Please choose an option: ";
        std::cin >> choice;
        if (std::cin.fail())
        {
            // Clear error flags
            std::cin.clear();
            // Discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch_based_on_role(choice);
        printLine();
        std::cout << "[info]Hit <enter> to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}
