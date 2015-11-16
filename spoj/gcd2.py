def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)

t=input()

for x in range(0,t):
	a,b=map(int,raw_input().split())
	print gcd(a,b)
