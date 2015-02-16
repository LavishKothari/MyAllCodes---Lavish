a=raw_input()
c,d=a.split()
n=int(c)
m=int(d)

mylist=[]
mylist.append(1)

for i in range(1,m):
	mylist.append(0)
	mylist[i]=(mylist[i-1]*i)%m

answer=0
pi=raw_input()
pilist=pi.split()
for i in range(n):
	p=int(pilist[i])
	pc=p%m
	x=((pc*(pc+1)*pc)/2)%m
	if p+1<m:
		y=mylist[p+1]-1
	else:
		y=m-1
	answer=(answer+x+y)%m
print answer
	

