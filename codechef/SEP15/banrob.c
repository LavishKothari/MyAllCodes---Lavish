#include<stdio.h>
#define B 1000000000
int main()
{
	float p;
	int t,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%f",m,p);
		if(m==1)
		{
			printf("%f 0.0",(float)B);
		}
		else
		{
			cp=p;
			for(i=0;i<m;i++)
			{
				if(i==0)
				{
					a=max((1-p)*B,p*B);
					b=min((1-p)*B,p*B);
				}
				else
				{
					if(p>=0.5)
					{
						if(i%2==0)
						{
							a=max((1-p)*B,p*B);
							b=min((1-p)*B,p*B);
						}
						else
						{
							a=min((1-p)*B,p*B);
							b=max((1-p)*B,p*B);
						}
					}
					else
					{
						a=b=p*B;
					}
					p=p*cp;
				}
				if(i==0)
				{
					maxa=a;maxb=b;finali=0;
				}
			}
		}
	}
	return 0;
}
