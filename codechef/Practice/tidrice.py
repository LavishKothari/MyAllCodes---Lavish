t=input()
for i in range(0,t):
	answer=0
	n=input()
	x=[]
	y=[]
	for j in range(0,n):
		line=raw_input().split()
		x.append(line[0])
		y.append(line[1])
	for j in range(n-1,-1,-1):
		flag=0
		for k in range(j+1,n):
			if x[j]==x[k]:
				flag=1
		if flag==0:
			if y[j]=='+':
				answer=answer+1
			else:
				answer=answer-1
	print answer
