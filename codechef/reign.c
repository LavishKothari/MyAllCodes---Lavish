#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,t,n,k,j,sum,*arr,a,b,c,d,max,*answer;
	int ansa,ansb,ansc,ansd;
	scanf("%d",&t);
	answer=(int*)malloc(sizeof(int)*t);
	for(i=0;i<t;i++)
	{
		max=-1000000000-1;
		sum=0;
		scanf("%d%d",&n,&k);
		arr=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
			scanf("%d",&arr[j]);

		for(a=0;a<n;a++)	
			for(b=a;b<n;b++)
				for(c=b+k+1;c<n;c++)
					for(d=c;d<n;d++)
					{
						sum=0;

						for(j=a;j<=b;j++)
							sum+=arr[j];

						for(j=c;j<=d;j++)
							sum+=arr[j];
						if(sum>max)
							max=sum;
					}
		answer[i]=max;
	}
	for(i=0;i<t;i++)
		printf("%d\n",answer[i]);
	return 0;
}
