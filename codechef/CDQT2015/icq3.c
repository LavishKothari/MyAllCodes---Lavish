#include<stdio.h>
int cm(const void*a,const void*b)
{
	return *(char*)a-*(char*)b;
}
int main()
{
	int t,ncounter,ccounter,i;
	char str[1000001];
	char n[1000001],c[1000001];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		ncounter=ccounter=0;
		for(i=0;str[i];i++)
		{
			if(str[i]>='a' && str[i]<='z')
				c[ccounter++]=str[i];
			else if(str[i]>='0' && str[i]<='9')
				n[ncounter++]=str[i];
		}
		/*
		printf("%d %d\n",ccounter,ncounter);
		for(i=0;i<ccounter;i++)
			printf("%c",c[i]);
		printf("\n");
		for(i=0;i<ncounter;i++)
			printf("%c",n[i]);
		printf("\n");
		*/
		qsort(c,ccounter,sizeof(char),cm);
		qsort(n,ncounter,sizeof(char),cm);
		ncounter=ccounter=0;
		for(i=0;str[i];i++)
		{
			if(str[i]>='a' && str[i]<='z')
				printf("%c",c[ccounter++]);
			else
				printf("%c",n[ncounter++]);
		}
		printf("\n");
	}
	return 0;
}
