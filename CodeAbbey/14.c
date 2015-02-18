#include<stdio.h>

int main()
{
	int n,num[100000],i,j;
	char ch[100000];
	scanf("%d",&n);
	scanf(" %c%d",&ch[0],&num[0]);
	i=0;
	while(ch[i]!='%')
	{
		i++;
		//ch[i]=(char)getchar();
		scanf(" %c%d",&ch[i],&num[i]);
		//printf(" %c %d\n",ch[i],num[i]);
	}
	for(j=0;j<i;j++)
	{
		if(ch[j]=='+')
			n=(n+num[j])%num[i];
		else if(ch[j]=='*')
			n=(n*num[j])%num[i];
		//printf("%d\n",n);
	}
	printf("%d",n);
	return 0;
}
