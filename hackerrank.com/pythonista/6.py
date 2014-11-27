n=input()
answer=0
realAnswer=[]
for i in range(n):
	s=raw_input()
	for j in range(len(s)-1):
		if s[j]=='<':
			if s[j+1]!='/':
				answer=answer+1
				realAnswer.append(answer)
			else :
				answer=answer-1
		if s[j]=='/':
			if s[j+1]=='>':
				answer=answer-1
		
			
print max(realAnswer)-1