#include<stdio.h>

int main()
{
	int n,h,i,pos,c,have;
	int arr[100001];
	scanf("%d%d",&n,&h);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	pos=0;have=0;
	while(1)
	{
		scanf("%d",&c);
		if(c==0)
			break;
		if(c==1 && pos>0)
			pos--;
		if(c==2 && pos<n-1)
			pos++;
		if(c==3 && arr[pos]>0 && !have)
		{
			have=1;
			arr[pos]--;
		}
		if(c==4 && arr[pos]<h && have)
		{
			have=0;
			arr[pos]++;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
