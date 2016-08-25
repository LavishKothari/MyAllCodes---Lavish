#include<stdio.h>
#include<stdlib.h>
#define N 100
int main()
{
	int t,i,j,a,b,c,d,min=2147483647;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			printf("%d %d\n",abs(i*c+a-(j*d+b)),abs(a-b));
			if(min>abs(i*c+a-(j*d+b)))
				min=abs(i*c+a-(j*d+b));
		}
	printf("min = %d\n",min);
	return 0;
}
