#Converting a decimal to binary number in recursion
def binary(n):
    assert n>=0 and int(n) == n, "Enter only positive integer"
    if n == 0:
        return 0
    else:
        return n%2 + 10*binary(n//2)

print(binary(17))
