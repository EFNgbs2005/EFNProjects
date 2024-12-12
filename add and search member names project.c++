#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Member{
    public:
        string firstname, lastname;
    Member(string a, string b){
        firstname = a;
        lastname = b;
    }
};
void add_member();
void search_member();

int main(){
    int choice;
    while(1){
        cout << "WELCOME\n1-Add member\n2-Search member\n3-exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                system("cls");
                add_member();
                break;
            
            case 2:
                system("cls");
                search_member();
                break;

            case 3:
                return 0;
            
            default :
                cout << "Wrong choice!!!\nplease try again\n";
                break;
        }
    }
}

vector <Member> members;

void add_member(){
    string firstname, lastname;

    ofstream Member("add member.txt", ios::app);
    cout << "Enter your first name: ";
    getline(cin, firstname);
    cout << "Enter your last name: ";
    getline(cin, lastname);
    members.emplace_back(firstname, lastname);
    Member << members.back().firstname << " " << members.back().lastname << endl;
    Member.close();
}

void search_member(){
    string firstname, lastname;
    
    cout << "Enter first name do you want to search: ";
    getline(cin, firstname);
    cout << "Enter last name do you want to search: ";
    getline(cin, lastname);

        for (const auto& member : members) {
        if (member.firstname == firstname && member.lastname == lastname) {
            cout << "User founded with " << member.firstname << member.lastname << " .\n";
            return;
        }
    }
    cout << "User not founded.\n" << endl;
}
