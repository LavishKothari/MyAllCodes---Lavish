#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b;
int isSubString(char *x,int p,int q,char *y)
{
	int leny,i,ci,j;
	leny=strlen(y);
	for(i=0;i<leny;i++)
	{
		ci=i;
		for(j=p;j<=q;j++,i++)
		{
			if(x[j]!=y[i])
				break;
		}
		if(j==q+1)
			return 1;
		i=ci;
	}
	return 0;
}
int mycmp(char*x,int a,int b,int c,int d)
{
	int i;
	char s1[21],s2[21];
	for(i=a;i<=b;i++)
		s1[i-a]=x[i];
	s1[i-a]='\0';
	for(i=c;i<=d;i++)
		s2[i-c]=x[i];
	s2[i-c]='\0';
	return strcmp(s1,s2);
}
void updateAB(char *x,char *y)
{
	int i,j,max=0,lenx,maxi,maxj,isFound=0;
	lenx=strlen(x);
	for(i=a;i<=b;i++)
	{
		for(j=i;j<=b;j++)
		{
			if(isSubString(x,i,j,y) && j-i+1>max )
			{
				isFound=1;
				maxi=i;maxj=j;max=j-i+1;
			}
			if(isSubString(x,i,j,y) && j-i+1==max && mycmp(x,maxi,maxj,i,j)==1)
			{
				isFound=1;
				maxi=i;maxj=j;max=j-i+1;
			}
		}
	}
	if(isFound==0)
	{
		a=1;b=0;return;
	}
	if(maxi>=a && maxj<=b)
	{
		a=maxi;b=maxj;
	}
}
int main()
{
	char **strings;
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		strings=(char**)malloc(sizeof(char*)*n);
		for(i=0;i<n;i++)
			strings[i]=(char*)malloc(sizeof(char)*21);
		for(i=0;i<n;i++)
			scanf(" %s",strings[i]);
		a=0;
		b=strlen(strings[0])-1;
		for(i=1;i<n;i++)
			updateAB(strings[0],strings[i]);
		for(i=a;i<=b;i++)
			printf("%c",strings[0][i]);
		printf("\n");
	}
	return 0;
}
