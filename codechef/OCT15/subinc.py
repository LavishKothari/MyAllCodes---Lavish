def fun(n):
	return (n*(n+1))/2

t=input()
for z in range(0,t):
	n=input()
	a=map(int,(raw_input().split()))
	b=[]
	for i in range(0,n-1):
		if a[i]>a[i+1]:
			b.append(i+1)
	start=0
	answer=0
	for i in range(0,len(b)):
		answer=answer+fun(b[i]-start)
		start=b[i]
	answer=answer+fun(n-start)
	print answer
