n=input()
for i in range(0,n):
	a=list(set(list(raw_input())))
	b=raw_input()
	answer=0
	for j in range(0,len(a)):
		for k in range(0,len(b)):
			 if a[j]==b[k]:
			 	answer=answer+1
	print answer
