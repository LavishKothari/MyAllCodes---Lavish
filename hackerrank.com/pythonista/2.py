x=input()
y=input()
z=input()
n=input()

mainList=[]
for i in range(x+1):
	for j in range(y+1):
		for k in range(z+1):
			if i+j+k!=n:
				mainList.append([i,j,k])
print mainList