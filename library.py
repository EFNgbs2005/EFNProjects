### libs
import pickle
import os



### PATH
PATH = "c:/Users/MSI/Desktop/"



### validation
def check_validation():
    if not os.path.exists(PATH + "user.dat"):
        with open(PATH + "user.dat", "wb") as f :
            users_dict = {}
            pickle.dump(users_dict, f)

    if not os.path.exists(PATH + "Book.dat"):
        with open(PATH + "Book.dat", "wb") as f:
            book_dict = {}
            pickle.dump(book_dict, f)

    if not os.path.exists(PATH + "borrows.dat"):
        with open(PATH + "borrows.dat", "wb") as f:
            borrows_dict = {}
            pickle.dump(borrows_dict, f)


### func 
def add_user(name, family, father_name, code, birthday):
    check_validation()

    with open(PATH + "user.dat", "rb") as f:
        users_dict = pickle.load(f)

    user_id = len(users_dict)
    users_dict[user_id] = [name, family, father_name, code, birthday]

    with open(PATH + "user.dat", "wb") as f:
        pickle.dump(users_dict, f)
    print("welcome to our library... your id is: ", user_id + 1)

def add_book(title, author, subject, year):
    check_validation()
    with open(PATH + "Book.dat", "rb") as f:
        book_dict = pickle.load(f)

    book_dict[title] = [author, subject, year]

    with open(PATH + "Book.dat", "wb") as f:
        pickle.dump(book_dict, f)
        
    print(book_dict)

def search_book(title):
    check_validation()

    with open(PATH + "Book.dat", "rb") as f:
        book_dict = pickle.load(f)

    print(book_dict[title]) 

def borrow(user_id, title):
    check_validation()
    with open(PATH + "borrows.dat", "rb") as f:
        borrows_dict = pickle.load(f)

    borrows_dict[user_id] = title

    with open(PATH + "borrows.dat", "wb") as f:
        pickle.dump(borrows_dict, f)

def show_all_info():
    check_validation()

    with open(PATH + "user.dat", "rb") as f :
        users_dict = pickle.load(f)
    
    with open(PATH + "Book.dat", "rb") as f:
        book_dict = pickle.load(f)

    with open(PATH + "borrows.dat", 'rb') as f :
        borrows_dict = pickle.load(f)

    print(users_dict)
    print("--------------------------------")
    print(book_dict)
    print("--------------------------------")
    print(borrows_dict)
### start
ch = 1
while ch != 0 :
    print("1-Add User\n2-Add New Book\n3-Search\n4-Barrow\n5-Show All\n0-Exit")
    ch = int(input("Enter YOur Choice: "))
    os.system('cls')


    if ch == 1:
        check_validation()
        name = input("Enter Name: ")
        family = input("Enter Family: ")
        father_name = input("Enter Father Name: ")
        code = input("Enter Nationality Code: ")
        birthday = input("Enter Birthday: ")

        add_user(name, family, father_name, code, birthday)

    elif ch == 2:
        title = input("Enter Title: ")
        author = input("Enter Author: ")
        subject = input ("Enter Subject: ")
        year = input("Enter Year: ")

        add_book(title, author, subject, year)


    elif ch == 3:
        check_validation()
        title = input("Enter Title: ")
        search_book(title)
        
    elif ch == 4:
        check_validation()
        user_id = input("Enter User Id: ")
        title = input ("Enter Title: ")

        borrow(user_id, title)

    elif ch == 5:
        show_all_info()
    elif ch == 0:
        break


