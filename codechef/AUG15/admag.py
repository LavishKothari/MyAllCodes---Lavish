import math
t=input()
for i in range(0,t):
	n=input()
	if n==1:
		print "1"
	else:
		print int(math.log(n*math.sqrt(5)+0.5)/math.log((1+math.sqrt(5))/2))-1
