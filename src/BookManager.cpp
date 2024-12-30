#include "BookManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>



// Print a line , its length is equal to the width of the table
void printLine()
{
    for (int i = 0; i < 165; i++)
        std::cout << "-";
    std::cout << std::endl;
}
BookManager::BookManager()
{
}

BookManager::~BookManager()
{
}
// Load book data from ../data/books.csv
void BookManager::loadData()
{
    std::ifstream file("../data/books.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file" << std::endl;
        return;
    }

    // Skip the first line (header)
    std::string headerLine;
    std::getline(file, headerLine);
    std::string line;
    int recordCount = 0;// Variable to count successfully loaded records
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        // Ensure the line contains exactly 10 tokens
        if (tokens.size() != 10)
        {
            std::cerr << "Error: Invalid data format in line: " << line << std::endl;
            continue; // Skip the current line
        }

        try
        {
            long long bookId = std::stoll(tokens[0]);
            std::string name = tokens[1];
            std::string author = tokens[2];
            std::string publish = tokens[3];
            std::string ISBN = tokens[4];
            std::string language = tokens[5];
            double price = std::stod(tokens[6]);
            std::string pubDate = tokens[7];
            int classId = std::stoi(tokens[8]);
            int quantity = std::stoi(tokens[9]);

            Book book(bookId, name, author, publish, ISBN, language, price, pubDate, classId, quantity);
            books.push_back(book);
            recordCount++;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: Invalid number format in line: " << line << std::endl;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error: Number out of range in line: " << line << std::endl;
        }
    }

    file.close();
    if(recordCount)std::cout << "Successfully loaded " << recordCount << " book records." << std::endl;
    else std::cout << "No book records loaded." << std::endl;
}
void BookManager::addBook()
{
    Book book;
    book.inputInfo();
    books.push_back(book);
}
void BookManager::printBookHeader()
{
    printLine();
    std::cout<<std::setw(5)<<"Book ID"
             <<std::setw(28)<<"Name"
             <<std::setw(20)<<"Author"
             <<std::setw(20)<<"Publish"
             <<std::setw(20)<<"ISBN"
             <<std::setw(15)<<"Language"
             <<std::setw(15)<<"Price"
             <<std::setw(15)<<"Pub Date"
             <<std::setw(12)<<"Class ID"
             <<std::setw(12)<<"Quantity"
             <<std::endl;
    printLine();
}
void BookManager::deleteBook(long long bookId)
{
    for (auto it = books.begin(); it != books.end();)
    {
        if (it->getBookId() == bookId)
        {
            it = books.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void BookManager::searchBooks(const std::string &keyword)
{
    printBookHeader();
    for (auto &book : books)
    {
        // Example: Check if book ID in string form matches keyword
        std::string bookIdStr = std::to_string(book.getBookId());
        if (bookIdStr.find(keyword) != std::string::npos)
        {
            book.displayBookData();
            printLine();
        }
        // You could also compare other fields (name, author, etc.) if needed
    }
}

void BookManager::printBooks()
{

    printBookHeader();
    for (auto &book : books)
    {
        book.displayBookData();
        printLine();
    }
}
