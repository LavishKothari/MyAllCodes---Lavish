a,b,n=map(int,raw_input().split())
if n==1:
	print a
elif n==2:
	print b
else:
	for i in range(0,n-2):
		c=b*b+a
		a=b
		b=c
	print c
