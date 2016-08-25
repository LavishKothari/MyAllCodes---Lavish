 #include<stdio.h>

int main()
{	
	int e,t,n,count[26],i;char str[4];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<26;i++)	
			count[i]=0;
		scanf("%d",&e);
		for(i=0;i<e;i++)
		{
			scanf(" %s",str);
			count[str[0]-'A']++;
			count[str[2]-'A']++;
		}
		n=0;
		for(i=0;i<26;i++)	
		{
			//printf("%d ",count[i]);
			if(count[i])
				n++;
		}
		//printf("this is a tewst %d\n",n);
		if(n-1==e)
			printf("0 ");
		else printf("1 ");
	}
	return 0;
}
