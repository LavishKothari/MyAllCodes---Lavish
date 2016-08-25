#include<stdio.h>
#define MAX 100001
int stack[MAX],ind=0,maxarr[MAX];
void push(int x)
{
	stack[ind]=x;
	if(ind==0)
		maxarr[0]=stack[0];
	else
		maxarr[ind]=stack[ind]>maxarr[ind-1]?stack[ind]:maxarr[ind-1];
	ind++;
}
void pop()
{
	ind--;
}
int main()
{
	int n,x,ch;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&x);
			push(x);
		}	
		if(ch==2)
			pop();
		if(ch==3)
			printf("%d\n",maxarr[ind-1]);
	}
	return 0;
}
