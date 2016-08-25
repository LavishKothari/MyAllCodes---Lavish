#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int find(int a,int b,int c,int d)
{
	int x;
	
	if(d==b)
		return 0;
	
	if(c>a && d>=b)
		return 0;
	if(a>c && b>=d)
		return 0;
	
	if(abs(a*d-b*c)%abs(d-b)==0)
	{
		x=(a*d-b*c)/(d-b);
		//printf("x=%d\n",x);
		if((x-a)%b!=0 || (x-c)%d!=0)
			return 0;
		if(x>0 && x>a && x>c)
			return 1;
	}
	return 0;
}
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(find(a,b,c,d))
		printf("YES\n");
	else printf("NO\n");
	return 0;
}
