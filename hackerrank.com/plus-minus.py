t=input()
a=map(int,raw_input().split())
p=0
n=0
z=0
for i in range(0,t):
	if a[i]>0:
		p=p+1
	elif a[i]<0:
		n=n+1
	else :
		z=z+1
print "%.3f\n%.3f\n%.3f"%(p/float(t),n/float(t),z/float(t))
	
