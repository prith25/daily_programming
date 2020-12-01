#Finding the GCD of a number using Euclidean algorithm in recursion
def gcd(num1,num2):
    assert num1>0 and num2>0 and int(num1)==num1 and int(num2)==num2,"Enter only positive integer number"
    if num1 % num2 == 0:
        return num2
    else:
        return gcd(num2,num1%num2)

print(gcd(8,12))
