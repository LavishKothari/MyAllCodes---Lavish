#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int get_sum(int *);

int main()
{
	FILE *f;
	int arr[100][100],max1[100],max2[100],i=0,j=0,maximum=0;
	
	f=fopen("D:/e.txt","r");
	i=0;
	for(i=0;i<100;i++)
		for(j=0;j<=i;j++)
		{
			fscanf(f,"%d",&arr[i][j]);
		}

	for(i=0;i<100;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i==0)
			{
				max1[j]=arr[i][j];
				continue;
			}
			else if((j-1)<0)
			{
				max2[j]=arr[i][j]+max1[j];
			}
			else if(j==i)
				max2[j]=arr[i][j]+max1[j-1];
			else
				max2[j]=arr[i][j]+((max1[j-1]>max1[j])?max1[j-1]:max1[j]);		
		}

		if(i==0)
			continue;
			
		for(j=0;j<=i;j++)
			max1[j]=max2[j];

	}
	
	for(i=0;i<100;i++)
		if(maximum<max2[i])
			maximum=max2[i];
	printf("Answer = %d\n\n",maximum);
	
	printf("\nEXECUTION TIME = %f\n",clock()/(float)CLK_TCK);
	system("pause");
}