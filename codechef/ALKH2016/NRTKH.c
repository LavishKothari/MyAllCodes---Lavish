#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,suma,answer,sumb,i,*flaga,*flagb,j,n,a,b;
	char str[100001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf(" %s",str);
		flaga=(int*)malloc(sizeof(int)*n);
		flagb=(int*)malloc(sizeof(int)*n);
		for(i=0;str[i];i++)
			flaga[i]=flagb[i]=0;
		suma=0;sumb=0;
		for(i=0;str[i];i++)
		{
			if(str[i]=='a')
				suma++;
			flaga[i]=suma;
			if(str[i]=='b')
				sumb++;
			flagb[i]=sumb;
			//printf("%d %d\n",flaga[i],flagb[i]);
		}
		answer=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				// extracting the substring from ith index till the jth index.
				if(i==0) a=flaga[j]; else a=flaga[j]-flaga[i-1];
				if(i==0) b=flagb[j]; else b=flagb[j]-flagb[i-1];
				if(a!=0 && b!=0 && 2*a==3*b)
					answer++;
			}
		printf("%d\n",answer);
		
	}
	return 0;
}
