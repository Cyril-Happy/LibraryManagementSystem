#include "BookManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include<algorithm>
using namespace std;
// Print a line , its length is equal to the width of the table
void printLine()
{
    for (int i = 0; i < 165; i++)
        cout << "-";
    cout << endl;
}
BookManager::BookManager()
{
}

BookManager::~BookManager()
{
}

// // Function to calculate Levenshtein distance (edit distance)
// int levenshteinDistance(const string &s1, const string &s2) {
//     int len1 = s1.size();
//     int len2 = s2.size();
    
//     // Create a matrix to store the distance between substrings
//     vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

//     for (int i = 0; i <= len1; ++i) {
//         for (int j = 0; j <= len2; ++j) {
//             if (i == 0) dp[i][j] = j;  // If s1 is empty, all characters of s2 have to be inserted
//             else if (j == 0) dp[i][j] = i;  // If s2 is empty, all characters of s1 have to be deleted
//             else {
//                 int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
//                 dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
//             }
//         }
//     }

//     return dp[len1][len2];
// }
// Load book data from ../data/books.csv
void BookManager::loadData()
{
    ifstream file("../data/books.csv");
    if (!file.is_open())
    {
        cerr << "Error: Could not open file" << endl;
        return;
    }

    // Skip the first line (header)
    string headerLine;
    getline(file, headerLine);
    string line;
    int recordCount = 0; // Variable to count successfully loaded records
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) // getline(stringstream, string, delimiter)
        {
            tokens.push_back(token);
        }

        // Ensure the line contains exactly 10 tokens
        if (tokens.size() != 10)
        {
            cerr << "Error: Invalid data format in line: " << line << endl;
            continue; // Skip the current line
        }

        try
        {
            long long bookId = stoll(tokens[0]);
            string name = tokens[1];
            string author = tokens[2];
            string publish = tokens[3];
            string ISBN = tokens[4];
            string language = tokens[5];
            double price = stod(tokens[6]);
            string pubDate = tokens[7];
            int classId = stoi(tokens[8]);
            int quantity = stoi(tokens[9]);

            Book book(bookId, name, author, publish, ISBN, language, price, pubDate, classId, quantity);
            books.push_back(book);
            recordCount++;
        }
        catch (const invalid_argument &e) // When the number is not a valid number
        {
            cerr << "Error: Invalid number format in line: " << line << endl;
        }
        catch (const out_of_range &e) // When the number is out of range
        {
            cerr << "Error: Number out of range in line: " << line << endl;
        }
    }

    file.close();
    if (recordCount)
        cout << "Successfully loaded " << recordCount << " book records." << endl;
    else
        cout << "No book records loaded." << endl;
}

void BookManager::saveData()
{
    ofstream file("../data/books.csv");
    if (!file.is_open())
    {
        cerr << "Error: Could not open file" << endl;
        return;
    }

    file << "Book ID,Name,Author,Publish,ISBN,Language,Price,Pub Date,Class ID,Quantity" << endl;
    for (const auto &book : books)
    {
        file << book.getBookId() << ","
             << book.getName() << ","
             << book.getAuthor() << ","
             << book.getPublish() << ","
             << book.getISBN() << ","
             << book.getLanguage() << ","
             << book.getPrice() << ","
             << book.getPubDate() << ","
             << book.getClassId() << ","
             << book.getQuantity() << endl;
    }
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
    cout << setw(5) << "Book ID"
              << setw(28) << "Name"
              << setw(20) << "Author"
              << setw(20) << "Publish"
              << setw(20) << "ISBN"
              << setw(15) << "Language"
              << setw(15) << "Price"
              << setw(15) << "Pub Date"
              << setw(12) << "Class ID"
              << setw(12) << "Quantity"
              << endl;
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

void BookManager::searchBooks(const string &keyword)
{
    printBookHeader();
    for (auto &book : books)
    {
        // Example: Check if book ID in string form matches keyword
        
        string bookIdStr = to_string(book.getBookId());
        if (bookIdStr.find(keyword) != string::npos)// npos indicates no match
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
