#include<stdio.h>
#include<string.h>
int isAnagram(char*str,int i,int j,int k,int l)
{
	int x,y;
	int flag1[26]={0},flag2[26]={0};
	for(x=i;x<=j;x++)
		flag1[str[x]-'a']++;
	for(y=k;y<=l;y++)
		flag2[str[y]-'a']++;
	for(i=0;i<26;i++)
		if(flag1[i]!=flag2[i])
			return 0;
	return 1;
}
int  main()
{
	char str[101];
	int t,count,len,i,j,k,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		len=strlen(str);
		count=0;
		for(i=0;i<len;i++)
			for(j=i;j<len;j++)
				for(k=i;k<len;k++)
					for(l=k;l<len ;l++)
						if(i!=k && j!=l && l-k+1==j-i+1 && isAnagram(str,i,j,k,l))
						{
							count++;
							printf("%d %d %d %d\n",i,j,k,l);
						}
		printf("%d\n",count);
	}
	return 0;
}
