a=raw_input()
b=raw_input()
answer=0
for i in range(0,len(a)-len(b)+1):
	flag=0
	for j in range(0,len(b)):
		if a[i+j]==b[j]:
			flag=flag+1
		else:
			break
	if flag==len(b):
		answer=answer+1
		
print answer