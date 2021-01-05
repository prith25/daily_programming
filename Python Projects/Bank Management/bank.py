#Bank Management project using SQL
import sqlite3
import os
import random

def Signup_page():
    os.system('cls')
    print("\n\t\t\t\t\tNational Bank")
    print("\n\t\t\t\t\t SIGN UP\n")
    first_name = input("Enter your first name : ")
    last_name = input("Enter your last name : ")
    mobile_number = input("Enter your mobile number : ")
    account_number = random.randint(200000000,298341469)
    password = input("Enter your password : ")
    balance = 0
    query = f"INSERT INTO ACCOUNTS (account_number,password,first_name,last_name,mobile_number,balance) VALUES (?,?,?,?,?,?)"
    c.execute(query,(account_number,password,first_name,last_name,mobile_number,balance))
    conn.commit()
    print("Account has been successfully created")
    print(f"Your account number is {account_number}")
    q = input("Press any key to go to welcome screen")
    Welcome_screen()

def Login_page():
    temp = 1
    log = 0
    while temp:
        temp = 0
        os.system('cls')
        print("\n\t\t\t\t\tNational Bank")
        print("\n\t\t\t\t\t LOGIN\n")
        if log:
            print("Incorrect Credentials\n")
            pass_reset = input("Do you want to reset your password (Y/N) : ")
            if pass_reset == 'Y' or pass_reset == 'y':
                Passwordreset_screen()
                Login_page()
                break
        firstname = input("Enter your first name : ")
        password = input("Enter your password : ")
        if firstname == "admin" and password == "admin":
            Admin_page()
            Welcome_screen()
        query = f"SELECT * FROM ACCOUNTS WHERE first_name=? AND password=?"
        c.execute(query,(firstname,password))
        result = c.fetchone()
        if result:
            acc = result[0]
            User_page(acc)
        else:
            log += 1
            temp = 1

def Admin_page():
    os.system('cls')
    print("\n\t\t\t\t\tNational Bank")
    print("\n\t\t\t\tWelcome Admin")
    c.execute("SELECT * FROM ACCOUNTS")
    result = c.fetchall()
    print("\nAccount Number   Username        Balance")
    for data in result:
        print(f"{data[0]}\t   {data[2]}\t      {data[4]}")
    q = input("Press Enter key to continue")
    Welcome_screen()

def Withdraw(acc_number):
    os.system('cls')
    print("\n\t\t\t\t\tNational Bank")
    print("\n\t\t\t Withdraw Money\n")
    c.execute("SELECT * FROM ACCOUNTS WHERE account_number=?",(acc_number,))
    result = c.fetchone()
    balance = result[5]
    if balance == 0:
        print("Insufficient Balance")
        q = input("Press Enter to exit")
        Welcome_screen()
    else:
        print(f"Your Balance : Rs. {balance}")
        amount = int(input("Enter the amount : Rs. "))
        if amount > balance:
            print("Insufficient Balance")
            q = input("Press Enter to exit")
            Welcome_screen()
        else:
            balance = balance - amount
            query = f"UPDATE ACCOUNTS SET balance=? WHERE account_number=?"
            c.execute(query,(balance,acc_number))
            conn.commit()
            print(f"Your current balance : {balance}")
            q = input("Press Enter key to quit")
            Welcome_screen()

def Make_transaction(acc_number):
    os.system('cls')
    print("\n\t\t\t\t\tNational Bank")
    print("\n\t\t\t Make Transaction")
    c.execute("SELECT * FROM ACCOUNTS WHERE account_number=?",(acc_number,))
    result = c.fetchone()
    balance = result[5]
    if balance == 0:
        print("Insufficient Balance")
        q = input("Press Enter to exit")
        Welcome_screen()
    else:
        temp = 1
        while temp:
            temp = 0
            amount = []
            transfer_account = input("\nEnter the transfer account number : ")
            c.execute("SELECT * FROM ACCOUNTS WHERE account_number=?",(transfer_account,))
            account = c.fetchone()
            if account:
                transfer_balance = int(input("Enter the amount : "))
                if transfer_balance > balance:
                    print("\nInsufficient balance")
                    q = input("Press Enter to quit")
                    Welcome_screen()
                balance = balance - transfer_balance
                query = f"UPDATE ACCOUNTS SET balance=? WHERE account_number=?"
                c.execute(query,(balance,acc_number))
                conn.commit()
                print(f"TRANSACTION SUCCESS\nYour current balance : {balance}")
                query = f"SELECT * FROM ACCOUNTS WHERE account_number=?"
                c.execute(query,(transfer_account,))
                transfer = c.fetchone()
                total_transfer = transfer_balance + transfer[5]
                query = f"UPDATE ACCOUNTS SET balance=? WHERE account_number=?"
                c.execute(query,(total_transfer,transfer_account))
                conn.commit()
                q = input("Press Enter to quit")
                Welcome_screen()
            else:
                quit = input("The account number you entered is incorrect\n Please try again\n\n Enter q to quit")
                if quit == 'q' or quit == 'Q':
                    Welcome_screen()
                temp = 1

