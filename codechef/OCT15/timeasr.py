def findDegree(h,m):
	temp=m*6-h*30-0.5*m
	if temp>=0:
		if temp<=180:
			return temp
		else:
			return temp-180
	else:
		if temp>=-180:
			return -temp
		else:
			return 360+temp

def convert(a):
	string=""
	for i in range(0,len(a)):
		if a[i][0]>9 and a[i][1]>9:
			string = string + "%d:%d\n" %(a[i][0],a[i][1])
		elif a[i][0]<10 and a[i][1]>9:
			string = string + "0%d:%d\n" %(a[i][0],a[i][1])
		elif a[i][0]>9 and a[i][1]<10:
			string = string + "%d:0%d\n" %(a[i][0],a[i][1])
		elif a[i][0]<10 and a[i][1]<10:
			string = string + "0%d:0%d\n" %(a[i][0],a[i][1])
	return string

t=input()
answer=[]
temp={}
for h in range(0,12):
	for m in range(0,60):
		temp=findDegree(h,m)
		if temp in answer:
			answer[temp].append([h,m])
		else:
			answer[temp]=[h,m]
for key in sorted(answer):
    newDict[key]=convert(answer[key])
    
for z in range(0,t):
	d=input()
	print newDict[d]

