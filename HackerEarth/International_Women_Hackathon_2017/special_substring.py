def gcd(a,b):
	if b==0:
		return a;
	return gcd(b,a%b);

n,m=map(int,raw_input().split())
str=raw_input()
count=0;
for i in range(0,n):
	for j in range(i+1,n+1):
		#print str[i:j]
		if gcd(int(str[i:j]),m)==1:
			count+=1
print count
