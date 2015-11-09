def findn(n):
	m=n%9;
	if m==0:
		return 9;
	return m;

t=input()
for x in range(0,t):
	a,d,l,r=map(int,raw_input().split())
	answer=0;
	coll=[]
	divsum=0;
	for i in range(l,r+1):
		f=findn(a+(i-1)*d);
		if f in coll:
			break;
		else:
			divsum+=f;
			coll.append(f);
	answer=answer+int((r-l+1)/len(coll))*divsum;
	for i in range(0,(r-l+1)%len(coll)):
		answer=answer+coll[i];
	print answer
