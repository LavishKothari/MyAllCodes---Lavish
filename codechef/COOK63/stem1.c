#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int main()
{
	char **strings;
	int t,i,n,max,j,k,maxi,maxj,lena;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		strings=(char**)malloc(sizeof(char*)*n);
		for(i=0;i<n;i++)
			strings[i]=(char*)malloc(sizeof(char)*21);
		for(i=0;i<n;i++)
			scanf(" %s",strings[i]);
		lena=strlen(strings[0]);
		max=0;
		for(i=0;i<lena;i++)
		{
			for(j=i;j<lena;j++)
			{
				for(k=1;k<n;k++)
				{
					if(isSubString(strings[0],i,j,strings[k]) && max<j-i+1)
					{
						maxi=i;maxj=j;max=j-i+1;
					}
					else if(isSubString(strings[0],i,j,strings[k]) && max==j-i+1 && mycmp(strings[0],maxi,maxj,i,j)==0)
					{
						maxi=i;maxj=j;
					}
				}
			}
		}
		
	}
	return 0;
}
