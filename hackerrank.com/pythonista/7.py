import re
n=input()
for i in range(n):
	s=raw_input()
	match=re.search(r'\d\d\d\d\d\d\d\d\d\d',s)
	if match:
		if len(s)==10:
			if s[0]==str(7):
				print 'YES'
			elif s[0]==str(8):
				print 'YES'
			elif s[0]==str(9):
				print 'YES'
			else: 
				print 'NO'
		else:
			print 'NO'
	else:
		print 'NO'