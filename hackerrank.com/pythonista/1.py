n=input()
data={}
for i in range(n):
	name,a,b,c=raw_input().split()
	data[name]=(float(a)+float(b)+float(c))/3.0
	
newname=raw_input()
print ("%.2f"%data[newname])
	