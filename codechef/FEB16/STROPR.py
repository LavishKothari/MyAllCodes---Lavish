MOD=1000000007
MAX=100001
def powerMOD(a,b):
	if b==0:
		return 1
	elif b==1: 
		return a
	t=powerMOD(a,b/2)
	if b%2==1:
		return (t*t*a)%MOD
	return (t*t)%MOD

def inverseMOD(a):
	return powerMOD(a,MOD-2)

t=input()
for x in range(0,t):
	n,x,m=map(int,raw_input().split())
	arr=map(int,raw_input().split())
	answer=arr[x-1]
	prev=1
	for i in range(2,x+1):
		one=i+m-2
		two=m-1
		inter=(prev*one*inverseMOD(one-two))%MOD
		#print "coeff = "+str(inter)	
		answer=(answer+inter*arr[x-i])%MOD
		prev=inter
	print (answer)%MOD
