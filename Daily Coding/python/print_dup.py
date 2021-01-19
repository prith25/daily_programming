#Print the duplicate element in the array. If there is no duplicate element then print -1
a = []
dup = []
flag = 1
length = int(input("Enter the length of the array: "))
for i in range(length):
    temp = int(input())
    if temp not in a:
        a.append(temp)
    else:
        dup.append(temp)
        flag = 0
if flag:
    print(-1)
else:
    for i in dup:
        print(i,end=" ")
