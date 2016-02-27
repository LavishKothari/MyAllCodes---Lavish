#include<stdio.h>
int findAnswer(int a,int b,int c,int d,int e,int f)
{
	if(a+b+f<0 || a+b+c+d<0 || a+e+d<0)
	{
		for(int p=1;p<=20;p++)
		{
			if(a+b+f<0 && a+b+f+p>=0 && (a+p<=20 || b+p<=20 || f+p<=20))
				return p;
			else if(a+b+c+d<0 && a+b+c+d+p>=0 && (a+p<=20 || b+p<=20 || c+p<=20 || d+p<=20))
				return p;
			else if(a+e+d<0 && a+e+d+p>=0 && (a+p<=20 || e+p<=20 || d+p<=20))
				return p;
		}
		return -1;
	}
	else return 0;
}
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	printf("%d\n",findAnswer(a,b,c,d,e,f));
	return 0;
}
