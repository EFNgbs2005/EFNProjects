####lib:
import os
PATH = "D:/Programming/Python/project in python/phone book project/phone_book.txt"
#### validation:
def validation():
    if not os.path.exists(PATH):
        print("file doesnt exisit but we creat it.")
        f = open(PATH,"w+")
        f.write("")
#### start function :
def add(name, number):
     validation()
     f = open(PATH, "a+")
     new_phone = name + ":" + number + "\n"
     f.write(new_phone)
     f.close()

def search(name):
     validation()

     f = open(PATH, "r")
     for line in f.readlines():
          if name == line.split(":")[0]:
               print(name + ":" + line.split(":")[1]) 

     f.close()

def delete(name):
     validation()

     f = open(PATH, "r")
     new_database = ""
     for line in f.readlines():
          if not name == line.split(":")[0]:
               new_database += line
     f.close()

     f = open(PATH, "w")
     f.write(new_database)

def show_all():
     validation()

     f = open(PATH, "r")
     database = ""
     database = f.read()
     f.close()
     print(database)
     # for line in f.readlines():
     #      print(line)

     # f.close()

##### Start:
ch = 1
while ch != 0:
    print("1- Add User\n2- Search Phone\n3- Delete Phone\n4- Show All Number\n0- Exit")
    ch = int(input("Enter your choice: "))
    os.system('cls')
    if ch == 1:
        validation()
        name = input("Enter Name:")
        number = input("Enter Your number:")
        add(name, number)

    elif ch == 2:
         validation()
         name = input("Enter Name:")
         search(name)

    elif ch == 3:
         validation()
         name = input("Enter Name:")
         delete(name)

    elif ch == 4:
          validation()
          show_all()

    elif ch == 0:
         validation()
         break