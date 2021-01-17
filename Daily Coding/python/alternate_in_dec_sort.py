# Sorting the even index digits in increasing order and odd index digits in descending order

a = []
even = []
odd = []
length = int(input("Enter the length of the array: "))
print("Enter the array: ")
for i in range(length):
    temp = int(input())
    a.append(temp)
for i in range(length):
    if i%2 == 0:
        even.append(a[i])
    else:
        odd.append(a[i])
even.sort()
odd.sort()
odd.reverse()
for i in even:
    print(i,end=" ")
for i in odd:
    print(i,end=" ")
