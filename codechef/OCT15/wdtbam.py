t=input()
for z in range(0,t):
	n=input()
	a=raw_input()
	b=raw_input()
	w=map(int,raw_input().split())
	count=0
	for i in range(0,n):
		if a[i]==b[i]:
			count=count+1
	if count==n:
		print w[n]
	else: 
		print max(w[:count+1])
