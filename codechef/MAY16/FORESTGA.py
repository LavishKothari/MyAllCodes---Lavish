MAX_T=1000000000000000000L
MAX=100001
n=0
w=0
l=0
h=[]
r=[]

def findNew(t):
	maxredeemption=0
	for i in range(0,n):
		newh=h[i]+r[i]*t
		if newh>=l:
			maxredeemption=maxredeemption+newh
		if maxredeemption>w:
			return maxredeemption
	return maxredeemption;

def findAnswer():
	startt=0
	endt=MAX_T
	if findNew(0)>=w:
		return 0;
	while 1==1:
		t=(startt+endt)/2
		w1=findNew(t)
		w2=findNew(t-1)
		w3=findNew(t+1)
		
		if w2<w and w1>=w:
			return t 
		if w3>=w and w1<w:
			return t+1;
		
		if w1>w: 
			endt=t-1 
		else :
			startt=t+1 
		
		if startt>endt:
			break;
	return t

n,w,l=map(int,raw_input().split())
for i in range(0,n):
	a,b=map(int,raw_input().split())
	h.append(a)
	r.append(b)
print findAnswer()
