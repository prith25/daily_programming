# Alternate sorting (first, last, second, second last...)
a = []
len = int(input("Enter the number of elements: "))
print("Enter the array: ")
for i in range(len):
    temp = int(input())
    a.append(temp)
i = 0
len -= 1
while i < len:
    print(a[len],end=" ")
    print(a[i],end=" ")
    i += 1
    len -= 1
    if i == len:
        print(a[i])
        break
