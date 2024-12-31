#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int admin_login_id = 3756;
const string admin_login_name = "admin";

int sum_invoice;

class Product{
    public:
        string product_name;
        int product_inventory, product_cost;
    
    Product (string a, int b, int c ){
        product_name = a;
        product_inventory = b;
        product_cost = c; 
    }
};

class Invoice{
    public:
        string buy_product_name;
        int buy_product_inventory, buy_product_cost;
    Invoice(string a, int b, int c){
        buy_product_name = a;
        buy_product_inventory = b;
        buy_product_cost = c;
    }
};

class Sell_list{
    public:
        string sell_product_name;
        int sell_product_inventory, sell_product_cost, sum;
    Sell_list(string a, int b, int c, int d){
        sell_product_name = a;
        sell_product_inventory = b;
        sell_product_cost = c;
        sum = d;
    }
};

vector <Product> products;
vector <Invoice> invoices;
vector <Sell_list> sell_lists;

bool admin_login(){
    string name;
    int id;
    cout << "Enter admin name: ";
    getline(cin, name);
    cout << "Enter admin id: ";
    cin >> id;
    if (name == admin_login_name && id == admin_login_id){
        return true;
    }else{
        return false;
    }
}
void show_product_list(){
    if(products.empty()){
        cout << "Product list is empty.\n"; 
    }else{
        cout << "-product name --> product inventory --> product cost" <<"\n";
        for (const auto& p : products) {
            cout << p.product_name << "\t\t\t" << p.product_inventory << "\t\t\t" << p.product_cost << "\n";
        }
    }
}
void add_product(){
    string name;
    int inventory, cost;
    cout << "Enter product name: ";
    getline(cin, name);
    cout << "Enter product inventory: ";
    cin >> inventory;
    cout << "Enter product cost: ";
    cin >> cost;

    products.emplace_back(name, inventory, cost );
}
void edit_product(){
    string name, new_name;
    int new_inventory, new_cost;
    bool found = false; 
    int x;
    cout << "1- Product name\n2- Product inventory\n3- Product cost\n0- Exit\nWhat do you want to change? ";
    cin >> x;
    cin.ignore();

    switch (x){
        case 1:
            system("cls");
            cout << "Enter product name: ";
            getline(cin, name);
            for (auto& p : products){
                if (name == p.product_name){
                    found = true; 
                    cout << "Enter product new name: ";
                    getline(cin, new_name);
                    p.product_name = new_name;
                    break; 
                }
            }
            if (!found){
                cout << "Product not found.\n";
                break;
            }
            break;

        case 2:
            system("cls");
            cout << "Enter product name do you want to change inventory: ";
            getline(cin, name);
            for (auto& p : products){
                if (name == p.product_name){
                    found = true; 
                    cout << "Enter new inventory do you want to chane it on this product: ";
                    cin >> new_inventory;
                    p.product_inventory = new_inventory;
                    break; 
                }
            }
            if (!found){
                cout << "Product not found.\n";
                break;
            }
            break;
        
        case 3:
            system("cls");
            cout << "Enter product name do you want to change inventory: ";
            getline(cin, name);
            for (auto& p : products){
                if (name == p.product_name){
                    found = true; 
                    cout << "Enter new cost do you want to chane it on this product: ";
                    cin >> new_cost;
                    p.product_cost = new_cost;
                    break; 
                }
            }
            if (!found){
                cout << "Product not found.\n";
                break;
            }
            break;

        case 0:
            system("cls");
            return;

        default:
        cout << "invalid number!!\n";
        break;
    }
}
void delete_product(){
    string name;
    bool found = false; 
    cout << "Enter product name do you want to delete: ";
    cin >> name;
    for (auto p = products.begin(); p != products.end(); p++){
        if (name == p->product_name){
            found = true; 
            products.erase(p);
            cout << "Product deleted successfully.\n";
            break; 
        }
    }
    if (!found){
        cout << "Product not found.\n";
    }
}
void buy_product(){
    string name;
    int inventory = 0, sum;
    bool found = false;
    cout << "Enter name product do you want to buy: ";
    cin >> name;
    for (auto& p : products){
        if (name == p.product_name){
            found = true; 
            cout << "How many do you want? ";
            cin >> inventory;
            p.product_inventory -= inventory;
            sum = (p.product_cost * inventory);
            sum_invoice = sum_invoice + sum;
            invoices.emplace_back(name, inventory, sum);
            sell_lists.emplace_back(name, 0, 0, 0);
            for (auto& I : sell_lists){
                if (name == I.sell_product_name){
                    I.sell_product_inventory += inventory;
                    I.sell_product_cost += sum;

                }
            }
            break;
        }
    }
    if (!found){
        cout << "Product not found.\n";
    }
}
void show_my_invoice(){
    if(invoices.empty()){
        cout << "Invoice list is empty.\n";
    }else{
        for (const auto& I : invoices) {
            cout << I.buy_product_name << "\t\t\t" << I.buy_product_inventory << "\t\t\t" << I.buy_product_cost << "\n";
        }
    }
}
void show_sell_lists(){
    if(sell_lists.empty()){
        cout << "Sell list is empty.\n";
    }else{
        for (auto& S : sell_lists) {
            cout << S.sell_product_name << "\t\t\t" << S.sell_product_inventory << "\t\t\t" << S.sell_product_cost << "\n";
        }
    }
}
int main(){
    int x;

    while(1){
        cout << "1- Admin login\n2- client login\n0- Exit\nEnter your choice: ";
        cin >> x;
        switch (x){
            case 1:{
                int z;
                bool y = true;
                bool login;
                cin.ignore();
                system("cls");
                login = admin_login();
                if (login == false){
                    cout << "invalid login!! _ acces denied.\n";
                    break;
                }
                while(y){
                    cout << "1- Add product\n2- Show products list\n3- Edit product\n4- Delete product\n5- Sell list\n0- Exit admin menu\nEnter your choice: ";
                    cin >> z;
                    switch (z){
                        case 1 : {
                            cin.ignore();
                            system("cls");
                            add_product();
                            break;
                        }
                        case 2: {
                            cin.ignore();
                            system("cls");
                            show_product_list();
                            break;
                        } 
                        case 3: {
                            cin.ignore();
                            system("cls");
                            edit_product();
                            break;
                        }
                        case 4: {
                            cin.ignore();
                            system("cls");
                            delete_product();
                            break;
                        }
                        case 5: {
                            cin.ignore();
                            system("cls");
                            show_sell_lists();
                            break;
                        } 
                        case 0: {
                            system("cls");
                            y = false;
                            break;
                        }

                        default: {
                            cout << "invalid number!!\n";
                            break;
                        }
                    }
                }
            break;
            }

            case 2: {
                system("cls");
                cin.ignore();
                bool y = true;
                int z;
                while(y){
                    cout << "1- Show product list\n2- Buy new product\n3- Show my invoice\n0- Exit\nEnter your choice: ";
                    cin >> z;
                    switch(z){
                        case 1: {
                            system("cls");
                            show_product_list();
                            break;
                        }
                        case 2: {
                            system("cls");
                            show_product_list();
                            buy_product();
                            break;
                        }
                        case 3: {
                            system("cls");
                            show_my_invoice();
                            cout << "Sum of your Invoice = " << sum_invoice << "\n";
                            break;
                        }
                        case 0: {
                            system("cls");
                            y = false;
                            break;
                        }
                        default: {
                            cout << "Invalid number!!\n";
                            break;
                        }
                    }
                }
            break;
            }

            case 0: {
                system("cls");
                invoices.clear();
                return 0;
            }

            default: {
                cout << "invalid number!!\n";
                break;
            }
        }
    }
}