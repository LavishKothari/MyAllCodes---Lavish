#include<stdio.h>
#include<conio.h>
#define max 2000

int arr1[max],arr2[max],arr3[max];

void fun(void);

int main()
{
	int num,i,j,tag=0;
	clrscr();
	for(i=0;i<max;i++)
		arr1[i]=arr2[i]=arr3[i]=0;

	arr2[max-1]=1;

	printf("ENTER THE TERM : ");
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		fun();

		if(i==num-3)
			break;

		for(j=0;j<max;j++)
			arr1[j]=arr2[j];

		for(j=0;j<max;j++)
			arr2[j]=arr3[j];

	}

	for(i=0;i<max;i++)
	{
		if(tag||arr3[i])
		{
			tag=1;
			printf("%d",arr3[i]);
		}
	}


	getch();
	return 1;
}

void fun(void)
{
	int i,temp;
	for(i=0;i<max;i++)
		arr3[i]=arr1[i]+arr2[i];

	for(i=max-1;i>0;i--)
	{
		if(arr3[i]>9)
		{
			temp=arr3[i];
			arr3[i]%=10;
			arr3[i-1]+=(temp/10);
		}
	}
}


