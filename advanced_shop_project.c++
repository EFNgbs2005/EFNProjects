#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int admin_login_id = 3756;
const string admin_login_name = "admin";

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


class Product{//مدیریت محصولات فروشگاه
private:
    int product_code, product_stock, best_selling_product; // به ترتیب کد محصول و موجودی انبار
    string product_name; // اسم محصول
    double product_cost; //قیمت محصول 
public:
    Product(int a, double b, int c, string d){
    product_code = a;
    product_cost = b;
    product_stock = c;
    product_name = d;
    }
    void setproduct_code(int a){ product_code = a;}
    void setproduct_cost(double b){ if (b >= 0){product_cost = b;}else{cout << "It's can't be negetive" << endl;}}
    void setproduct_stock(int c){ if ( c >= 0){product_stock = c;}else {cout << "It's can't be negative" << endl;}}
    void setproduct_name(string d){ product_name = d;}
    void setbest_selling_product(int e){ best_selling_product = e;}
    int getproduct_code() const{ return product_code;}
    double getproduct_cost() const{ return product_cost;}
    int getproduct_stock() const{ return product_stock;}
    string getproduct_name() const{ return product_name;}
    int getbest_selling_product() const{ return best_selling_product;}
    void print_product(){
        cout << "product name: " << product_name << "\nproduct code: " << product_code << "\nproduct cost: " << product_cost << "\nproduct stock in storage: " << product_stock << endl;
    }
    void update_stock(int amount){
        product_stock += amount; 
    }

    friend ostream& operator<<(ostream& output, const Product& o){
        output << "product name: " << o.product_name << "\nproduct code: " << o.product_code << "\nproduct cost: " << o.product_cost << "\nproduct stock in storage: " << o.product_stock << endl;
        return output;
    }
    friend istream& operator>>(istream& input, Product &i){
        cout << "Enter product name: ";
        input >> i.product_name;
        cout << "Enter product code: ";
        input >> i.product_code;
        cout << "Enter product cost: " ;
        input >> i.product_cost;
        cout << "Enter product stock in storage: ";
        input >> i.product_stock;
        return input;
    }
};
vector <Product> products;

class Customer { // مدیریت مشتریان یک فروشگاه
private:
    int Customer_code, orderss;
    string first_name, last_name, phone_number;
    int most_purchased_customers = 0;
    Product* prod;
public:
    Customer(int a, string b, string c, string d, int e){
        Customer_code = a;
        first_name = b;
        last_name = c;
        phone_number = d;
        orderss = e;
    }
    void setcustomer_code(int a){ Customer_code = a;}
    void setfirstname(string b){ first_name = b; }
    void setlastname(string c){ last_name = c; }
    void setphone_number(string d){ phone_number = d;}
    void setorderss(int e){ orderss = e;}

    string getfirst_name() const{ return first_name; }
    string getlast_name() const{ return last_name; }
    int getcustomer_code() const{ return Customer_code; }
    string getphone_number() const{ return phone_number; }
    int getorderss() const{ return orderss; }
    int getmost_purchased_customers()const { return most_purchased_customers; }
    
    void addmost_purchased_customers(){
        most_purchased_customers += 1;
    }
    void add_order(){
        orderss += 1;
        setorderss(orderss);
    }
    void print_customer(){
        cout << "Customer name: " << first_name << " " << last_name << "\nCustomer code: " << Customer_code << "\nCustomer phone number: " << phone_number ;
    }
    friend ostream& operator<<(ostream& output, const Customer& C){
        output << "Customer name: " << C.first_name << " " << C.last_name << "\nCustomer code: " << C.Customer_code << "\nCustomer phone number: " << C.phone_number << endl;
        return output;
    }
    friend istream& operator>>(istream& input, Customer &i){
        cout << "Enter your first name: ";
        input >> i.first_name;
        cout << "Enter your last name: ";
        input >> i.last_name;
        cout << "Enter your customer code: " ;
        input >> i.Customer_code;
        cout << "Enter your phone number: ";
        input >> i.phone_number;
        return input;
    }
    Customer& operator++(){
        int a = prod->getproduct_stock();
        ++a;
        prod->setproduct_stock(a);
        return *this;
    }
    Customer operator++(int){
        Customer temp = *this;
        int a;
        a = prod->getproduct_stock();
        ++a;
        prod->setproduct_stock(a);
        return temp;
    }
    Customer& operator--(){
        int a = prod->getproduct_stock();
        --a;
        prod->setproduct_stock(a);
        return *this;
    }
    Customer operator--(int){
        Customer temp = *this;
        int a;
        a = prod->getproduct_stock();
        --a;
        prod->setproduct_stock(a);
        return temp;
    }
};
vector <Customer> customers;

