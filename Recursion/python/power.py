#Finding the power of the number using recursion
def power(base,exp):
    assert exp >= 0 and int(exp) == exp, "Enter positive or integer value for the exponent"
    if exp == 0:
        return 1
    else:
        return base * power(base,exp-1)

print(power(3,3))
