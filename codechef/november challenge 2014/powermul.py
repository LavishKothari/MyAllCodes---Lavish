import math
def calMul(a,b):
	pro=1
	for i in range(a,b+1):
		pro=pro*(math.pow(i,i))
	return pro

t=input()
for i in range(t):
	n,m,q=raw_input().split()
	n=int(n)
	m=int(m)
	q=int(q)
	
	for j in range(q):
		r=input()
		answer=(calMul(r+1,n)/calMul(1,n-r))%m
		print int(answer)