#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,x,y;
	char str[100],temp[100],t[100];
	scanf("%[^\n]s",str);
	while(1)
	{
		scanf(" %s",t);
		if(t[0]=='D')
		{
			scanf(" %s",t);
			break;
		}
		scanf(" %lf %s %s %s %lf",&a,temp,temp,temp,&b);
		x+=a*cos(b*M_PI/180);
		y+=a*sin(b*M_PI/180);
	}
	printf("%d %d\n",(int)round(y),(int)round(x));
	return 0;
}
