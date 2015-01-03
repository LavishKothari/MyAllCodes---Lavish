t=input()
for i in range(t):
    n,k=raw_input().split()
    n=int(n)
    k=int(k)
    A=raw_input().split()
    B=raw_input().split()
    for j in range(n):
        A[j]=int(A[j])
        B[j]=int(B[j])
    max=0
    for j in range(n):
        if (k/A[j])*B[j] > max :
            max=(k/A[j])*B[j]
    print max
