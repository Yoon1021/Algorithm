def min(a, b):
    if (a>b):
        return b
    else :
        return a

x = int(input())

DP = [ 0 for _ in range(10000000)]
DP[1] = 0
DP[2] = 1
DP[3] = 1

for i in range(4, x+1):
    DP[i] = DP[i-1] + 1
    #print(i, ':', DP[i])

    if (i%2 == 0):
        DP[i] = min(DP[i], DP[int(i/2)]+1)
        #print('mod 2', i, ':', DP[i])

    if (i%3 == 0):
        DP[i] = min(DP[i], DP[int(i/3)]+1)
        #print ('mod 3', i, ':', DP[i])

print(DP[x])
