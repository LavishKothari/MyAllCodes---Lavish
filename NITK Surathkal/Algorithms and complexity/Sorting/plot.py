# specify the number of algorithms
import pylab 
n=6
ftest=open('result.txt','r')
line=ftest.read().split();
x=[]
y=[]
for i in range(0,n):
	x.append([])
	y.append([])	
for i in range(0,n):
	x[i]=[]
	y[i]=[]
for i in range(0,len(line)/(2*n)):
	for j in range(0,n*2,2):
		x[j/2].append(line[i*2*n+j])
		y[j/2].append(line[i*2*n+j+1])
	
pylab.plot(x[0],y[0],'k')
pylab.plot(x[1],y[1],'g')
pylab.plot(x[2],y[2],'b')
pylab.plot(x[3],y[3],'c')
pylab.plot(x[4],y[4],'r')
pylab.plot(x[5],y[5],'m')

pylab.xlabel("Input size")
pylab.ylabel("time of execution")
pylab.legend(['Bubble Sort', 'Insertion Sort', 'Selection Sort', 'Quick Sort', 'Merge Sort', 'Binary Search '], loc='upper left')
pylab.show()
ftest.close()
