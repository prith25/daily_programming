#Invoice management using SQL
import random
import prettytable
import sqlite3
import os

def check(product):
    if product == "maggi":
        return 12
    elif product == "rice":
        return 23
    elif product == "kitkat":
        return 10
    elif product == "watch":
        return 66
    elif product == "milk":
        return 18
    elif product == "water":
        return 20
    elif product == "mixer":
        return 28
    elif product == "ice cream":
        return 55
    elif product == "kulfi":
        return 34
    elif product == "mouse":
        return 219
    elif product == "headset":
        return 599
    elif product == "axe":
        return 78
    elif product == "apple":
        return 12
    elif product == "orange":
        return 27
    elif product == "pen":
        return 14
    elif product == "pencil":
        return 8
    elif product == "ink":
        return 17
    elif product == "note":
        return 28
    else:
        return 0

def print_bill(bill_no):
    query = "SELECT AMOUNT FROM " + bill_no
    c.execute(query)
    result = c.fetchall()
    l = map(sum,result)
    subtotal = sum(l)
    query = "SELECT * FROM " + bill_no
    print(prettytable.from_db_cursor(c.execute(query)))
    print(f"\t\t\t\t  Subtotal   {subtotal}")
    GST = (subtotal * 18 )/100
    print(f"\t\t\t\t   GST 18%   {GST}")
    total = GST + subtotal
    total = round(total,2)
    print(f"\n\t\t\t\t     Total   {total}")
    q = input("\n\nPress Enter to exit")
    welcome_screen()

def create_bill(bill_no):
    os.system("cls")
    print("\n\n\t\t\tTreetop billing")
    bill = "bill_" + str(bill_no)
    query = "CREATE TABLE " + bill + " (SL_NO INTEGER, PRODUCT_NAME TEXT, QUANTITY INTEGER, PRICE INTEGER, AMOUNT INTEGER)"
    c.execute(query)
    sl_no = 1
    while True:
        price = 0
        product_name = input("Product name : ")
        price = check(product_name)
        if price:
            quantity = int(input("Quantity : "))
            amount = price * quantity
            query = "INSERT INTO " + bill + " (SL_NO,PRODUCT_NAME,QUANTITY,PRICE,AMOUNT) VALUES (?,?,?,?,?)"
            c.execute(query,(sl_no,product_name,quantity,price,amount))
            conn.commit()
            sl_no += 1
            quitting = input("\nDo you want to add products (Y/N): ")
            if quitting == 'N' or quitting == 'n':
                break
            os.system("cls")
        else:
            os.system("cls")
            print("Invalid Product name\n")
    print_bill(bill)
    welcome_screen()

def view_bill():
    os.system("cls")
    print("\n\t\t\tWelcome to Treetop")
    while True:
        bill_no = int(input("\nEnter the bill no : "))
        bill = "bill_" + str(bill_no)
        try:
            query = "SELECT * FROM " + bill
            c.execute(query)
        except sqlite3.OperationalError:
            print("There is no such bill number ")
        else:
            print_bill(bill)
            break


def new_bill():
    os.system("cls")
    loop = 0
    while True:
        os.system("cls")
        if loop:
            print("Invalid input.. Please enter the correct option")
        print("\n\n\t\t\tTreetop billing")
        option = input("\n\nIs this for a existing customer (YES/NO) : ")
        if option == 'YES' or option == 'yes':
            temp = 0
            while True:
                os.system("cls")
                if temp:
                    print("Invaid input")
                print("\n\n\t\t\tTreetop billing")
                customer_name = input("\n\nEnter the customer name : ")
                query = "SELECT * FROM ACCOUNTS WHERE CUSTOMER_NAME = (?) "
                c.execute(query,(customer_name,))
                result = c.fetchone()
                try:
                    bill_no = random.randint(1823,98242)
                    ct_list = list(result)
                    customer_id = ct_list[0]
                    c.execute("SELECT COUNT(*) FROM TRACK_BILL")
                    ct = c.fetchone()
                    ct_list = list(ct)
                    count = ct_list[0] + 1
                    query = "INSERT INTO TRACK_BILL (SL_NO, CUSTOMER_ID, BILL_NO) VALUES (?,?,?)"
                    c.execute(query,(count,customer_id,bill_no))
                    conn.commit()
                    create_bill(bill_no)
                    break
                except sqlite3.OperationalError:
                    temp = 1
            break
                
        elif option == 'NO' or option == 'no':
            os.system("cls")
            print("\n\n\t\t\tTreetop billing")
            customer_name = input("\n\nEnter the customer name : ")
            bill_no = random.randint(1823,98242)
            c.execute("SELECT COUNT(*) FROM ACCOUNTS")
            ct = c.fetchone()
            ct_list = list(ct)
            count = ct_list[0] + 1
            query = "INSERT INTO ACCOUNTS (CUSTOMER_ID,CUSTOMER_NAME) VALUES (?,?) "
            c.execute(query,(count,customer_name,))
            conn.commit()
            c.execute("SELECT COUNT(*) FROM TRACK_BILL")
            ct = c.fetchone()
            ct_list = list(ct)
            count2 = ct_list[0] + 1
            query = "INSERT INTO TRACK_BILL (SL_NO,CUSTOMER_ID,BILL_NO) VALUES (?,?,?)"
            c.execute(query,(count2,count,bill_no))
            conn.commit()
            create_bill(bill_no)
            break
            
        else:
            loop = 1
            
def welcome_screen():
    temp = 0
    while True:
        os.system("cls")
        print("\n\t\t\tWelcome to Treetop")
        if temp:
            print("Invaid input... Please select a correct option")
        print("\n\n1. New bill\n2. View existing bill\n3. Quit")
        choice = int(input("\n\nEnter your option : "))
        if choice == 1:
            new_bill()
            break
        elif choice == 2:
            view_bill()
            break
        elif choice == 3:
            quit()
            break
        else:
            temp = 1
            welcome_screen()

conn = sqlite3.connect("shop.db")
c = conn.cursor()
c.execute("CREATE TABLE IF NOT EXISTS ACCOUNTS (CUSTOMER_ID INTEGER, CUSTOMER_NAME TEXT)")
c.execute("CREATE TABLE IF NOT EXISTS TRACK_BILL (SL_NO INTEGER, CUSTOMER_ID, BILL_NO)")
welcome_screen()
