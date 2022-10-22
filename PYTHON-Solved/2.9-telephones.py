# https://open.kattis.com/problems/telephones

while True:
    calls = []
    line1 = [int(n) for n in input().strip().split()]
    n = line1[0]
    m = line1[1]

    if n == 0 and m == 0:
        break

    for i in range(n):
        line2 = [int(j) for j in input().strip().split()]
        callBounds = (line2[2], line2[2] + line2[3])
        calls.append(callBounds)

    for i in range(m):
        count = 0
        query = [int(k) for k in input().strip().split()]
        query[1] += query[0]
        for pair in calls:
            if pair[0] < query[1] and pair[1] > query[0]:
                count += 1
        print(count)
