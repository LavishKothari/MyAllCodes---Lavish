def power(a,b):
	if b==0:
		return 1
	if b==1:
		return a
	t=power(a,b/2)
	if(b%2==0):
		return t*t
	return t*t*a
	
def convert(a,inbase,outbase):
	pro=1
	answer=0
	if inbase!=10:
		for i in range(len(a)-1,-1,-1):
			answer=answer+int(a[i])*pro
			pro=pro*inbase
		if outbase==10:
			return str(answer)
	else:
		answer=int(a)
	
	otheranswer=""
	while answer!=0:
		otheranswer=otheranswer+str(answer%outbase)
		answer=answer/outbase
	if otheranswer=="":
		return "0"
	return otheranswer[::-1]
	
t=input()
for i in range(0,t):
	a=int(convert(raw_input(),7,10))
	b=int(convert(raw_input(),7,10))
	l=input()
	c=convert(str(a/b),10,7)
	#c=(a/b)%power(7,l)
	#c=convert(str(c),10,7)
	if len(c)>l:
		print c[-l:]
	else:
		print c
