def findAnswer(n):
	if n==0:
		return 0
	if n==1:
		return 0
	a=0
	b=1
	counter=1
	while 1==1:
		c=a+b
		counter=counter+1
		if c%n==0:
			return counter 
		a=b
		b=c

t=input()
a=map(int,raw_input().split())
for j in range(0,len(a)):
	print findAnswer(a[j])
