#include "Book.h"
#include <iostream>
#include <iomanip>
#include <limits>
// book_id,name,author,publish,ISBN,language,price,pub_date,class,quantity

// prototype for input validation functions
using namespace std;

template <typename T>
bool validatePositiveInput(T &input);
bool validatePositiveDoubleInput(double &input);
bool validateNonEmptyString(std::string &input);
void printLine()
{
    for (int i = 0; i < 170; i++)
        cout << "-";
    cout << endl;
}
void printBookHeader()
{
    printLine();
    cout << setw(5) << "Book ID"
         << setw(28) << "Name"
         << setw(20) << "Author"
         << setw(20) << "Publish"
         << setw(20) << "ISBN"
         << setw(15) << "Language"
         << setw(15) << "Price"
         << setw(15) << "Pub Date"
         << setw(15) << "BookType"
         << setw(12) << "Quantity"
         << endl;
    printLine();
}
Book::Book()
    : book_id(0), name(""), author(""), publish(""), ISBN(""),
      language(""), price(0.0), pub_date(""), bookType(""), quantity(0)
{
}

Book::Book(long long id, const std::string &n, const std::string &a,
           const std::string &p, const std::string &isbn,
           const std::string &lang, double pr, const std::string &date,
           const std::string &btype, int qty)
    : book_id(id), name(n), author(a), publish(p), ISBN(isbn),
      language(lang), price(pr), pub_date(date), bookType(btype), quantity(qty)
{
}

Book::~Book()
{
}

void Book::displayBookData()
{
    // in table format
    // book_id,name,author,publish,ISBN,language,price,pub_date,class,quantity
    // Printing the datalk
    std::cout << std::setw(5) << book_id
              << std::setw(30) << name
              << std::setw(20) << author
              << std::setw(20) << publish
              << std::setw(20) << ISBN
              << std::setw(15) << language
              << std::setw(15) << price
              << std::setw(15) << pub_date
              << std::setw(15) << bookType
              << std::setw(12) << quantity
              << std::endl;
}

long long Book::getBookId() const
{
    return book_id;
}

std::string Book::getName() const
{
    return name;
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getPublish() const
{
    return publish;
}

std::string Book::getISBN() const
{
    return ISBN;
}

std::string Book::getLanguage() const
{
    return language;
}

double Book::getPrice() const
{
    return price;
}

std::string Book::getPubDate() const
{
    return pub_date;
}

std::string Book::getBookType() const
{
    return bookType;
}

int Book::getQuantity() const
{
    return quantity;
}
void Book::modifyBook(Book &book)
{
    std::cout << "Type the number to select the field you want to change: \n";
    std::cout << "1. Book ID\t"
              << "2. Name\t"
              << "3. Author\t"
              << "4. Publisher\t"
              << "5. ISBN\t"
              << "6. Language\t"
              << "7. Price\t"
              << "8. Publication Date\t"
              << "9. BooktType\t"
              << "a. Quantity\t"
              << "q. Quit\n";
    char choice;
    std::cin >> choice;
    switch (choice)
    {
    case '1':
        setBookIdFromInput();
        break;
    case '2':
        setNameFromInput();
        break;
    case '3':
        setAuthorFromInput();
        break;

    case '4':
        setPublishFromInput();
        break;
    case '5':
        setISBNFromInput();
        break;
    case '6':
        setLanguageFromInput();
        break;
    case '7':
        setPriceFromInput();
        break;
    case '8':
        setPubDateFromInput();
        break;
    case '9':
        setBookTypeFromInput();
        break;
    case 'a':
        setQuantityFromInput();
        break;
    case 'q':
        break;
    }
}
void Book::inputInfo()
{
    // book_id,name,author,publish,ISBN,language,price,pub_date,class,quantity
    setBookIdFromInput();
    setNameFromInput();
    setAuthorFromInput();
    setPublishFromInput();
    setISBNFromInput();
    setLanguageFromInput();
    setPriceFromInput();
    setPubDateFromInput();
    setBookTypeFromInput();
    setQuantityFromInput();
    char choice;
    do
    {
        // display the book data
        std::cout << "The book data you entered is: " << std::endl;

        printBookHeader();
        displayBookData();
        std::cout << "Do you want to change the data? (y/n): ";
        std::cin >> choice;
        if (choice == 'y')
        {
            modifyBook(*this);
        }
    } while (choice == 'y');
}
// Function to validate integer input (positive numbers)
template <typename T>
bool validatePositiveInput(T &input)
{
    std::cin >> input;
    if (std::cin.fail() || input <= 0)
    {
        std::cin.clear();                                                   // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "\nInvalid input. Please enter a positive number: ";
        return false;
    }
    return true;
}

// Function to validate double input (positive numbers)
bool validatePositiveDoubleInput(double &input)
{
    std::cin >> input;
    if (std::cin.fail() || input <= 0.0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input in the buffer
        std::cout << "\nInvalid input. Please enter a positive number: ";
        return false;
    }
    return true;
}

// Function to validate non-empty string input
bool validateNonEmptyString(std::string &input)
{
    std::cin >> input;
    if (input.empty())
    {
        std::cout << "\nInput cannot be empty. Please try again: ";
        return false;
    }
    return true;
}
void Book::setBookIdFromInput()
{
    std::cout << "Enter book ID: ";
    while (!validatePositiveInput(book_id))
    {
        std::cout << "Enter book ID: ";
    }
}

void Book::setNameFromInput()
{
    std::cout << "Enter book name: ";
    while (!validateNonEmptyString(name))
    {
        std::cout << "Enter book name: ";
    }
}

void Book::setAuthorFromInput()
{
    std::cout << "Enter author: ";
    while (!validateNonEmptyString(author))
    {
        std::cout << "Enter author: ";
    }
}

void Book::setPublishFromInput()
{
    std::cout << "Enter publisher: ";
    while (!validateNonEmptyString(publish))
    {
        std::cout << "Enter publisher: ";
    }
}

void Book::setISBNFromInput()
{
    std::cout << "Enter ISBN: ";
    while (!validateNonEmptyString(ISBN))
    {
        std::cout << "Enter ISBN: ";
    }
}

void Book::setLanguageFromInput()
{
    std::cout << "Enter language: ";
    while (!validateNonEmptyString(language))
    {
        std::cout << "Enter language: ";
    }
}

void Book::setPriceFromInput()
{
    std::cout << "Enter price: ";
    while (!validatePositiveDoubleInput(price))
    {
        std::cout << "Enter price: ";
    }
}

void Book::setPubDateFromInput()
{
    std::cout << "Enter publication date: ";
    while (!validateNonEmptyString(pub_date))
    {
        std::cout << "Enter publication date: ";
    }
}

void Book::setBookTypeFromInput()
{
    std::cout << "Enter BookType: ";
    while (!validateNonEmptyString(bookType))
    {
        std::cout << "Enter BookType: ";
    }
}

void Book::setQuantityFromInput()
{
    std::cout << "Enter quantity: ";
    while (!validatePositiveInput(quantity))
    {
        std::cout << "Enter quantity: ";
    }
}
