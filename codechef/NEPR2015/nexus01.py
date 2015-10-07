t=input()
for z in range(0,t):
	n=input()
	a=map(int,raw_input().split())
	print max(a)*n-sum(a)
