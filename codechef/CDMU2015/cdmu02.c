#include<stdio.h>
#include<stdlib.h>
int **arr;
int main()
{
	char str[1000001],ch;
	int q,a,b,i,j,len;
	scanf("%s%d",str,&q);
	for(len=0;str[len];len++);
	arr=(int**)malloc(sizeof(int*)*26);
	for(i=0;i<26;i++)
		arr[i]=(int*)malloc(sizeof(int)*len);
	for(i=0;i<26;i++)
		for(j=0;j<len;j++)
			arr[i][j]=0;
	for(i=0;i<len;i++)
	{
		if(i==0)
		{
			arr[str[i]-'a'][i]++;
		}
		else
		{
			for(j=0;j<26;j++)
				arr[j][i]=arr[j][i-1];
			arr[str[i]-'a'][i]++;
		}
	}
	while(q--)
	{
		scanf(" %c%d%d",&ch,&a,&b);
		if(a!=1)
		{
			printf("%d\n",arr[ch-'a'][b-1]-arr[ch-'a'][a-2]);
		}
		else
		{
			printf("%d\n",arr[ch-'a'][b-1]);
		}
	}
}
