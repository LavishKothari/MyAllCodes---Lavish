#include<conio.h>
#include<stdio.h>

void decimal_to_binary(unsigned char);

union u
{
	int i;
	char c;
};

int main()
{
	char*ptr;
	union u a;

	printf("ENTER AN INTEGER : \n");
	scanf("%d",&a.i);

	ptr=&a.i;

	ptr++;
	decimal_to_binary(*ptr);

	ptr--;
	decimal_to_binary(*ptr);

	getch();
	return 0;
}

void decimal_to_binary(unsigned char n)
{
	int arr[8];
	int i;

	for(i=7;i>=0;i--)
	{
		if(n%2==0)
			arr[i]=0;
		else
			arr[i]=1;
		n/=2;
	}

	for(i=0;i<8;i++)
		printf("%d",arr[i]);
	printf(" ");
}