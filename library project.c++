#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Member {
public:
    string full_name, sign_date, EXP_date;
    int national_code;

    Member(string a, string b, string c, int d) {
        full_name = a;
        sign_date = b;
        EXP_date = c;
        national_code = d;
    }
};

class Book {
public:
    string book_name, writer_name;
    int shabak;
    bool situation = true;

    Book(string name, string writer) {
        book_name = name;
        writer_name = writer;
        shabak = rand() % 9000 + 1000;
    }
};

vector<Member> members;
vector<Book> books;

void add_member() {
    string name, sign_date, EXP_date;
    int national_code;

    cout << "Enter your full name: ";    
    getline(cin, name);
    cout << "Enter your national code: ";
    cin >> national_code;
    cin.ignore();
    cout << "Enter your sign date: ";
    getline(cin, sign_date);
    cout << "Enter your expiration date: ";
    getline(cin, EXP_date);

    members.emplace_back(name, sign_date, EXP_date, national_code);
}

void add_book() {
    string book_name, writer_name;
    cout << "Enter book name: ";
    getline(cin, book_name);
    cout << "Enter book writer name: ";
    getline(cin, writer_name);
    books.emplace_back(book_name, writer_name);
    cout << "Book added with shabak: " << books.back().shabak << endl;
}

void take_book() {
    int shabak;
    cout << "Enter book shabak: ";
    cin >> shabak;

    for (auto& book : books) {
        if (book.shabak == shabak) {
            if (book.situation) {
                cout << "Enjoy this book." << endl;
                book.situation = false;
                return;
            } else {
                cout << "You can't take this book. It is already taken." << endl;
                return;
            }
        }
    }
    cout << "We don't have a book with this shabak." << endl;
}

void take_back_book() {
    int shabak;
    cout << "Enter shabak of your book: ";
    cin >> shabak;

    for (auto& book : books) {
        if (book.shabak == shabak) {
            cout << "Thank you for returning the book." << endl;
            book.situation = true;
            return;
        }
    }
    cout << "No book found with this shabak." << endl;
}

void search_book() {
    string book_name, writer_name;
    cout << "Enter book name: ";
    getline(cin, book_name);
    cout << "Enter writer name: ";
    getline(cin, writer_name);

    for (const auto& book : books) {
        if (book.book_name == book_name && book.writer_name == writer_name) {
            cout << "\nBook founded:" << endl;
            cout << "Shabak = " << book.shabak << endl;
            cout << (book.situation ? "You can take this book." : "Book is reserved. You can't take this book.") << endl;
            return;
        }
    }
    cout << "Book not founded." << endl;
}

int main() {
    srand(time(NULL));
    
    int choice;

    while (true) {
        cout << "\nWelcome\n1-add user\n2-add book\n3-take book\n4-take back book\n5-search\n6-exit" << endl;
        cout << "Enter number of your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                system("cls");
                add_member();
                break;

            case 2:
                system("cls");
                add_book();
                break;

            case 3:
                system("cls");
                take_book();
                break;

            case 4:
                system("cls");
                take_back_book();
                break;

            case 5:
                system("cls");
                search_book();
                break;

            case 6:
                return 0;

            default:
                cout << "Wrong Entry!!!\n";
                break;
        }
    }
}