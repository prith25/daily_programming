#Print the word in cross pattern
word = input("Enter the word: ")
length = len(word) 
l = length - 1
for i in range(length):
    for j in range(length):
        if i==j or j==l:
            print(word[j],end=" ")
        else:
            print(" ",end=" ")
    l -= 1
    print()
