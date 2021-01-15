"""
Given a number, the problem has to print two prime numbers whose sum will be equal to given number.
"""
def is_prime(num):
    for i in range(3,(num//2)+1):
        if num%i == 0:
            return False
    return True

num = int(input("Enter the number: "))
for i in range(3,num+1):
    if is_prime(i) and is_prime(num-i):
        print(i,num-i)
        break
