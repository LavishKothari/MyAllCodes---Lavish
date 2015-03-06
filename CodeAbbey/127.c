#include<string.h>
#include<stdio.h>
int isAnagram(char a[],char b[])
{
	int flag1[26],flag2[26],i;
	for(i=0;i<26;i++)
		flag1[i]=flag2[i]=0;
	for(i=0;a[i];i++)
		flag1[a[i]-'a']++;
	for(i=0;b[i];i++)
		flag2[b[i]-'a']++;
	for(i=0;i<26;i++)
		if(flag1[i]!=flag2[i])
			return 0;
	return 1;
}
int countNumberOfAnagrams(char str[])
{
	char currentStr[50];
	int len,currentLen,counter=0;
	FILE *f;
	f=fopen("words.txt","r");
	if(f)
	{
		len=strlen(str);
		while(1)
		{
			if(fscanf(f," %s",currentStr)==-1)
				break;
			else if(isAnagram(currentStr,str))
				counter++;
		}
	}
	else printf("There was some error in opening the file..\n");
	return counter;
}
int main()
{
	int t;
	char str[50];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		printf("%d ",countNumberOfAnagrams(str)-1);
	}
	return 0;
}
