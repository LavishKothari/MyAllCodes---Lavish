import math

def isPerfectSquare(n):
	x=int(math.sqrt(n))
	if x*x==n:
		return 1
	return 0

def getFactor(n):
	k=int(math.ceil(math.sqrt(n)))
	y=k*k-n
	d=1
	while isPerfectSquare(y)==0 : 
		y=y+2*k+d
		d=d+2
		print d
	
	x=int(math.sqrt(n+y))
	y=int(math.sqrt(y))
	return x+y
	
n=input()
c=input()
p=getFactor(n)
q=n/p
print p
print q
print p*q
