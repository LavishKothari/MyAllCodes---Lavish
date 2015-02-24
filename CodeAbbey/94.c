#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,*arr,i,j;
	long long int answer;
	char str[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %[^\n]s",str);
		n=0;
		for(i=0;str[i];i++)
			if(str[i]==' ')
				n++;
		n++;
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0,j=0;i<n;i++,j++)
		{
			arr[i]=0;
			while(str[j] && str[j]!=' ')
			{
				arr[i]=arr[i]*10+str[j]-'0';
				j++;
			}
		}
		answer=0;
		for(i=0;i<n;i++)
			answer+=(arr[i]*(long long int)arr[i]);
		printf("%lld ",answer);
	}
	return 0;
}
