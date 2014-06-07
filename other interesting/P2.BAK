//PROGRAM TO CALCULATE POWER OF 2

#include<stdio.h>
#include<conio.h>
#define max 10000


void main()
{
	int arr[max],aarr[max],i,j,flag,lavish,tag,sum=0;
	clrscr();

	printf("program to calculate power of 2\n");
	printf("x^(number)\n");
	printf("enter the number\n");
	scanf("%d",&lavish);

	for(i=0;i<max;i++)
	{
		arr[i]=0;
		aarr[i]=0;
	}

	printf("\n\n");

	arr[max-1]=2;

	flag=1;

	while(1)
	{
		flag++;
		for(i=max-1;i>=0;i--)
		{
			aarr[i]=aarr[i]+((2*arr[i])%10);
			if(arr[i]>=5&&arr[i]<10)
				aarr[i-1]=1;
		}


		for(i=0;i<=max-1;i++)
		{
			arr[i]=aarr[i];
			aarr[i]=0;
		}

		tag=0;

		if(flag==lavish)
		{
			for(i=0;i<max;i++)
			{
				if(arr[i]!=0)
					tag=1;
				if(tag==1)
				{
					printf("%d",arr[i]);
					sum=sum+arr[i];
				}
			}
			break;
		}
	}

	printf("\n\nsum of all digits is:-%d",sum);
	getch();
}

