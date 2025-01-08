#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <vector>
#include <string>
#include "Book.h"
using namespace std;
vector<string>extract_strings_from_file(string filename); // The returned vector may be empty
int longestCommonSubsequence(const std::string &s1, const std::string &s2);
vector<Book> extract_books_from_file(string filename);
string correctInput(string input, vector<string> options);
void displayBooks(vector<Book> books);
class BookManager
{
private:
    std::vector<Book> books;

public:
    BookManager();
    ~BookManager();

    // Adds a new book
    void addBook();

    // Deletes a book by bookId
    void deleteBook(long long bookId);

    // Searches books by keyword (for demonstration, only matches bookId as string)
    std::vector<Book> searchBooks(int searchType, const string &keyword);

    // Prints all book info
    void printAllBooks();

    // Loads data from file
    void loadData();

    vector<Book> getBooks() const;
    // Saves data to file
    void saveData(string filename, vector<Book> books);
    // 
    void classifyByLanguage();
    void classifyByBookType();
    void viewBooksClassifiedByLanguage();
    void viewBooksClassifiedByBookType();
};

#endif
