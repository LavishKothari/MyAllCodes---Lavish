a=input()
lis=raw_input().split()
seta=set(lis)
b=input()
lis=raw_input().split()
setb=set(lis)
answerset=seta.difference(setb)
answerset.update(setb.difference(seta))
answerlist=[]
for item in answerset:
	answerlist.append(int(item))
answerlist.sort()
for item in answerlist:
	print item