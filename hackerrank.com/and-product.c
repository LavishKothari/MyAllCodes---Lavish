#include<stdio.h>
#include<math.h>
#include<stdlib.h>
unsigned int findAnswer(unsigned int a,unsigned int b)
{
	unsigned int x,p,q;
	if(a==0 || b==0)
		return 0;
	p=(unsigned int)log2(a);
	q=(unsigned int)log2(b);
	
	x=llabs(p-q);
	if(x!=0) return 0;
	else return (1<<p)+findAnswer(a-(1<<p),b-(1<<q));
}
int main()
{
	int t;
	unsigned int a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%u%u",&a,&b);
		printf("%u\n",findAnswer(a,b));
	}
	return 0;
}
