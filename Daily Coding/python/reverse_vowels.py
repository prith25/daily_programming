# Reverse only the vowels present in the string
def check(letter):
    vowels = ['a','e','i','o','u']
    letter.lower()
    if letter in vowels:
        return True
    return False

word = input("Enter the word: ")
i = 0
j = len(word) - 1
lst = list(word)
while i<j:
    if not check(lst[i]):
        i += 1
    elif not check(lst[j]):
        j -= 1
    else:
        temp = lst[i]
        lst[i] = lst[j]
        lst[j] = temp
        i += 1
        j -= 1
word = "".join(lst)
print(word)

