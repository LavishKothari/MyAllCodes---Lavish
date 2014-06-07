#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int no[]={1,2,3,4,5,6,7,8,9};

long*store_in_array(long ,int );
int count_digits(long);
int is_equal(long*,long*,int );

int main()
{
	long i,max=0,n,digits,*arr;
	int j;
	arr=(long *)malloc(sizeof(long)*9);
	for(i=1;i<=10000;i++)
	{
		n=0;
		for(j=1;j<=9;j++)
		{
			digits=count_digits(i*j);
			n=(n*(long)pow(10,digits))+(i*j);
			
			arr=store_in_array(n,count_digits(n));

			if(count_digits(n)==9)
			{
				if(is_equal(no,arr,9))
				{
					if(n>max)
						max=n;
				}
			}
		}
	}
	printf("%ld\n",max);


	system("pause");
}




int is_equal(long*a,long*b,int counter)
{
	long tmp;
	int i,j,count=0;
	for(i=0;i<counter;i++)
	{
		for(j=i;j<counter;j++)
		{
			if(a[i]==b[j])
			{
				count++;
				tmp=b[j];
				b[j]=b[i];
				b[i]=tmp;
				break;
			}
		}
	}
	if(count==counter)
		return 1;
	return 0;
}



long*store_in_array(long n,int counter)
{
	long*arr,copy_n;
	int i;

	copy_n=n;
	

	arr=(long*)malloc(sizeof(long)*counter);


	for(i=0;i<counter;i++)
		arr[i]=0;

	for(i=counter-1;i>=0;i--)
	{
		arr[i]=n%10;
		n/=10;
	}

	return arr;
}


int count_digits(long num)
{
	int flag=0;
	while(num)
	{
		flag++;
		num/=10;
	}
	return flag;
}