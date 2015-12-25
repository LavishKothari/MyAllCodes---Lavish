#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int*arr=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		if(n&1)
		{
			int answer=0;
			for(int i=0;i<n;i+=2)
				answer=answer^arr[i];
			printf("%d\n",answer);
		}
		else printf("0\n");
		delete(arr);
	}
	return 0;
}
