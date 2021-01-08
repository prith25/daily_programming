"""
In two sorted arrays A and B, there is only 1 extra element in array A. Find the index of that one extra element
"""
a = []
b = []
print("Enter the elements of A (Press q to quit) : ")
while True:
    temp = input()
    try:
        a.append(int(temp))
    except ValueError:
        break
print("Enter the elements of B (Press q to quit) : ")
while True:
    temp = input()
    try:
        b.append(int(temp))
    except ValueError:
        break
for i in a:
    if i not in b:
        print(f"Index : {a.index(i)}")
        break
