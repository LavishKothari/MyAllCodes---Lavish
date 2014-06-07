#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>

int main()
{
	FILE *f;
	int i,j,k, **arr,*ans,tmp;
	char c;
	ans=(int *)malloc(sizeof(int)*100);
	
	for(i=0;i<100;i++)
		ans[i]=0;

	arr=(int **)malloc(sizeof(int *)*100);
	for(i=0;i<100;i++)
		arr[i]=(int *)malloc(sizeof(int)*50);

	f=fopen("D:/c.txt","r");
	if(f)
	{
		for(i=0;i<100;i++)
			for(j=0;j<50;j++)
			{
				fscanf(f," %c",&c);
				arr[i][j]=(int)c-48;
			}
		printf("FILE OPERATION SUCCESSFUL\n");
	}
	else
		printf("\nFILE OPERATION WAS NOT SUCCESSFUL!!!\n");
	
	for(i=49,k=99;i>=0;i--,k--)
		for(j=99;j>=0;j--)
		{
			ans[k]+=arr[j][i];
			if(ans[k]>=10)
			{
				tmp=ans[k]/10;
				ans[k]%=10;
				ans[k-1]+=tmp;
			}
		}

	for(i=0;i<100;i++)
		printf("%d",ans[i]);

	printf("\nEXECUTION TIME = %f\n",clock()/(float)CLK_TCK);
	system("pause");
}