t=input()
for x in range(t):
	n=input()
	if n<6:
		print "FIGHT"
	else :
		ans=(((n-5)*(n-4)*(n-3)*(n-2)*(n-1))/120)%1000000007
		print ans
