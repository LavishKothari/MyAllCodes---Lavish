n=input()
a=[]
for i in range(0,n):
	a.append([])
for i in range(0,n):
	a[i]=map(int,raw_input().split())
sum1=0
sum2=0
for i in range(0,n):
	sum1=sum1+a[i][i]
	sum2=sum2+a[i][n-i-1]
print abs(sum1-sum2)
