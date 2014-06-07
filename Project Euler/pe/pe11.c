#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

long find_max(int **);

int main()
{
	FILE *f;
	int **arr,i=0,j;
	arr=(int **)malloc(sizeof(int*)*20);
	for(i=0;i<20;i++)
		arr[i]=(int *)malloc(sizeof(int)*20);

	f=fopen("D:/b.txt","r");
	if(f)
		for(i=0;i<20;i++)
			for(j=0;j<20;j++)
				fscanf(f,"%d",&arr[i][j]);	
	else
		printf("file operation not successful\n");

	printf("Answer = %ld\n",find_max(arr));
	
	system("pause");
}


long find_max(int **arr)
{
	int i,j,k;
	long product,max=0;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		{
			/*checking for horizontal sequence*/
			product=1;
			for(k=0;k<4;k++)
			{
				if(j+k<20)
				{
					product*=arr[i][j+k];
				}
			}
			if(product>max)
				max=product;
			
			/*checking for vertical sequence*/
			product=1;
			for(k=0;k<4;k++)
			{
				if(i+k<20)
				{
					product*=arr[i+k][j];
				}
			}
			if(product>max)
				max=product;
			
			product=1;
			for(k=0;k<4;k++)
			{
				if( (i+k<20) && (j+k<20) )
				{
					product*=arr[i+k][j+k];
				}
			}
			if(product>max)
				max=product;

			product=1;
			for(k=0;k<4;k++)
			{
				if( (i+k<20) && (j-k>20) )
				{
					product*=arr[i+k][j-k];
				}
			}
			if(product>max)
				max=product;
			

		}
		return max;
}