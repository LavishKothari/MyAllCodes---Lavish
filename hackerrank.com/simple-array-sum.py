n=input()
a=raw_input().split()
a=map(int,a)
sum=0
for i in range(0,n):
	sum=sum+a[i]
print sum
