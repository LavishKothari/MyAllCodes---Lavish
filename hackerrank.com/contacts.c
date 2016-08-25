#include<stdio.h>
#include<string.h>

char s[100001][22];
int n;

int isPrefix(char *a,char *b)
{
	int i;
	for(i=0;a[i];i++)
		if(a[i]!=b[i])
			return 0;
	return 1;
}

int find(char *temp)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(isPrefix(temp,s[i]))
			count++;
	}
	return count;
}

int main(){
	int i;
	char temp[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %s",temp);
		if(strcmp(temp,"add")==0)
			scanf(" %s",s[i]);
		else {
			scanf(" %s",temp);
			printf("%d\n",find(temp));
		}
	}
	return 0;
}
