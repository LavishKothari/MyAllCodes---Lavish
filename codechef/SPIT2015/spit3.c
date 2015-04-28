#include<stdio.h>
int main()
{
	int i,containsUpper=0,containsDigit=0,containsLower=0;
	char str[101];
	scanf("%s",str);
	for(i=0;str[i];i++)
	{
		if(str[i]>='a' && str[i]<='z')
			containsLower=1;
		if(str[i]>='A' && str[i]<='Z')
			containsUpper=1;
		if(str[i]>='0' && str[i]<='9')
			containsDigit=1;
	}
	if(i>=5 && containsUpper==1 && containsLower==1 && containsDigit==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
