import sys

n = int(input())
count = 0
while (n != 0):
    count += 1
    print('SET', count)

    listL = []
    listR = []
    for i in range(n):
        s = input().strip()
        if i % 2 == 0:
            listL.append(s)
        else:
            listR.append(s)

    for str in listL:
        print(str)
    for str in reversed(listR):
        print(str)
    n = int(input())
