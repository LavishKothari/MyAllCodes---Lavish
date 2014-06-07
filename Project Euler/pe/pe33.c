#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i,j;
	for(i=11;i<99;i++)
	{
		if(i%10==0)
			continue;
		for(j=11;j<i;j++)
		{
			if(j%10==0)
			continue;

			if(((float)(j%10)*(int)(j/10))/(i%10*(int)(i/10))==(float)j/i)
			{
				if(i%10==j%10 || i/10==j/10 || i%10==j/10 || i/10==j%10)
				printf("i=%d j=%d\n",i,j);
			}
		}
	}
	printf("\nEXECUTION TIME = %f\n",clock()/(float)CLK_TCK);
	system("pause");
}