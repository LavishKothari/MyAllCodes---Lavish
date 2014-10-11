//PROGRAM TO FIND ALL THE PRIME NUMBERS WITHIN GIVEN RANGE

#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	long ll,ul,i,j;

	printf("ENTER THE LOWER LIMIT : ");
	scanf("%ld",&ll);

	printf("ENTER THE UPPER LIMIT : ");
	scanf("%ld",&ul);

	for(i=ll;i<=ul;i++)
	{
		if(i==1)
			i++;

		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				goto lavish;
			}
		}
		printf("%ld\t",i);
		lavish : ;
	}

	getch();
	return 1;
}


