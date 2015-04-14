#include<stdio.h>
#include<stdlib.h>
char*plainTextToCipherText(char plainText[],int n)
{
	char *cipherText;
	int i;
	cipherText=(char*)malloc(sizeof(char)*1000);
	for(i=0;plainText[i];i++)
	{
		if(plainText[i]!=' ')
			cipherText[i]=((plainText[i]-'a'+n)%26)+'a';
		else
			cipherText[i]=plainText[i];
	}
	cipherText[i]='\0';
	return cipherText;
}
char*cipherTextToPlainText(char cipherText[],int n)
{
	char *plainText,c;
	int i;
	plainText=(char*)malloc(sizeof(char)*1000);
	for(i=0;cipherText[i];i++)
	{
		if(cipherText[i]!=' ')
		{
			c=(cipherText[i]-'a'-n)%26;
			if(c<0)
				c+=26;
			c+='a';
			plainText[i]=c;
		}
		else
		{
			plainText[i]=cipherText[i];
		}
	}
	plainText[i]='\0';
	return plainText;
}
int main()
{
	int n;
	char plainText1[1000],*cipherText1,cipherText2[1000],*plainText2;

	// Encoding Cipher Text
	printf("Enter the Plain Text (in lower case): ");
	scanf(" %[^\n]s",plainText1);
	printf("Enter the number of characters to be shifted : ");
	scanf("%d",&n);
	cipherText1=plainTextToCipherText(plainText1,n);
	printf("Cipher Text is : %s\n",cipherText1);


	// Decoding Plain Text
	printf("\nEnter the Cipher Text (in lower case) : ");
	scanf(" %[^\n]s",cipherText2);
	printf("Enter the number of charaters to be shifted : ");
	scanf("%d",&n);
	plainText2=cipherTextToPlainText(cipherText2,n);
	printf("The Plain Text is : %s\n",plainText2);
	return 0;
}
