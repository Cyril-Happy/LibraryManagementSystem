#include "BookManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Book.h" // Book.h include printBookHeader() and printLine()
#include <algorithm>
#include <vector>
using namespace std;
// Print a line , its length is equal to the width of the table

BookManager::BookManager()
{
}

BookManager::~BookManager()
{
}
// Function to calculate the Longest Common Subsequence (LCS) length
int longestCommonSubsequence(const std::string &s1, const std::string &s2)
{
    int len1 = s1.size();
    int len2 = s2.size();

    // Create a 2D array to store lengths of longest common subsequence
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));

    // Build the dp table
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match, increase length
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); // No match, take max of removing one character from either string
            }
        }
    }

    // The length of the longest common subsequence is stored in dp[len1][len2]
    return dp[len1][len2];
}

// Function to calculate Levenshtein distance (edit distance)
int levenshteinDistance(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    // Case insensitive comparison
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    // Create a matrix to store the distance between substrings
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

    for (int i = 0; i <= len1; ++i)
    {
        for (int j = 0; j <= len2; ++j)
        {
            if (i == 0)
                dp[i][j] = j; // If s1 is empty, all characters of s2 have to be inserted
            else if (j == 0)
                dp[i][j] = i; // If s2 is empty, all characters of s1 have to be deleted
            else
            {
                int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
            }
        }
    }

    return dp[len1][len2];
}
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
        cout << "[info]Successfully loaded " << recordCount << " book records." << endl;
    else
        cout << "[info]No book records loaded." << endl;
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
    cout << "[info]Successfully saved " << books.size() << " book records." << endl;
}
void BookManager::addBook()
{
    Book book;
    book.inputInfo();
    cout << "[info]Do you want to save the book? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        books.push_back(book);
        cout << "[info]Book added successfully!" << endl;
    }
    else
        cout << "[info]Book not saved." << endl;
}

void BookManager::deleteBook(long long bookId)
{
    for (auto it = books.begin(); it != books.end();)
    {
        if (it->getBookId() == bookId)
        {
            printBookHeader();
            (*it).displayBookData();
            printLine();
            cout << "[info]Do you want to delete the book? (y/n): \n";
            char choice;
            cin >> choice;
            if (choice == 'y')
            {
                it = books.erase(it);
                cout << "[info]Book deleted successfully!" << endl;
            }
            else
            {
                cout << "[info]Book not deleted." << endl;
                return;
            }
        }
        else
        {
            ++it;
        }
    }
}

vector<Book> BookManager::searchBooks(int searchType, const string &keyword)
{
    vector<pair<Book, int>> bookDistances;
    for (const auto &book : books)
    {
        if (searchType == 1) // search by name
        {
            int distance = longestCommonSubsequence(keyword, book.getName());
            if (distance >= 2)
                bookDistances.push_back({book, distance});
        }
        else if (searchType == 2) // search by author
        {
            int distance = longestCommonSubsequence(keyword, book.getAuthor());
            bookDistances.push_back({book, distance});
        }
        else if (searchType == 3) // search by bookId
        {
            if (book.getBookId() == stoll(keyword))
                bookDistances.push_back({book, 0});
        }
        else if (searchType == 4) // search by language
        {
            int distance = longestCommonSubsequence(keyword, book.getLanguage());
            bookDistances.push_back({book, distance});
        }
    }
    vector<Book> foundBooks;
    if (bookDistances.size() == 0)
    {
        cout << "[info]No books found with the given keyword: " << keyword << endl;
        return foundBooks;
    }
    sort(bookDistances.begin(), bookDistances.end(), [](const pair<Book, int> &a, const pair<Book, int> &b)
         { return a.second < b.second; });
    for (auto &book : bookDistances)
    {
        if(book.second>=4)foundBooks.push_back(book.first);
    }
    return foundBooks;
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
