t=int(raw_input())
for i in range(0,t):
	n=int(raw_input())
	flag=0
	for y in range(0,n+1):
		x=n-y
		if x%7==0 and y%4==0:
			flag=1
			print x
			break
	if flag==0:
		print "-1"
