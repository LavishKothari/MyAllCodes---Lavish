t=input()
fib=[]
fib.append(1)
fib.append(1)
for i in range(2,1010):
	fib.append(fib[i-2]+fib[i-1])
for i in range(0,t):
	a=input()
	print fib[a]
