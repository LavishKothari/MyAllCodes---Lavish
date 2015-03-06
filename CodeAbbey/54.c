#include<stdio.h>
#include<math.h>
int main()
{
	int n,t,k;
	double m,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(k=1;;k++)
		{
			printf("k=%d\n",k);
			m=(sqrt(k*k+2*n*k)-k)/(2*k);
			//if((int)((m*m-(int)(m*m))*100000)==0)
			if((int)((m*m)-(int)(m*m))*100000==0)
			{
				printf("%g ",(m*m+1)*(m*m+1));
				break;
			}
		}
	}
	return 0;
}
