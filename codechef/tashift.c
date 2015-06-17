#include<stdio.h>
int findLongestPrefix(char *a,char *b)
{
	int counter=0,i;
	for(i=0;a[i];i++)
		if(a[i]==b[i])
			counter++;
		else
			break;
	return counter;
}
void shift(char *a,int len)
{
	int i;
	char temp;
	temp=a[0];
	for(i=0;i<len-1;i++)
		a[i]=a[i+1];
	a[len-1]=temp;
}
int main()
{
	int n,temp,max,i;
	char a[1000001],b[1000001];
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%s",b);
	printf("%s\n%s\n",a,b);
	max=findLongestPrefix(a,b);
	printf("max = %d\n",max);
	for(i=1;i<n;i++)
	{
		shift(b,n);
		temp=findLongestPrefix(a,b);
		printf("%s %s---%d\n",a,b,temp);
		if(temp>max)
			max=temp;
	}
	printf("%d",max);
	return 0;
}