class VIPcustomer : public Customer{ // مدیریت مشتریان وی آی پی فروشگاه
private: 
    int score = 0, vipcode;
    float discount_percentage = 0.8;
public:
    VIPcustomer(int a) : Customer(getcustomer_code(), getfirst_name(), getlast_name(), getphone_number(), getorderss()), vipcode(a) {}   
    void setvipcode(int a){vipcode = a;}
    int getvipcode(){return vipcode;}
    int getscore(){ return score;}
    void addpoint(){
        score += 10;
    }
    float applyDiscount(){
        float temp;
        Product* prod;
        temp = (prod->getproduct_cost() * discount_percentage);   
        return temp;     
    }
    void print_vip_customer(){
        cout << "First name : " << getfirst_name() << endl;
        cout << "Last name: " << getlast_name() << endl;
        cout << "Vip customer code: " << getvipcode() << endl;
        cout << "Phone number : " << getphone_number() << endl;
        cout << "Discount on costs : 20% " << endl;
        cout << "your Score : " << getscore() << endl;
    }
    VIPcustomer& operator+=(const VIPcustomer& other) {
        this->score += other.score;
        return *this; 
    }
};
vector <VIPcustomer> vipcustomers;

class Order{ // مدیریت سفارشات
private:
    int order_code, customer_code, sum_of_cost, product_amount, sum_of_invoice = 0;
    string orders;
public:
    Order(int a, int b, int c, int d, string e){
        order_code = a; 
        customer_code = b;
        sum_of_cost = c;
        product_amount = d;
        orders = e;
    }
    int sum_invoice(){
        sum_of_invoice += sum_of_cost;
        return sum_of_invoice;
    }
    int getsum_of_cost() { return sum_of_cost; }
    void setsum_of_cost(int a) { sum_of_cost = a; }
    void print_invoice(){
        cout << "Product name: " << orders;
        cout << "\tProduct amount: " << product_amount;
        cout << "\tProduct code: " << order_code;
        cout << "\tSum of product cost: " << sum_of_cost;    
    }
    bool operator==(const Order& other) const {
        return (this->order_code == other.order_code);
    }
    bool operator!=(const Order& other) const {
        return (*this != other);
    }
    bool operator<(const Order& other) const {
    return this->sum_of_cost < other.sum_of_cost;
    }
    bool operator>(const Order& other) const {
        return this->sum_of_cost > other.sum_of_cost;
    }
};
vector <Order> orders;

