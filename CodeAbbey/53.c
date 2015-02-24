#include<stdio.h>
int isPossible(int a,int b,int c,int d)
{
	if(a==c || b==d)
		return 1;
	if(a+b==c+d)
		return 1;
	if((a-b)==(c-d))
		return 1;
	return 0;
}

int main()
{
	int t,w,x,y,z;
	char str[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %[^\n]s",str);
		w=str[0]-'a';
		x=str[1]-'0';
		y=str[3]-'a';
		z=str[4]-'0';
		if(isPossible(w,x,y,z))
			printf("Y ");
		else printf("N ");
	}
	return 0;
}
