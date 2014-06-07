//project euler solution to problem no. 49


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


int no=0;
// no stores the total number of permutations of any number.

long*store_in_array(long,int);
int is_equal(long*,long*,int); 
long* permutation(long); 
int isprime(long);
void check_for_ap(long*,int);

void main()
{
	long i;int j;
	int flag=0,k;
	long *arr,*p_arr;
	
	for(i=1000;i<=9999;i++)
	{
		
		flag=0;k=0;
		if(!isprime(i))
			continue;
		//printf("i = %ld\t",i);
		arr=permutation(i);
		
	
		for(j=0;j<no;j++)
			if(isprime(arr[j]))
				flag++;
		
		p_arr=(long*)malloc(sizeof(long)*(flag));
		
		
		for(j=0,k=0;j<no;j++)
			if(isprime(arr[j]))
			{
				p_arr[k]=arr[j];
				k++;
			}

		
		/*	
		for(j=0;j<flag;j++)
			printf("%ld\t",p_arr[j]);

		printf("\n");
		*/

		check_for_ap(p_arr,flag);


		free(p_arr);

	}
	
	system("pause");
}



void check_for_ap(long* arr, int flag)
{
	int i,j,k;
	for(i=0;i<flag;i++)
		for(j=i+1;j<flag;j++)
			for(k=j+1;k<flag;k++)
			{
				if((arr[i]-arr[j])==arr[j]-arr[k])
					printf("%ld   %ld   %ld\n\n",arr[i],arr[j],arr[k]);
			}
}




int isprime(long n)
{
	long i;
	for(i=2;i<=(long)sqrt(n);i++)
		if(n%i==0)
			return 0;
	return 1;
}


long* permutation(long n)
{

	long i,*n_arr,*c_arr,copy_n,*result;
	int counter=0,abc=0,flag=0;
	
	
	copy_n=n;
	while(copy_n)
	{
		counter++;
		copy_n/=10;
	}

	n_arr=store_in_array(n,counter);


	for(i=0,abc=0;i<(long)pow(10,counter);i++)
	{
		c_arr=store_in_array(i,counter);
		if(is_equal(n_arr,c_arr,counter))
		{
			//printf("printing - > %ld\n",i);
			flag++;
		}
	}

	no=flag;

	result=(long*)malloc(sizeof(long)*(flag));
	for(i=0,abc=0;i<(long)pow(10,counter);i++)
	{
		c_arr=store_in_array(i,counter);
		if(is_equal(n_arr,c_arr,counter))
		{
			//printf("printing - > %ld\n",i);
			result[abc++]=i;
		}
	}
	
	return result;
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

