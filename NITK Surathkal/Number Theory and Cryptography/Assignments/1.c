#include<stdio.h>

void convert(int*number,int len,int inputBase,int outputBase)
{
	int result[100],i,j;
	long long int decimal=0;
	for(i=0;i<len;i++)
		decimal=decimal*inputBase+number[i];
	for(i=0;decimal;i++)
	{
		result[i]=decimal%outputBase;
		decimal/=outputBase;
	}
	for(j=i-1;j>=0;j--)
		if(result[j]>=0 && result[j]<=9)
			printf("%d",result[j]);
		else
			printf("%c",result[j]-10+'A');
	printf("\n");
}

int main()
{
	char str[100];
	int inputBase,outputBase,number[100],i;
	printf("Enter the input base : ");
	scanf("%d",&inputBase);
	printf("Enter the output base : ");
	scanf("%d",&outputBase);
	
	printf("Enter the number : ");
	scanf("%s",str);
	
	for(i=0;str[i];i++)
		if(str[i]>='0' && str[i]<='9')
			number[i]=str[i]-'0';
		else if(str[i]>='A' && str[i]<='Z')
			number[i]=str[i]-'A'+10;
		else if(str[i]>='a' && str[i]<='z')
			number[i]=str[i]-'a'+10;
	convert(number,i,inputBase,outputBase);
	return 0;
}
