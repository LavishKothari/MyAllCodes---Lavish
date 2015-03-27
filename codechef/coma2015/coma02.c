#include<stdlib.h>
#include<stdio.h>
int cfun(const void*a,const void*b)
{
	return (*(int *)a - *(int*)b);
}
int main()
{
	int n,m,o,*arr,counter,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&o);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		if(arr[0]<o)
			printf("-1\n");
		else
		{
			counter=0;
			for(i=0;i<n;i++)
			{
				if(arr[i]>=o) counter++;
				if(counter>m)
					break;
			}
			if(counter>m)counter--;
			printf("%d\n",counter);
		}
	}
	return 0;
}
