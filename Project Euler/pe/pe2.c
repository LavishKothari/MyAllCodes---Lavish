#include<stdio.h>
#include<conio.h>

void main()
{
	long a=1,b=2,c=0,sum=0;
	while(1)
	{
		c=a+b;
		if(c>4000000)
			break;

		printf("%ld\n",c);
		if(c%2==0)
			sum+=c;
		a=b;
		b=c;
	}
	printf("\n\nsum = %ld\n",sum+2);
	system("pause");
}