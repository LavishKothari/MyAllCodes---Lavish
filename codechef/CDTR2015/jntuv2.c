#include<stdio.h>
#include<string.h>

void print(int*arr)
{
	int i,flag=0,j;
	for(i=0;arr[i]==0;i++);
	if(i<=149)
	{
	    for(j=i;j<=149;j++)
	    {
	        printf("%d",arr[j]);
	    }
	}
	else
	    printf("0");
    printf("\n");
}
int main()
{
	char a[150],b[150];
	int sum[150],ci,i,j,counter;
	scanf("%s%s",a,b);

	for(i=0;i<150;i++)
		sum[i]=0;

    counter=149;
    for(i=strlen(a)-1,j=strlen(b)-1;i>=0 || j>=0;)
    {
        if(i>=0 && j>=0)
        {
            sum[counter]=a[i]+b[j]-2*'0';
            counter--;
            i--;j--;
        }
        else if(i>=0)
        {
            sum[counter]=a[i]-'0';
            counter--;i--;
        }
        else if(j>=0)
        {
            sum[counter]=b[j]-'0';
            counter--;j--;
        }
    }
	
	for(i=149;i>=1;i--)
	{
		if(sum[i]>9)
		{
			sum[i-1]+=sum[i]/10;
			sum[i]=sum[i]%10;
		}
	}
	printf("Result = ");
	print(sum);
	return 0;
}