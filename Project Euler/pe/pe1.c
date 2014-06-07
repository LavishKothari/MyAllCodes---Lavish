#include<stdio.h>
#include<conio.h>
#include<time.h>
int main()
{
	long sum=0;
	int i;
	for(i=0;i<1000;i++)
		if(i%3==0 || i%5==0)
		{
			sum+=i;
			printf("%d\t",i);
		}
	printf("\n\n%ld\n",sum);
	printf("EXECUTION TIME = %f",clock()/CLK_TCK);
	system("pause");
}
