def PrintConverted(c):
	s=""
	for i in range(0,len(c),2):
		if c[i]=='0' and c[i+1]=='0':
			break;
		n=(ord(c[i])-ord('0'))*10+(ord(c[i+1])-ord('0'))
		s=s+chr(n)
	print s
		
def inv(a,b):
	cx=1
	px=0
	cy=0
	py=1
	cr=a
	pr=b
	while pr!=1:
		q=cr/pr
		
		nr=cr-q*pr
		nx=cx-q*px
		ny=cy-q*py
		
		cx=px
		cy=py
		cr=pr
		
		px=nx
		py=ny
		pr=nr
	return (py+a)%a


def power(a,b,mod):
	if b==0:
		return 1
	if b==1:
		return a
	temp=power(a,b/2,mod)
	t=(temp*temp)%mod
	if b%2==1:
		return (t*a)%mod	
	return t


p=input()
q=input()
e=65537
d=inv((p-1)*(q-1),e)
print d
c=input()
PrintConverted(str(power(c,d,p*q)))

