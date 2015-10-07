b=map(int,raw_input().split())
a=map(int,raw_input().split())
if b[2]>a[2]:
	print "10000"
elif b[2]<a[2]:
	print "0"
elif b[1]>a[1]:
	print 500*(b[1]-a[1])
elif b[1]<a[1]:
	print "0"
elif b[0]>=a[0]:
	print 15*(b[0]-a[0])
else :
	print "0"
