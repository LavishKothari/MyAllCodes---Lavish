#include<stdio.h>
#include<stdlib.h>
int arr[100000];
int findNumber(int *arr,int len,int pointer,int d)
{
	int i=(pointer+d)%len;
	return arr[i];
}
int main()
{
	int d,i,n,m,pointer;
	char ch;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	pointer=0;
	for(i=0;i<m;i++)
	{
		scanf(" %c",&ch);
		scanf("%d",&d);
		if(ch=='R')
			printf("%d\n",findNumber(arr,n,pointer,d-1));
		else if(ch=='C')
			pointer=(pointer+d)%n;
		else if(ch=='A')
        {
            d=n-d;
            pointer=(pointer+d)%n;
        }
	}
	return 0;
}
