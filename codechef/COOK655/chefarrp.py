t=int(raw_input())
for i in range(0,t):
	n=int(raw_input())
	arr=map(int,(raw_input().split()))
	counter=n
	for j in range(0,n):
		for k in range(j+1,n):
			s=0
			p=1
			for x in range(j,k+1):
				s=s+arr[x]
				p=p*arr[x]
			if s==p:
				counter=counter+1
	print counter
