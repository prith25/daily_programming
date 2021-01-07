"""

1
1 1
2 1
1 2 1 1
1 1 1 2 2 1
3 1 2 2 1 1

"""
output = []
next_op = []
output.append(1)
count = 0
lines = int(input("Enter the number of lines: "))
for i in range(lines):
    for z in output:
        print(z,end=" ")
    temp = output[0]
    j = 0
    while j < len(output)+1:
        if j < len(output) and temp == output[j]:
            count += 1
            j += 1 
        
        else:
            next_op.append(count)
            next_op.append(temp)
            count = 0
            if j < len(output):
                temp = output[j]
            else:
                break
    output.clear()
    for x in next_op:
        output.append(x)
    next_op.clear()
    print()
