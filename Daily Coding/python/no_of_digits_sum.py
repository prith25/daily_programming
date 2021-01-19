#Get two numbers as input. Find the sum of the numbers.
#If the number of digits in the sum is greater than the number of digits in the first number then print only the first number, else print the sum
def find_digits(num):
    digits = 0
    while num > 0:
        num //= 10
        digits += 1
    return digits

print("Enter the numbers: ")
num1 = int(input())
num2 = int(input())
num_digits = find_digits(num1)
total = num1 + num2
sum_digits = find_digits(total)
if sum_digits == num_digits:
    print(total)
else:
    print(num1)
