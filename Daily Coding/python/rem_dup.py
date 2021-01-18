# Remove the duplicate element in an array
lst = []
length = int(input("Enter the length of the array: "))
print("Enter the array: ")
for i in range(length):
    temp = int(input())
    if temp not in lst:
        lst.append(temp)
for i in lst:
    print(i,end=" ")
