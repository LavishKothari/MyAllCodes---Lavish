#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//#include<conio.h>

void main()
{
	float i,j,k;
	for(i=1;i<1000;i++)
		for(j=1;j<1000;j++)
			for(k=1;k<1000;k++)
				if((i+j+k)==1000&&(k*k==i*i+j*j))
				{
					printf("%f\n",(i*j*k));
					printf("\nEXECUTION TIME = %f\n\n",clock()/(float)CLK_TCK);
					system("pause");
					return;
				}
	printf("EXECUTION TIME = %f",clock()/(float)CLK_TCK);
	//system("pause");
}
