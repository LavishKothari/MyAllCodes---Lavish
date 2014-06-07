#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

long find_max(int*);
int main()
{
	FILE *f;
	long answer;
	int *arr,i=0;
	char c;
	arr=(int*)malloc(sizeof(int)*1000);

	f=fopen("D:/a.txt","r");
	if(f)
	{
		while(!feof(f))
		{
			fscanf(f,"%c",&c);
			arr[i++]=(int)c-48;
		}
	}
	else
		printf("file operation not successful\n");

	printf("\nAnswer = %ld",find_max(arr));

	printf("\n\n");

	system("pause");
}


long find_max(int *arr)
{
	int i,j;
	long max=0,product=1;
	for(i=0;i<995;i++)
	{
		product=1;
		for(j=0;j<5;j++)
			product=product*arr[i+j];
		
		if(product>max)
			max=product;
	}
	return max;
}