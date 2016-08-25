def factorial(n):
	fact=1
	for i in range(1,n+1):
		fact=fact*i;
	return fact

n=input()
print (factorial(2*n)/(factorial(n)**2))/(n+1)

