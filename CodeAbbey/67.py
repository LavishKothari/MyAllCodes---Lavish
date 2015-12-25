def findAnswer(n):
	if n==0:
		return 0
	if n==1:
		return 1
	a=0
	b=1
	counter=1
	while 1==1:
		c=a+b
		counter=counter+1
		if c==n:
			return counter 
		a=b
		b=c

t=input()
for i in range(0,t):
	a=input()
	print findAnswer(a)
