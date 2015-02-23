#include<stdio.h>
#include<string.h>
int main()
{
	char fullstr[10000],str[10000][4],temp[4],end[]={'e','n','d','\0'};
	int i,len,j;
	len=i=0;
	scanf("%[^\n]s",fullstr);
	while(1)
	{
		if(!fullstr[i])
			break;
		str[len][0]=fullstr[i];
		str[len][1]=fullstr[i+1];
		str[len][2]=fullstr[i+2];
		len++;
		i+=4;
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	for(i=1;i<len;i++)
	{
		if(strcmp(str[i],str[i-1])==0)
		{
			printf("%s ",str[i]);
			i++;
			while(strcmp(str[i],str[i-1])==0)
				i++;
		}
	}
	return 0;
}
