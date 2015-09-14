#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double rate;
	int t,amount,type,time,charge,si,i,j,n,max,camount;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&amount,&time,&n);
		max=amount;
		for(i=0;i<n;i++)
		{
			camount=amount;
			scanf("%d%lf%d",&type,&rate,&charge);
			//rate/=8192;
			if(type==0) // for simple interest
			{
				si=0;
				for(j=0;j<time;j++)
				{
					si=si+(int)(amount*rate);
					amount-=charge;
					//printf(" 0 amount = %d\n",amount);
				}
				if(si+amount>max)
					max=si+amount;
			}
			else // for compound interest
			{
				for(j=0;j<time;j++)
				{
					amount=(int)(amount*(1+rate)-charge);
					//printf(" 1 amount = %d\n",amount);	
				}
				if(amount>max)
					max=amount;
			}
			amount=camount;
		}
		printf("%d\n",max);
	}
	return 0;
}
