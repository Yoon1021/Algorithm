P,K = input().split()
P = int(P)
K = int(K)

flag = 0

for i in range(2,K):
    if((P % i) ==0):
        print("BAD", i)
        flag = 1
        break;

        
if(flag == 0):
    print("GOOD")
