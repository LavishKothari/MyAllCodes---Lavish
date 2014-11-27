
/*BUBBLE SORT - ASCENDING ORDER*/

#include<stdio.h>
#include<conio.h>
void main()
{
int arr[20],i,j,n,temp,flag;
clrscr();

printf("enter the number of elements\n");
scanf("%d",&n) ;

printf("enter the data of array");


for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

printf("\n\n\n");


for(i=1;i<n;i++)
{
	flag=0;
	for(j=0;j<n-i;j++)
		if(arr[j]>arr[j+1])
		{
			flag=1;

			temp=arr[j];
			arr[j]=arr[j+1] ;
			arr[j+1]=temp;
		}

	if(flag==0)
		break;
}
for(i=0;i<n;i++)
printf("%d\n",arr[i]);

getch();
}

