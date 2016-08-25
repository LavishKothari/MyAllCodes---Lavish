#include<stdio.h>
char a[27];
void printAnswer(int n)
{
	int i;
	for(i=0;i<n/26;i++)
		printf("%s",a);
	n=n%26;
	if(n<26)
	{
		for(i=0;i<n;i++)
			printf("%c",a[i]);
	}	
	printf("\n");
}
int main()
{
	int t,i,answer,n;
	
	for(i=0;i<26;i++) a[i]='a'+i;
	a[i]='\0';
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printAnswer(n);
	}
	return 0;
}
