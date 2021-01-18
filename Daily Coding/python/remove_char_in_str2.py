# Remove the characters of the string2 in string 1
s1 = input("Enter the string 1 : ")
s2 = input("Enter the string 2 : ")
for s in s2:
    if s in s1:
        s1 = s1.replace(s,'')
print(s1)
