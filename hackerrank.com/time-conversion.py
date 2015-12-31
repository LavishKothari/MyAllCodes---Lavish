a=raw_input()
if a[8]=="A" and a[0]=="1" and a[1]=="2":
	print "00%s"%(a[2:8])
elif a[8]=="A":
	print a[0:8]
elif (int(a[0]+a[1])+12)%24==0:
	print "12%s"%(a[2:8])
else :
	print "%d%s"%(int(a[0]+a[1])+12,a[2:8])
