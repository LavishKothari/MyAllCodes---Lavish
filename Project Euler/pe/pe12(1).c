#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	long i,j,sum,flag=0;
    for(i=1;;i++)
    {
		flag=0;
		sum=i*(i+1)/2;
 
		 for(j=1;j<sqrt((double)sum);j++)
		 {
			 if(sum%j==0)
			 flag++;
		 }
 
	    flag=flag*2;
		if(sum%(long)sqrt((double)sum)==0)
			flag++;
		if(flag>500)
		{
			printf("%ld\t",sum);
			
			printf("\nEXECUTIONN TIME = %f\n",clock()/(float)CLK_TCK);
		    system("pause");
			return;
		}
    }
}











