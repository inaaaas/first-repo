#include <iostream>
#include <string>
struct Book {
    char title[100];   
    char author[100]; 
    char isbn[20];   
    int available;    
};
const int MAX = 100;
Book library[MAX];
int count  = 0;

void addBook() {
    if (count >= MAX) {
        std::cout << "Can't add books." << std::endl;
        return;
    }
    std::cout << "Enter book title: ";
    std::cin >> library[count].title;
    std::cout << "Enter book author: ";
    std::cin >> library[count].author;
    std::cout << "Enter ISBN: ";
    std::cin >> library[count].isbn;
    library[count].available = 1;
    ++count;
    std::cout << "Book added" << std::endl;
}
void listBooks() {
    if (count == 0) {
        std::cout << "No books." << std::endl;
        return;
    }
    std::cout << "Library books: " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << i + 1 << ". Title: " << library[i].title
         << ", Author: " << library[i].author
         << ", ISBN: " << library[i].isbn
         << "-";
         if (library[i].available == 1) {
            std::cout << "available " << std::endl;
         }
         else {
            std::cout << "borrowed " << std::endl;
         }
    }
} 

void searchBook() {
    char book[MAX]={};
    bool found = false;
    std::cout << "Enter title or author to search: ";
    for (int i = 0; i < count; ++i) {
        if (strstr(library[i].title, book) || strstr(library[i].author, book)) {
            std::cout << "Title: " << library[i].title
                 << ", Author: " << library[i].author
                 << ", ISBN: " << library[i].isbn
                 << " - " << (library[i].available ? "Available" : "Borrowed") << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found." << std::endl;
    }
}
void borrowBook() {
    char isbn[20];
    std::cout << "Enter ISBN of the book to borrow: "; 
    std::cin >> isbn;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            if (library[i].available) {
                library[i].available = 0;
                std::cout << "Book borrowed" << std::endl;
            } else {
                std::cout << "Sorry, this book is already borrowed." << std::endl;
            }
            return;
        }
    }
    std::cout << "Book not found." << std::endl;
}

void returnBook() {
    char isbn[20];
    std::cout << "Enter ISBN of the book to return: ";
    std::cin >>isbn;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            if (!library[i].available) {
                library[i].available = 1;
                std::cout << "Book returned" << std::endl;
            } else {
                std::cout << "This book was not borrowed." << std::endl;
            }
            return;
        }
    }
    std::cout << "Book not found." << std::endl;
}
int main() {
    int choice;
    do {
        std::cout << "\nLibrary Management System" << std::endl;
        std::cout << "1. Add a New Book" << std::endl;
        std::cout << "2. List All Books" << std::endl;
        std::cout << "3. Search for a Book" << std::endl;
        std::cout << "4. Borrow a Book" << std::endl;
        std::cout << "5. Return a Book" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: 
                addBook(); 
                break;
            case 2:     
                listBooks(); 
                break;
            case 3: 
                searchBook(); 
                break;
            case 4: 
                borrowBook(); 
                break;
            case 5: 
                returnBook(); 
                break;
            case 6: 
                std::cout << "Exiting..." << std::endl; 
                break;
            default: 
                std::cout << "Invalid choice.Try again." << std::endl;
        }
    } while (choice != 6);
    return 0;
}
