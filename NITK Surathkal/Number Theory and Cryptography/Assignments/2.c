#include<math.h>
#include<stdio.h>
#include<string.h>
long long int convert10(char *str,int inputBase)
{
	int result[100],i,j,number[100],len;
	long long int decimal=0,cdecimal;
	len=strlen(str);
	for(i=0;str[i];i++)
		if(str[i]>='0' && str[i]<='9')
			number[i]=str[i]-'0';
		else if(str[i]>='A' && str[i]<='Z')
			number[i]=str[i]-'A'+10;
		else if(str[i]>='a' && str[i]<='z')
			number[i]=str[i]-'a'+10;
			
	for(i=0;i<len;i++)
		decimal=decimal*inputBase+number[i];
	return decimal;
}
long long int convert(char *str,int inputBase,int outputBase)
{
	int result[100],i,j,number[100],len;
	long long int decimal=0,cdecimal;
	len=strlen(str);
	for(i=0;str[i];i++)
		if(str[i]>='0' && str[i]<='9')
			number[i]=str[i]-'0';
		else if(str[i]>='A' && str[i]<='Z')
			number[i]=str[i]-'A'+10;
		else if(str[i]>='a' && str[i]<='z')
			number[i]=str[i]-'a'+10;
			
	for(i=0;i<len;i++)
		decimal=decimal*inputBase+number[i];
	cdecimal=decimal;
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
	return cdecimal;
}
void printEquivalentBinary(long long int decimal)
{
	int i,j,outputBase=2;
	int result[100];
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
int convertToDecimal(char *str)// this function will return the number of bit operations in converting the binary number to decimal
{
	int i,bitoperations=0;
	long long int result=1;
	for(i=1;str[i];i++)
	{
		if(str[i]=='0')
		{
			result=(result<<1);
			bitoperations++;
		}
		else
		{
			result=(result<<1)+1;
			bitoperations+=2;
		}
	}
	printf("The Equivalent decimal number is : %lld\n",result);
	return bitoperations;
}
int primeFactors(long long int num)
{
	int i,bitoperations=0;
	printf("The prime factors of the number is : ");
	for(i=2;num!=1;i++)
	{
		while(num%i==0)
		{
			bitoperations=bitoperations+(int)(log10(num)/log10(2))*(int)(log10(num)/log10(2));
			num/=i;
			printf("%d,",i);
		}
	}
	printf("\n");
	return bitoperations;
}

int main()
{
	int choice;
	int num1,num2;
	long long int num;
	char s1[100],s2[100];
	while(1)
	{
		printf("\n____________________________________________\n\nYou have following options : \n");
		printf("0. To EXIT\n");
		printf("1. Addition of two k bit numbers \n");
		printf("2. Multiplication of two k bit numbers\n");
		printf("3. Conversion of k bit binary number to decimal \n");
		printf("4. Finding the number of bit operations for finding the prime factors of a number\n");
		printf("Enter your choice : ");
		scanf(" %d",&choice);
		switch(choice)
		{
			case 0:
				printf("Exiting...\n");
				return 0;
			case 1:
			{
				printf("Enter the first number : ");
				scanf(" %s",s1);
		
				printf("Enter the second number : ");
				scanf(" %s",s2);	
	
				printf("The number of bit operations  : %d\n",strlen(s1));
				num1=convert10(s1,2);
				num2=convert10(s2,2);
				printf("The result of addition is : ");
				printEquivalentBinary(num1+num2);	
				break;	
			}		
			case 2:
			{
				printf("Enter the first number : ");
				scanf(" %s",s1);
		
				printf("Enter the second number : ");
				scanf(" %s",s2);	
	
				printf("The number of bit operations  : %d\n",strlen(s1)*strlen(s2));
				num1=convert10(s1,2);
				num2=convert10(s2,2);
				printf("The result of addition is : ");
				printEquivalentBinary(num1*num2);	
				break;	
			}
			case 3:
			{
				printf("Enter the binary number : ");
				scanf(" %s",s1);
				
				printf("The number of bit operations is : %d\n",convertToDecimal(s1));
				break;
			}
			case 4:
			{
				printf("Enter the number for which you need to find the prime factors : ");
				scanf("%lld",&num);
				printf("The number of bit operations is : %d\n",primeFactors(num));
				break;
			}
			default :
				printf("Wrong choice entered...\n Enter the choice again...\n\n");
		}
	}
	return 0;
}
