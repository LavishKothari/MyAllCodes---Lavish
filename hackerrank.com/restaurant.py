def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

t=input()
for i in range(0,t):
	a=raw_input().split()
	x=int(a[0])
	y=int(a[1])
	
	print x*y/(gcd(x,y)**2)
