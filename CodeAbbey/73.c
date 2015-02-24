#include<stdio.h>
#include<math.h>
int main()
{
	int t,i;
	double x,y;
	char str[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		x=y=0.0;
		for(i=0;str[i];i++)
		{
			switch(str[i])
			{
				case 'A':x+=1;				y+=0;				break;
				case 'B':x+=0.5;			y+=sqrt(3)/2;		break;
				case 'C':x+=-0.5;			y+=sqrt(3)/2;		break;
				case 'D':x+=-1;				y+=0;				break;
				case 'E':x+=-0.5;			y+=-sqrt(3)/2;		break;
				case 'F':x+=0.5;			y+=-sqrt(3)/2;		break;
			}
		}
		printf("%0.10f ",sqrt(x*x+y*y));
	}
	return 0;
}
