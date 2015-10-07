n=input()
for z in range(0,n):
	s=raw_input()
	k=input()
	answer=""
	for i in range(0,len(s)):
		if ord(s[i])>=ord('a') and ord(s[i])<=ord('z'):
			answer=answer+str(unichr((ord(s[i])-ord('a')-k)%26+ord('a')))
		elif ord(s[i])>=ord('A') and ord(s[i])<=ord('Z'):
			answer=answer+str(unichr((ord(s[i])-ord('A')-k)%26+ord('A')))
		else:
			answer=answer+s[i]
	print answer
