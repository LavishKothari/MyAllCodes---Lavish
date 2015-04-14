#include<stdio.h>

int main()
{
	int t,prev,counter,n,i,current,currentunmatch,flag,prevunmatch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		counter=0;
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&current);
			if(i!=0)
			{
				if(current!=prev)
				{
					counter+=2;
					currentunmatch=i-1;
					flag=1;
				}
				if(prevunmatch+1==currentunmatch && flag==1)
					counter--;
			}
			prev=current;
			prevunmatch=currentunmatch;
		}
		printf("%d\n",counter);
	}
	return 0;
}
