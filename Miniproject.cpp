#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================
// CLASS 1: Book
// Represents individual books in the library
// ==========================================
class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    bool getIssueStatus() const { return isIssued; }

    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    void displayBookRow() const {
        cout << left << setw(10) << id 
             << setw(30) << title 
             << setw(25) << author 
             << setw(15) << (isIssued ? "Issued" : "Available") << "\n";
    }
};

// ==========================================
// CLASS 2: Patron
// Represents a library user (e.g., a student)
// ==========================================
class Patron {
private:
    int id;
    string name;
    vector<int> borrowedBookIds; // Tracks IDs of books borrowed by this user

public:
    Patron(int patronId, string patronName) {
        id = patronId;
        name = patronName;
    }

    int getId() const { return id; }
    string getName() const { return name; }

    void borrowBook(int bookId) {
        borrowedBookIds.push_back(bookId);
    }

    void returnBook(int bookId) {
        for (auto it = borrowedBookIds.begin(); it != borrowedBookIds.end(); ++it) {
            if (*it == bookId) {
                borrowedBookIds.erase(it);
                return;
            }
        }
    }

    void displayPatronDetails() const {
        cout << "Patron ID: " << id << " | Name: " << name << "\nBorrowed Book IDs: ";
        if (borrowedBookIds.empty()) {
            cout << "None";
        } else {
            for (int bId : borrowedBookIds) {
                cout << "[" << bId << "] ";
            }
        }
        cout << "\n--------------------------------------------------\n";
    }
};

// ==========================================
// CLASS 3: Library
// Controls interaction between Books and Patrons
// ==========================================
class Library {
private:
    vector<Book> books;
    vector<Patron> patrons;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "✔ Book added successfully!\n";
    }

    void addPatron(int id, string name) {
        patrons.push_back(Patron(id, name));
        cout << "✔ Patron registered successfully!\n";
    }

    void listBooks() const {
        if (books.empty()) {
            cout << "❌ No books in the library inventory.\n";
            return;
        }
        cout << "\n------------------- BOOK INVENTORY -------------------\n";
        cout << left << setw(10) << "Book ID" << setw(30) << "Title" << setw(25) << "Author" << setw(15) << "Status" << "\n";
        cout << "------------------------------------------------------\n";
        for (const auto& book : books) {
            book.displayBookRow();
        }
    }

    void listPatrons() const {
        if (patrons.empty()) {
            cout << "❌ No registered patrons.\n";
            return;
        }
        cout << "\n---------------- REGISTERED PATRONS ----------------\n";
        for (const auto& patron : patrons) {
            patron.displayPatronDetails();
        }
    }

    void checkoutBook(int patronId, int bookId) {
        Patron* targetPatron = nullptr;
        Book* targetBook = nullptr;

        // Find Patron
        for (auto& p : patrons) {
            if (p.getId() == patronId) {
                targetPatron = &p;
                break;
            }
        }

        // Find Book
        for (auto& b : books) {
            if (b.getId() == bookId) {
                targetBook = &b;
                break;
            }
        }

        if (!targetPatron) {
            cout << "❌ Error: Patron ID not found.\n";
            return;
        }
        if (!targetBook) {
            cout << "❌ Error: Book ID not found.\n";
            return;
        }
        if (targetBook->getIssueStatus()) {
            cout << "❌ Error: Book is already checked out by someone else.\n";
            return;
        }

        // Process Transaction
        targetBook->issueBook();
        targetPatron->borrowBook(bookId);
        cout << "✔ Success: '" << targetBook->getTitle() << "' has been issued to " << targetPatron->getName() << ".\n";
    }

    void returnBook(int patronId, int bookId) {
        Patron* targetPatron = nullptr;
        Book* targetBook = nullptr;

        for (auto& p : patrons) {
            if (p.getId() == patronId) {
                targetPatron = &p;
                break;
            }
        }

        for (auto& b : books) {
            if (b.getId() == bookId) {
                targetBook = &b;
                break;
            }
        }

        if (targetPatron && targetBook && targetBook->getIssueStatus()) {
            targetBook->returnBook();
            targetPatron->returnBook(bookId);
            cout << "✔ Success: '" << targetBook->getTitle() << "' has been returned successfully.\n";
        } else {
            cout << "❌ Error: Invalid transaction. Please check ID numbers.\n";
        }
    }
};

// ==========================================
// MAIN FUNCTION
// Houses the Interactive Menu Interface
// ==========================================
int main() {
    Library centralLibrary;
    int choice;

    // Seed dummy data for rapid initial testing
    centralLibrary.addBook(101, "The C++ Programming Language", "Bjarne Stroustrup");
    centralLibrary.addBook(102, "Clean Code", "Robert C. Martin");
    centralLibrary.addPatron(1, "Alice Smith");

    while (true) {
        cout << "\n====================================\n";
        cout << "     LIBRARY MANAGEMENT SYSTEM      \n";
        cout << "====================================\n";
        cout << "1. Add a Book\n";
        cout << "2. View All Books\n";
        cout << "3. Register a Patron (User)\n";
        cout << "4. View All Patrons\n";
        cout << "5. Issue / Checkout Book\n";
        cout << "6. Return a Book\n";
        cout << "7. Exit Application\n";
        cout << "Enter your selection (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "\nThank you for using the Library Management System. Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1: {
                int id;
                string title, author;
                cout << "Enter Book ID (Integer): "; cin >> id;
                cin.ignore(); // Flush newline left over from cin
                cout << "Enter Book Title: "; getline(cin, title);
                cout << "Enter Author Name: "; getline(cin, author);
                centralLibrary.addBook(id, title, author);
                break;
            }
            case 2:
                centralLibrary.listBooks();
                break;
            case 3: {
                int id;
                string name;
                cout << "Enter Patron ID (Integer): "; cin >> id;
                cin.ignore();
                cout << "Enter Patron Name: "; getline(cin, name);
                centralLibrary.addPatron(id, name);
                break;
            }
            case 4:
                centralLibrary.listPatrons();
                break;
            case 5: {
                int pId, bId;
                cout << "Enter Patron ID: "; cin >> pId;
                cout << "Enter Book ID to Issue: "; cin >> bId;
                centralLibrary.checkoutBook(pId, bId);
                break;
            }
            case 6: {
                int pId, bId;
                cout << "Enter Patron ID: "; cin >> pId;
                cout << "Enter Book ID to Return: "; cin >> bId;
                centralLibrary.returnBook(pId, bId);
                break;
            }
            default:
                cout << "❌ Invalid option selected. Please choose between 1 and 7.\n";
        }
    }
    return 0;
}

