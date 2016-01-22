#include<stdio.h>

int main()
{
	int countLower[26],countUpper[26],i;
	char str[1000];
	for(i=0;i<26;i++)
		countLower[i]=countUpper[i]=0;
	printf("Enter a line of text : ");
	scanf(" %s",str);
	for(i=0;str[i];i++){
		if(str[i]>='A' && str[i]<='Z')
			countUpper[str[i]-'A']++;
		if(str[i]>='a' && str[i]<='z')
			countLower[str[i]-'a']++;
	}	
	for(i=0;i<26;i++)
		printf("%c = %d\n",i+'a',countLower[i]);
	for(i=0;i<26;i++)
		printf("%c = %d\n",i+'A',countUpper[i]);
	return 0;
}
