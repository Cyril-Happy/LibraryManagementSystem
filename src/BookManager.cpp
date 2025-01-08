#include "BookManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Book.h" // Book.h include printBookHeader() and printLine()
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;
// Print a line , its length is equal to the width of the table
// create mapping manually

BookManager::BookManager()
{
}

BookManager::~BookManager()
{
}

// Load book data from ../data/books.csv
void BookManager::loadData()
{
    string filename = "../data/books.csv";
    books = extract_books_from_file(filename);
}

void BookManager::saveData(string filename, vector<Book> books)
{
    ofstream file(filename);
    // ofstream file("../data/books.csv");
    if (!file.is_open())
    {
        cerr << "Error: Could not open file" << endl;
        return;
    }

    file << "Book ID,Name,Author,Publish,ISBN,Language,Price,Pub Date,Class,Quantity" << endl;
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
             << book.getBookType() << ","
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
            {
                bookDistances.push_back({book, 4});
                break;
            };
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
        if (book.second >= 4)
            foundBooks.push_back(book.first);
    }
    return foundBooks;
}

void BookManager::printAllBooks()
{
    displayBooks(books);
}

vector<Book> BookManager::getBooks() const
{
    return books;
}

void BookManager::classifyByLanguage()
{
    unordered_map<string, vector<Book>> languageMap;
    for (const auto &book : books)
    {
        languageMap[book.getLanguage()].push_back(book);
    }
    // save the books to different files based on language
    for (const auto &pair : languageMap)
    {
        string filename = "../data/language/" + pair.first + ".csv";
        // if the language folder does not exist, create it
        string folder = "../data/language/";
        string command = "mkdir -p " + folder;
        system(command.c_str()); // create the folder
        saveData(filename, pair.second);
        cout << "[info]Books saved to " << filename << endl;
    }
}
/*
class_id,class_name
1,Fiction
2,Poetry
3,Drama
4,Sociology
5,Engineering
6,Fine Arts
7,Philosophy
8,Travel Guides
9,Biography
10,Science Fiction
*/
void BookManager::classifyByBookType()
{
    vector<string> BookTypes = extract_strings_from_file("../data/book_types.dat");

    // save the books to different files based on language
    for (const auto &bookType : BookTypes)
    {
        string filename = "../data/BookType/" + bookType + ".csv";
        // if the language folder does not exist, create it
        string folder = "../data/BookType/";
        string command = "mkdir -p " + folder;
        system(command.c_str()); // create the folder
        vector<Book> booksOfType;
        for (const auto &book : books)
        {
            if (book.getBookType() == bookType)
            {
                booksOfType.push_back(book);
            }
        }
        saveData(filename, booksOfType);
        cout << "[info]Books saved to " << filename << endl;
    }
}

void BookManager::viewBooksClassifiedByLanguage()
{
    //  ["English", "Chinese", "French", "Spanish", "Russian"]
    string filename = "../data/languages.dat";
    vector<string> available_languages = extract_strings_from_file(filename);
    string language;
    do
    {

        cout<< "[info]Available Languages: ";
        for (auto &lang : available_languages)
        {
            printf("[%s] ", lang.c_str());
        }
        cout << '\n';
        cout << "[info]Enter the language you want to view: \n";
        cout << "[info]Enter <q> to quit\n"
             << endl;
        cin >> language;
        if (language == "q")
            return;
        available_languages.push_back("Quit");
        language = correctInput(language, available_languages);
        if (language == "quit")
            return;
        cout << "[info]You selected: " << language << endl;
        if (language == "")
        {
            cout << "[info]Invalid language." << endl;
        }
        string filename = "../data/language/" + language + ".csv";
        vector<Book> extracted_books = extract_books_from_file(filename);
        if (extracted_books.size() == 0)
            cout << "[info]No books found in the language " << language << endl;
        else
            displayBooks(extracted_books);
    } while (language == "");
}

void BookManager::viewBooksClassifiedByBookType()
{
    string filename = "../data/book_types.dat";
    vector<string> available_bookTypes = extract_strings_from_file(filename);
    // for(auto &class_name:available_classes){
    //     cout<<class_name<<endl;
    // }
    string bookType;
    do
    {
        cout << "[info]Available BookType: ";
        for (auto &item : available_bookTypes)
        {
            printf("[%s] ", item.c_str());
        }
        cout << '\n';
        cout << "[info]Enter the class name you want to view: \n";
        cout << "[info]Enter <q> to quit\n"
             << endl;

        cin >> bookType;
        if (bookType == "q")
            return;
        available_bookTypes.push_back("quit");
        bookType = correctInput(bookType, available_bookTypes);
        if (bookType == "quit")
            return;
        cout << "[info]You selected: " << bookType << endl;
        if (bookType == "")
        {
            cout << "[info]Invalid class name." << endl;
        }
        string filename = "../data/BookType/" + bookType + ".csv";
        // cout<<"[info]Reading from file: "<<filename<<endl;
        vector<Book> extracted_books = extract_books_from_file(filename);
        if (extracted_books.size() == 0)
            cout << "[info]No books found in the class " << bookType << endl;
        else
            displayBooks(extracted_books);
        std::cout << "[info]Hit <enter> to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    } while (bookType == "");
}

// Helper functions
string correctInput(string input, vector<string> options)
{
    vector<pair<int, string>> scores;
    for (auto &option : options)
    {
        int score = longestCommonSubsequence(input, option);
        if (score >= 2)
            scores.push_back({score, option});
    }

    if (scores.size() == 0)
        return "";
    sort(scores.begin(), scores.end(), greater<pair<int, string>>()); // sort in descending order
    if (scores[0].first == scores[1].first)
    {
        printf("[info] Confusing option. Do you mean [%s] or [%s]?\n", scores[0].second.c_str(), scores[1].second.c_str());
        return "";
    }
    return scores[0].second;
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

void displayBooks(vector<Book> books)
{
    printLine();
    printBookHeader();
    for (auto &book : books)
    {
        book.displayBookData();
    }
    printLine();
}

vector<Book> extract_books_from_file(string filename) // The returned vector may be empty
{
    vector<Book> extracted_books;
    cout << "[info]Reading from file: " << filename << endl;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file" << endl;
        return extracted_books;
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
            string bookType = tokens[8];
            int quantity = stoi(tokens[9]);

            Book book(bookId, name, author, publish, ISBN, language, price, pubDate, bookType, quantity);
            extracted_books.push_back(book);
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
    return extracted_books;
}
// Extract strings from a .dat file that contains one string per line
// Function to extract strings from a file safely
vector<string> extract_strings_from_file(string filename)
{
    vector<string> extracted_strings;
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return extracted_strings;
    }
    string line;
    while (getline(file, line))
    {
        // get rid of space around the string
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        extracted_strings.push_back(line);
    }
    return extracted_strings;
}