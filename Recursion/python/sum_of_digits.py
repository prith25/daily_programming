#Sum of the individual digits
def sumofdigits(n):
    assert n > 0 and int(n) == n, "Enter only integer or Enter only the positive numbers"
    if n < 10:
        return n
    else:
        return n%10 + sumofdigits(n//10)

print(sumofdigits(123456789))
