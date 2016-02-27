#include<stdio.h>
int find(int n,int flag)
{
	if(n==1)
		return 1;
	if(n==2 && flag==1)
		return 2;
	if(n==2 && flag==2)
		return 1;
	if(n%2==0 && flag==1)			// e1
		return find(n/2,1)*2; 	
	else if(n%2==1 && flag==1)		// o1
		return find(n/2,2)*2;
	else if(n%2==0 && flag==2)		// e2
		return find(n/2,2)*2-1;
	else if(n%2==1 && flag==2)		// o2
		return find(n/2+1,1)*2-1;	
}
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",find(n,1));
	}
	return 0;
}
