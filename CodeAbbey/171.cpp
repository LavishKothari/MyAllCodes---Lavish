#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int d;
		float degree;
		scanf("%d%f",&d,&degree);
		printf("%g\n",round(d/(tan((180-degree)*3.14/180.0))));
	}
	return 0;
}
