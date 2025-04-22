#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    char* author;
    int pageCount;
    int isHardcover;  
    int numChapters;
    
public:
    Book() {
        title = new char[1]; title[0] = '\0';
        author = new char[1]; author[0] = '\0';
        pageCount = 0;
        isHardcover = false;
        numChapters = 0;
    }

    Book(const char* titleInput, const char* authorInput, int pageCountInput, int isHardcoverInput, int numChaptersInput) {
        title = new char[strlen(titleInput) + 1];
        strcpy(title, titleInput);
        
        author = new char[strlen(authorInput) + 1];
        strcpy(author, authorInput);
        
        pageCount = pageCountInput;
        isHardcover = isHardcoverInput;
        numChapters = numChaptersInput;
    }

    ~Book() {
        delete[] title;
        delete[] author;
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Page Count: " << pageCount << endl;
        cout << "Format: " << (isHardcover ? "Hardcover" : "Paperback") << endl;
        cout << "Number of Chapters: " << numChapters << endl;
    }
};

int main() {
    char title[100], author[100];
    int pageCount, isHardcoverInput, numChapters;
    
    cout << "Enter Title of the book: ";
    cin.getline(title, 100);

    cout << "Enter Author of the book: ";
    cin.getline(author,100);  

    cout << "Enter total page count: ";
    cin >> pageCount;

    cout << "Enter number of chapters: ";
    cin >> numChapters;

    Book myBook(title, author, pageCount, isHardcoverInput == 1, numChapters);
    myBook.display();
    return 0;
}
