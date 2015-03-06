#include<math.h>
#include<stdio.h>
#define LEN_HOUR 6
#define LEN_MIN 9

int main()
{
	int a,b,t;
	char str[6];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		a=(str[0]-'0')*10+str[1]-'0';
		b=(str[3]-'0')*10+str[4]-'0';
		if(a>=12) a-=12;
		//printf("\n this is a check = %d %d %f %f\n",a,b,cos(0),sin(90));
		printf("%0.10f %0.10f %0.10f %0.10f ",10+LEN_HOUR*sin((30*a+b/2.0)*M_PI/180),10+LEN_HOUR*cos((30*a+b/2.0)*M_PI/180),10+LEN_MIN*sin(6*b*M_PI/180),10+LEN_MIN*cos(6*b*M_PI/180));
	}
	return 0;
}
