#include<conio.h>
#include<stdio.h>

void decimal_to_binary(unsigned char);

union u
{
	float f;
	char c;
};

int main()
{
	int i;
	char*ptr;
	union u a;

	clrscr();
	printf("ENTER THE FLOATING POINT NUMBER : \n");
	scanf("%f",&a.f);

	ptr=&a.c+sizeof(float);

	for(i=0;i<sizeof(float);i++)
	{
		ptr--;
		decimal_to_binary(*ptr);
	}

	getch();
	return 0;
}

void decimal_to_binary(unsigned char n)
{
	int arr[8];
	int i;
	//printf("n = %u  ",n);

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