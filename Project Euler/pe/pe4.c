#include<stdio.h>
#include<conio.h>

int ispalindrome(long);

int main()
{
	int i,j,x,y;
	long max=0;
	
	for(i=100;i<=999;i++)
		for(j=100;j<=999;j++)
		{
			if(ispalindrome(i*j))
				if((i*j)>max)
				{
					max=i*j;
					x=i;
					y=j;
				}
		}
	

	printf("%d * %d = %ld\n",x,y,(max));
	system("pause");
}

int ispalindrome(long num)
{
	long reverse=0,c_num;
	c_num=num;
	while(num)
	{
		reverse=(reverse*10)+(num%10);
		num/=10;
	}

	if(reverse==c_num)
		return 1;
	return 0;
}
