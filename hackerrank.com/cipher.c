#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printAnswer(char *arr,int n,int k)
{
	char *answer;
	int i,temp;
	answer=(char*)malloc(sizeof(char)*n);
	answer[0]=arr[0];
	for(i=1;i<k && i<n;i++)
		answer[i]=((arr[i]-'0')^(arr[i-1]-'0'))+'0';
	temp=arr[k-1]-'0';
	for(i=k;i<n;i++)
	{
		temp=temp^(answer[i-k]-'0')^(arr[i]-'0');
		answer[i]=temp+'0';
		temp=arr[i]-'0';
	}
	answer[i]='\0';
	printf("%s\n",answer);
}
int main()
{
	int n,k,i,j,len;
	char arr[2000001];
	scanf("%d%d",&n,&k);
	scanf("%s",arr);
	printAnswer(arr,n,k);
	return 0;
}
