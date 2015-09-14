#include<stdio.h>
#include<stdlib.h>
struct lane
{
	long long int l,h;
};
int main()
{
	long long int j,t,n,h,minl,maxh,minanswer,answer,i,k;
	struct lane*arr;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&h);
		arr=(struct lane*)malloc(sizeof(struct lane)*n);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&arr[i].l,&arr[i].h);
			if(i==0)
			{
				minl=arr[i].l;
				maxh=arr[i].h;
			}
			else
			{
				if(arr[i].l<minl)
					minl=arr[i].l;
				if(arr[i].h>maxh)
					maxh=arr[i].h;
			}
		}
		minanswer=n*n;
		//printf("This is a test %lld %lld\n",minl,maxh);
		for(i=0;i<=maxh && i+h<=n;i++)
		{
			answer=0;
			for(j=0;j<n;j++)
			{
				for(k=i;k<i+h;k++)
				{
					if(k<arr[j].l || k>arr[j].h)
						answer++;
				}
				/*
				if(i+h-1>=arr[j].l && i<arr[j].l)
				{
					//printf("A");
					answer+=arr[j].l-i;
				}
				else if(i>=arr[j].l && i<=arr[j].h && i+h-1>arr[j].h)
				{
					//printf("B");
					answer+=i+h-1-arr[j].h;
				}
				else if(i>=arr[j].l && i+h-1<=arr[j].h)
				{
					//printf("C");
					answer+=0;
				}
				else if(i<arr[j].h && i+h>arr[j].h)
				{
					//printf("D");
					answer+=arr[j].l-i+i+h-arr[j].l;
				}
				else if(i+h-1<arr[j].l)
				{
					//printf("E");
					answer+=h;
				}
				else if(i>arr[j].h)
				{
					//printf("F");
					answer+=h;
				}
				//printf("%lld, ",answer);
				*/
			}
			//printf("\nRemoval = %lld\n",answer);
			if(minanswer>answer)
				minanswer=answer;
		}
		printf("%lld\n",minanswer);
		free(arr);
	}
	return 0;
}
