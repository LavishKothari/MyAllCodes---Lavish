#include<stdio.h>
#include<conio.h>
#include<math.h>

long*store_in_array(long,int);
int is_equal(long*,long*,int);

int main()
{
	long n,i,*n_arr,*c_arr,copy_n;
	int counter=0;
	clrscr();
	printf("ENTER A NUMBER : ");
	scanf("%ld",&n);
	copy_n=n;
	while(copy_n)
	{
		counter++;
		copy_n/=10;
	}

	n_arr=store_in_array(n,counter);

	for(i=0;i<(long)pow(10,counter);i++)
	{
		c_arr=store_in_array(i,counter);
		if(is_equal(n_arr,c_arr,counter))
			printf("%ld\t",i);
	}
	getch();
	return 1;
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

int is_equal(long*a,long*b,int counter)
{
	long tmp;
	int i,j,count=0;
	for(i=0;i<counter;i++)
		for(j=i;j<counter;j++)
			if(a[i]==b[j])
			{
				count++;
				tmp=b[j];
				b[j]=b[i];
				b[i]=tmp;
				break;
			}
	if(count==counter)
		return 1;
	return 0;
}

