#include<stdio.h>
int main()
{
    int i,j,k ,sum1=0 ,sum2=0 ,sum3=0 ,sum=0 ,num;
    printf("please enter a number" );
    scanf("%d",&num );
    for (i=3;i<num;i++)
        if (i%3==0) sum1 =sum1 +i ;
    for (j=5;j<num;j++)
        if (j%5==0) sum2=sum2+j ;
    for (k=15;k<num;k++)
        if (k%15==0) sum3 =sum3+k;
    sum =sum+sum1+sum2-sum3;
    printf("%d" ,sum);
    return 0 ;
}