class Store{ // مدیریت فروشگاه
private: 
    Product* prod;
    Customer* cust;
    Order* ord;
public:
    void add_product(){ //اضاقه کردن و سیو کردن محصول در فایل 
        string name;
        double cost;
        int code, stock;
        cout << "___Add Product___" << endl;
        cout << "Enter product name: ";
        getline(cin, name);
        for(auto& p: products){
            if(name == p.getproduct_name()){
                cout << "This product already exist!!\n";
                return;
            }
        }
        cout << "Enter product cost: ";
        cin >> cost;
        cout << "Enter product code(4digit): ";
        cin >> code;
        while (to_string(code).length() != 4) {  
            cout << "Product code must be a 4-digit number.\nPlease re-enter(Exit = 0): ";
            cin >> code;            
            if (code == 0){
                return;
            }
        }
        cout << "Enter product stock: ";
        cin >> stock;
        while(stock < 0){
            cout << "Invalid Entery!!\nplease enter again(Exit = 0): ";
            cin >> stock;
            if (stock == 0){
                return;
            }
        }
        products.emplace_back(code, cost, stock, name);
        save_products_to_file();
    }
    void save_products_to_file() { // سیو کردن محصول در فایل 
        ofstream product("products.txt", ios::app);
            if (product.is_open()) {
                product << products.back().getproduct_name() << " "
                        << products.back().getproduct_cost() << " "
                        << products.back().getproduct_stock() << " "
                        << products.back().getproduct_code() << endl;
                product.close();
            } else {
                cout << "Unable to open file." << endl;
            }
        cin.ignore();
    }
    void delete_product(){ //پاک کردن یک محصول 
        string name;
        bool found = false; 
        cout << "___Delete Product___\nEnter product name do you want to delete: ";
        cin >> name;
        for (auto p = products.begin(); p != products.end(); p++){
            if (name == p->getproduct_name()){
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
    void edit_product(){ // ادیت کردن مشخصات یک محصول ثبت شده
        string name, new_name;
        int new_inventory, new_cost, new_code;
        bool found = false; 
        int x;
        cout << "___Edit product__\n1-Product name\n2-Product stock\n3-Product cost\n4-Product code\n5-Exit\nWhat do you want to change? ";
        cin >> x;
        cin.ignore();
        switch (x){
            case 1:
                system("cls");
                cout << "Enter product name: ";
                getline(cin, name);
                for (auto& p : products){
                    if (name == p.getproduct_name()){
                        found = true; 
                        cout << "Enter product new name: ";
                        getline(cin, new_name);
                        p.setproduct_name(new_name);
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
                cout << "Enter product name do you want to change stock: ";
                getline(cin, name);
                for (auto& p : products){
                    if (name == p.getproduct_name()){
                        found = true; 
                        cout << "Enter new stock do you want to chane it on this product: ";
                        cin >> new_inventory;
                        p.setproduct_stock(new_inventory);
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
                    if (name == p.getproduct_name()){
                        found = true; 
                        cout << "Enter new cost do you want to chane it on this product: ";
                        cin >> new_cost;
                        p.setproduct_cost(new_cost);
                        break; 
                    }
                }
                if (!found){
                    cout << "Product not found.\n";
                    break;
                }
                break;
            
            case 4:
                system("cls");
                cout << "Enter product name do you want to change code: ";
                getline(cin, name);
                for (auto& p : products){
                    if (name == p.getproduct_name()){
                        found = true; 
                        cout << "Enter new code do you want to chane it on this product: ";
                        cin >> new_code;
                        p.setproduct_code(new_code);
                        break; 
                    }
                }
                if (!found){
                    cout << "Product not found.\n";
                    break;
                }

                break;

            case 5:
                system("cls");
                return;

            default:
            cout << "invalid number!!\n";
            break;
        }

    }
    void search_product(){ // سرچ کردن بر اساس اسم یک محصول 
        bool found = false; 
        string name;
        cout << "___Serach product___";
        cout << "Enter product name do you want to serach: ";
        getline(cin, name);
        for(auto& p: products){
            if (name == p.getproduct_name()){
                found = true;
                cout << p;
            }else if (!found){
                cout << "Product not found.\n";
                break;
            }
        }
    }
    void add_new_order(){ //اضافه کردن محصول
        bool aproval1 = true, aproval2 = true;
        string product_name, coustomer_first_name, coustomer_last_name;
        int product_amount, temp, best_sell_product, customer_code, sum;

        cout << "Enter your first name: ";
        getline(cin, coustomer_first_name);
        cout << "Enter your last name: ";
        getline(cin, coustomer_last_name);
        cout << "Enter your customer code: ";
        cin >> customer_code;
        for (auto& v : vipcustomers){
            if (v.getfirst_name() == coustomer_first_name && v.getlast_name() == coustomer_last_name && customer_code == v.getcustomer_code()){
                aproval2 = false;
                v.setorderss((v.getorderss() + 1));
                cout << "Enter what do u want to buy: ";
                getline(cin, product_name);
                for(auto& p: products){
                    if(product_name == p.getproduct_name()){
                        float discount_cost;
                        aproval1 = false;
                        cout << "How many do u want to buy: ";
                        cin >> product_amount;
                        best_sell_product = p.getproduct_stock();
                        best_sell_product -= p.getproduct_stock() - product_amount;
                        p.setbest_selling_product(best_sell_product);
                        temp = p.getproduct_stock();
                        temp -= product_amount;
                        p.setproduct_stock(temp);
                        discount_cost = v.applyDiscount();
                        sum = product_amount * discount_cost;
                        v.addpoint();
                        v.addmost_purchased_customers();
                        orders.emplace_back(p.getproduct_code(), v.getcustomer_code(), sum, product_amount, p.getproduct_name());                    
                    }
                }   
                if(aproval1){
                    cout << "Dont have product with this name already!!!";
                    return;
                }
            }else{
                for(auto& c: customers){
                    if (coustomer_first_name == c.getfirst_name() && coustomer_last_name == c.getlast_name() && customer_code == c.getcustomer_code()){
                        aproval2 = false;
                        c.setorderss((c.getorderss() + 1));
                        cout << "Enter what do u want to buy: ";
                        getline(cin, product_name);
                        for(auto& p: products){
                            if(product_name == p.getproduct_name()){
                                aproval1 = false;
                                cout << "How many do u want to buy: ";
                                cin >> product_amount;
                                best_sell_product = p.getproduct_stock();
                                best_sell_product -= p.getproduct_stock() - product_amount;
                                p.setbest_selling_product(best_sell_product);
                                temp = p.getproduct_stock();
                                temp -= product_amount;
                                p.setproduct_stock(temp);
                                sum = product_amount * p.getproduct_cost();
                                c.addmost_purchased_customers();
                                orders.emplace_back(p.getproduct_code(), c.getcustomer_code(), sum, product_amount, p.getproduct_name());                    
                            }
                        }   
                        if(aproval1){
                            cout << "Dont have product with this name already!!!";
                            return;
                        }
                    }
                    if(aproval2){
                        cout << "Dont exists person with this information!!!";
                        return;
                    }

                }
        }  
    }
    };
    void view_registred_orders(){ // نمایش لیست سفارش ها
        cout << "__product name__\t__product_amount__/t__product code\t__product cost__\n";
        for(auto& o: orders){
            o.print_invoice();
        }
    }
    void enlist_customer(){ //اضافه کردن مشتریان 
        while(1){
            int x;
            cout << "Do you want add 1_vip-customer or 2_normal customer(3_Exit): ";
            cin >> x;
            switch (x){
                case 1 :{
                    cin.ignore();
                    system("cls");
                    string first_name, last_name, phone_number;
                    int customer_code, order_list = 0;
                    bool check = true;
                    cout << "Enter your first name: ";
                    getline(cin , first_name);
                    cout << "Enter your last name: ";
                    getline(cin, last_name);
                    cout << "Enter your phone number: ";
                    while(check){
                        getline(cin, phone_number);
                        if (phone_number.length() <= 11){
                            check = false;
                        }else{
                            cout << "Please enter just 11 digit.";
                        }
                    }
                    check = true;
                    cout << "Enter your customer code: ";
                    while(check){
                        cin >> customer_code;
                        if (customer_code >= 1000 && customer_code <= 9999 ){
                            check = false;
                        }else{
                            cout << "Please enter just 4 digit." << endl;
                        }
                    }

                    customers.emplace_back(customer_code, first_name, last_name, phone_number, order_list);
                    vipcustomers.emplace_back(customer_code); 
                    ofstream customer("customers.txt", ios::app);
                    if (customer.is_open()) {
                        customer << "*VIP* "
                                << customers.back().getfirst_name() << " "
                                << customers.back().getlast_name() << " "
                                << customers.back().getcustomer_code() << " "
                                << customers.back().getphone_number() << endl;
                        customer.close();
                    } else {
                        cout << "Unable to open file." << endl;
                    }
                    break;
                }

                case 2 :{
                    cin.ignore();
                    system("cls");
                    string first_name, last_name, phone_number;
                    int customer_code, order_list = 0;
                    bool check = true;
                    cout << "Enter your first name: ";
                    getline(cin , first_name);
                    cout << "Enter your last name: ";
                    getline(cin, last_name);
                    cout << "Enter your phone number: ";
                    while(check){
                        getline(cin, phone_number);
                        if (phone_number.length() <= 11){
                            check = false;
                        }else{
                            cout << "Please enter just 11 digit.";
                        }
                    }
                    check = true;
                    cout << "Enter your customer code: ";
                    while(check){
                        cin >> customer_code;
                        if (customer_code >= 1000 && customer_code <= 9999 ){
                            check = false;
                        }else{
                            cout << "Please enter just 4 digit." << endl;
                        }
                    }
                    customers.emplace_back(customer_code, first_name, last_name, phone_number, order_list);
                    ofstream customer("customers.txt", ios::app);
                    if (customer.is_open()) {
                        customer << customers.back().getfirst_name() << " "
                                << customers.back().getlast_name() << " "
                                << customers.back().getcustomer_code() << " "
                                << customers.back().getphone_number() << endl;
                        customer.close();
                    } else {
                        cout << "Unable to open file." << endl;
                    }
                    break;
                }

                case 3 :{
                    return;
                    break;
                }

                default:{
                    cout << "Invalid Entery!!!";
                    break;
                }
            }
        }

    }
    void search_customer(){ // جستجو در مشتریان 
        bool found = false; 
        string first_name, last_name;
        cout << "___Serach Customer___";
        cout << "Enter Customer first name do you want to serach: ";
        getline(cin, first_name);
        cout << "Enter Customer last name do you want to serach: ";
        getline(cin, last_name);
        for (auto& v : vipcustomers){
            if (v.getfirst_name() == first_name && v.getlast_name() == last_name){
                v.print_vip_customer();
            }else{
                for(auto& p: customers){
                    if (first_name == p.getfirst_name() && last_name == p.getlast_name()){
                        found = true;
                        cout << p;
                    }else if (!found){
                        cout << "Product not found.\n";
                        break;
                    }
                }
            }
        }
    }

};
Store obj; // ساختن یک شی از کلاس store

int main(){
    bool login;
    while(1){
        char answer;
        login = admin_login();
        if (login == false){
            cout << "Acces denied.\nDo u want try again? (Y = Yes, N = No)\n";
            cin >> answer;
            switch(answer){
                case 'Y' :
                    break;

                case 'y' :
                    break;

                case 'n' :
                    return 0;
                    break;

                case 'N' : 
                    return 0;
                    break;

                default :
                    cout << "Invalid Entery !!!";
                    break;

            }
        }else if(login == true){
            break;
        }
        cin.ignore();
    }
    cin.ignore();
    while(login){
        int x;
        cout << "_____Welcome_____\n1-Product Managment\n2-Customer Managment\n3-Order Managment\n4-Shop Reports\n5-Exit\nEnter your choice: ";
        cin >> x;
        switch(x){
            case 1:{
                cin.ignore();
                system("cls");
                bool nothing = true;
                while(nothing){
                    int z;
                    cout << "____Product Managment____\n1-Add product\n2-Delete product\n3-Edit product\n4-Search product\n5-Exit\nEnter your choice: ";
                    cin >> z;
                    switch (z){
                        case 1:{
                            cin.ignore();
                            system("cls");
                            obj.add_product();
                            break;
                        }
                        case 2:{
                            cin.ignore();
                            system("cls");
                            obj.delete_product();
                            obj.save_products_to_file();
                            break;
                        } 
                        case 3:{
                            cin.ignore();
                            system("cls");
                            obj.edit_product();
                            obj.save_products_to_file();
                            break;
                        }
                        case 4:{
                            cin.ignore();
                            system("cls");
                            obj.search_product();
                            break;
                        }
                        case 5:{
                            system("cls");
                            nothing = false;
                            break;
                        }
                        default:{
                            cout << "Invalid Entery!!!";
                            break;
                        }
                    }

                }
                break;
            }   

            case 2:{
                cin.ignore();
                system("cls");
                bool nothing = true;
                while(nothing){
                    int z;
                    cout << "______Customer Managment______\n1-Enlist Customer(Normal & Vip)\n2-Search Customer\n3-Exit\nEnter your choice: ";
                    cin >> z;
                    switch(z){
                        case 1:{
                            obj.enlist_customer();
                            break;
                        }
                        case 2:{
                            obj.search_customer();
                            break;
                        }
                        case 3:{
                            system("cls");
                            nothing = false;
                            break;
                        }
                        default:{
                            cout << "Invalid Entery!!!";
                            break;
                        }
                    }
                }
                break;
            }

            case 3:{
                cin.ignore();
                system("cls");
                bool nothing = true;
                while(nothing){
                    int z;
                    cout << "______Order Managment______\n1-Add new order\n2-View registered orders\n3-Exit\nEnter your choice: ";
                    cin >> z;
                    switch(z){
                        case 1:
                            obj.add_new_order();
                            break;
                        case 2:
                            obj.view_registred_orders();
                            break;
                        case 3:
                            system("cls");
                            nothing = false;
                            break;
                        default:
                            cout << "Invalid Entery!!!";
                            break;
                    }
                }
                break;
            }

            case 4:{
                cin.ignore();
                system("cls");
                bool nothing = true;
                while(nothing){
                    int z;
                    cout << "______Shop Reports______\n1-Show the best selling product\n2-Show customers with the most purchase\n3-Show the most expensive orders\n4-List of products with low stock\n5-Exit\nEnter your choice: ";
                    cin >> z;
                    switch(z){
                        case 1:{
                            int temp;
                            string best_sell_product_name1, best_sell_product_name2 = "";
                            for (size_t i = 0; i < products.size(); i++) {
                                temp = products[i].getbest_selling_product();
                                if ( temp > products[i].getbest_selling_product() ) {
                                    best_sell_product_name1 = products[i].getproduct_name();
                                }else if( temp == products[i].getbest_selling_product()){
                                    best_sell_product_name2 = products[i].getproduct_name();
                                }
                            }
                            cout << "The 1st best selling product is __" << best_sell_product_name1 << "__" << endl;
                            if (best_sell_product_name2.size() > 2){
                                cout << "The 2nd best selling product is __" << best_sell_product_name2 << "__" << endl;
                            }
                            break;
                        }
                        case 2:{
                            int temp = 0,customer_code;
                            string first_name, last_name;
                            for (auto& c : customers){
                                if (temp < c.getmost_purchased_customers()){
                                    temp = c.getmost_purchased_customers();
                                    first_name = c.getfirst_name();
                                    last_name = c.getlast_name();
                                    customer_code = c.getcustomer_code();
                                }
                            }
                            cout << "the customer with " << temp << " purchases is : " << first_name << " " << last_name << endl;
                            cout << " with customer code: " << customer_code << endl;
                            break;
                        }
                        case 3:{
                            int a = 0;
                            int temp[100];
                            for (size_t i = 0; i < orders.size() - 1; i++) {
                                a += 1;
                                if (orders[i].getsum_of_cost() > orders[i + 1].getsum_of_cost()) {
                                    temp[a] = i;
                                } else if (orders[i].getsum_of_cost() == orders[i + 1].getsum_of_cost()) {
                                    a += 1;
                                    temp[a] = i + 1;
                                }
                            }
                            for (int i = 0; i < 100; i++){
                                orders[temp[i]].print_invoice();
                            }
                            break;
                        }

                        case 4:{
                            int check = true;
                            for(auto& p : products){
                                if (p.getproduct_stock() < 4 ){
                                    cout << "__Products with under 4 stocks__" << endl;
                                    cout << p.getproduct_name() << "\t" << p.getproduct_stock() << "\t" << p.getproduct_code() << endl;
                                    check = false;
                                }
                            }
                            if(check){
                                cout << "Dont have products with low stock." << endl;
                            }
                            break;
                        }
                        case 5:{
                            system("cls");
                            nothing = false;
                            break;
                        }
                        default:
                            cout << "Invalid Entery!!!";
                            break;
                    }
                }
                break;
            }

            case 5:{
                system("cls");
                cout << "Good bye!";
                return 1;
                break;
            }
            
            default:
                cout << "Invalid Entery!!";
                break;
        }
    }
    cout << "Good bye................";
    return 0;
}