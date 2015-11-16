/*
	Conversion of a number from one number system to other.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// this function will return a character array of the result of conversion of str to output base.
char* convert(char*str,int inputBase,int outputBase) 
{
	char *charResult;
	int result[100],i,j,k,number[100];
	long long int decimal=0;
	int len=strlen(str);
	for(i=0;str[i];i++)
		if(str[i]>='0' && str[i]<='9')
			number[i]=str[i]-'0';
		else if(str[i]>='A' && str[i]<='Z')
			number[i]=str[i]-'A'+10;
		else if(str[i]>='a' && str[i]<='z')
			number[i]=str[i]-'a'+10;
	
	for(i=0;i<len;i++)
		decimal=decimal*inputBase+number[i];
	//here decimal stores the decimal equivalent of the str
	for(i=0;decimal;i++)
	{
		result[i]=decimal%outputBase;
		decimal/=outputBase;
	}
	charResult=(char*)malloc(sizeof(char)*i);
	for(j=i-1,k=0;j>=0;j--,k++)
	{
		if(result[j]>=0 && result[j]<=9)
		{
			//printf("%d",result[j]);
			charResult[k]=result[j]+'0';
		}
		else
		{
			//printf("%c",result[j]-10+'A');
			charResult[k]=result[j]-10+'A';
		}
	}
	charResult[k]='\0';
	return charResult;
}

int main()
{
	char str[100];
	int inputBase,outputBase,i;
	printf("Enter the input base : ");
	scanf("%d",&inputBase);
	printf("Enter the output base : ");
	scanf("%d",&outputBase);
	
	printf("Enter the number : ");
	scanf("%s",str);

	printf("The result of conversion is : %s\n",convert(str,inputBase,outputBase));
	return 0;
}
