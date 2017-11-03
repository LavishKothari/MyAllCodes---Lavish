#include<stdio.h>
int sol(int c,int v0,int v1,int a,int l)
{
	if(c<=v0)
		return 1;
	int rp=v0;// read pages
	int days=1;
	int x=0;
	while(1)
	{
		days++;
		x++;
		int y=v0+x*a;
		if(y>v1)
			y=v1;
		rp+=y-l;
		if(rp>=c)
			return days;
	}
}
int main()
{
	int c,v0,v1,a,l;
	scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
	printf("%d\n",sol(c,v0,v1,a,l));
	return 0;
}
