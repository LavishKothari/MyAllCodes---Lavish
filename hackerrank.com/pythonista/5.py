n=input()
answer=0
for i in range(n):
	s=raw_input();
	for item in s:
		if item=='=':
			answer=answer+1
print answer