def Passwordreset_screen():
    temp = 1
    while temp:
        temp = 0
        os.system('cls')
        print("\n\t\t\t\t\tNational Bank")
        print("\n\t\t\t\tPassword Reset\n")
        firstname = input("Enter your first name : ")
        mobile = int(input("Enter your mobile number : "))
        query = f"SELECT * FROM ACCOUNTS WHERE first_name=? AND mobile_number=?"
        c.execute(query,(firstname,mobile))
        result = c.fetchone()
        if result:
            otp = int(input("Enter the OTP : "))
            if otp == 1234:
                new_password = input("Enter your new password : ")
                query = f"UPDATE ACCOUNTS SET password=? WHERE mobile_number=?"
                c.execute(query,(new_password,mobile))
                conn.commit()
                Login_page()
            else:
                print("Your OTP is wrong. Please try again")
                temp = 1

def User_page(acc_number):
    c.execute("SELECT * FROM ACCOUNTS WHERE account_number=?",(acc_number,))
    result = c.fetchone()
    os.system('cls')
    temp = 1
    while temp:
        temp = 0
        print("\n\t\t\t\tNational Bank")
        print(f"\n\t\tWelcome {result[2]}\n")    
        print(f"Account number : {result[0]}\nBalance : Rs. {result[5]}\n")
        choice = int(input("1. Make Transactions\n2. Withdraw\n3. Add money\n4. Logout\nEnter your choice : "))
        if choice == 1:
            Make_transaction(result[0])
        elif choice == 2:
            Withdraw(result[0])
        elif choice == 3:
            Addmoney_page(result[0])
        elif choice == 4:
            Welcome_screen()
        else:
            temp = 1

def Addmoney_page(account_no):
    os.system('cls')
    print("\n\t\t\t\t\tNational Bank")
    print("\n\t\t\t Adding money\n")
    c.execute("SELECT * FROM ACCOUNTS WHERE account_number=?",(account_no,))
    result = c.fetchone()
    balance = result[5]
    amount = int(input("Enter the amount : "))
    balance = balance + amount
    c.execute("UPDATE ACCOUNTS SET balance=? WHERE account_number=?",(balance,account_no))
    conn.commit()
    print("Amount has been added successfully")
    c.execute("SELECT * FROM ACCOUNTS WHERE account_number=?",(account_no,))
    result = c.fetchone()
    balance = result[5]
    print(f"Your balance is Rs. {balance}")
    q = input("Press Enter to exit")
    Welcome_screen()

def Delete_account():
    os.system('cls')
    print("\n\t\t\t\t\tNational Bank")
    print("\n\t\t\t Delete Account\n")
    temp = 1
    while temp:
        temp = 0
        account_no = int(input("Enter the account number : "))
        c.execute("SELECT * FROM ACCOUNTS WHERE account_number=?",(account_no,))
        result = c.fetchone()
        if result:
            choice = input("Are You sure you want to delete the account\nYES\t\tNO\n\nEnter your choice : ")
            if choice == "YES" or choice == "yes":
                query = f"DELETE FROM ACCOUNTS WHERE account_number=?"
                c.execute(query,(account_no,))
                conn.commit()
                print("Your Account is deleted")
                q = input("Press Enter to exit")
                Welcome_screen()
            else:
                temp = 1
                choice = input("The account number you enter is wrong.\nTry again\nEnter q to exit")
                if choice == "q" or choice == "Q":
                    Welcome_screen()
        else:
            temp = 1
            print("Invalid account number")
            q = input("Press q to quit   ")
            if q == 'q' or q == 'Q':
                Welcome_screen()

def Welcome_screen():
    temp = 1
    while temp:
        temp = 0
        os.system('cls')
        print("\n\t\t\t\tWelcome to National Bank")
        print("1. Login\n2. Signup\n3. Delete Account\n4. Quit\n\nEnter your choice : ",end="")
        option = int(input())
        if option == 1:
            Login_page()
        elif option == 2:
            Signup_page()
        elif option == 3:
            Delete_account()
        elif option == 4:
            break
        else:
            os.system('cls')
            print("Please enter a valid input")
            temp = 1
    
conn = sqlite3.connect("bank.db")
c = conn.cursor()
c.execute('CREATE TABLE IF NOT EXISTS accounts(account_number INTEGER, password BLOB, first_name TEXT, last_name TEXT, mobile_number INTEGER, balance INTEGER)')
Welcome_screen()
q = input()
conn.close()
