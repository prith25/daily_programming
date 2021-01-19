#Find the union of two arrays and print the number elements in the resultant array
a = []
print("Enter the length of both arrays: ")
len1 = int(input())
len2 = int(input())
print("Enter the first array: ")
for i in range(len1):
    temp = int(input())
    a.append(temp)
print("Enter the second array: ")
for i in range(len2):
    temp = int(input())
    if temp not in a:
        a.append(temp)
print(f"Length of the union is {len(a)}")
