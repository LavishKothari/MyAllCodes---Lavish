#include<stdio.h>
 #define max 4000
 void multiply(long int *,long int);

int main()
{
    int t,a,b,i,j;
    int answer[9][4000];
    for(i=1;i<=9;i++)
    {
        printf("%d\n",i);
        for(j=0;j<=4000;j++)
        {
            printf("j = %d\n",j);
            answer[i][j]=findSum(i,j);
        }
    }
    printf("Enter");
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",i,answer[a][b]);
    }
    return 0;
}
 int findSum(int num,int power)
 {

     int ans=0,i;
     int a[max]={0};
    a[max-1]=1;
    for(i=0;i<power;i++)
        multiply(a,num);
     long int flag=0;

     for(i=0;i<max;i++)
     {
         if(flag||a[i]!=0)
         {
             flag=1;
             //printf("%d",a[i]);
             ans=ans+a[i];
         }
     }
     return ans;
 }

void multiply(long int *a,long int n)
 {
    long long int i;
     for(i=0;i<max;i++)
         a[i]=a[i]*n;

     for(i=max-1;i>0;i--)
     {
         a[i-1]=a[i-1]+(a[i]/10);
         a[i]=a[i]%10;
     }
 }
