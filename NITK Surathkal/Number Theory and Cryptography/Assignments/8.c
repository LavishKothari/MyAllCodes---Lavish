/*
	Steps for Encryption : 
	____________________
		Take a message from the user
		divide the message in blocks of 4
		reverse each block
		treat each block as a base 26 number,
		find equivalent decimal of above number
		multiply the equivalent number by 37
		add 96 to above number
		finally convert the number to base 16.
		This is the encrypted form of the number.
		
		Also perform the reverse of this process to get back the original message.
*/

#include<stdio.h>
#include<string.h>
char gArray[1000];
int gCounter=0,pCounter=0;
int partition[1000];
long long int findEquivalentNumber(char*str,int a,int b)
{
	
	long long int sum=0,product=1;
	
	
	int i;
	for(i=a;i<=b;i++)
	{
		sum+=(str[i]-'A')*product;
		product=product*26;
	}
	return sum;
}
int getEquivalent(char ch)
{	
	if(ch>='0' && ch<='9')
		return ch-'0';
	else return ch-'A'+10;
}
long long int convert(int a,int b) // THIS FUNCTION CONVERTS PART OF ARRAY TO BASE 10 AND RETURNS EQUIVALENT NUMBER
{
	long long int sum=0;
	int i,num;
	for(i=a;i<=b;i++)
	{
		num=getEquivalent(gArray[i]);
		sum=sum*16+num;
	}
	return sum;
}

void convertTo16(long long int decimal,int outputBase)
{
	int result[100],i,j;
	// decimal her is the number to be converted to hexadecimal
	for(i=0;decimal;i++)
	{
		result[i]=decimal%outputBase;
		decimal/=outputBase;
	}
	for(j=i-1;j>=0;j--)
		if(result[j]>=0 && result[j]<=9)
		{
			gArray[gCounter++]=(char)(result[j]+'0');
			printf("%d",result[j]);
		}
		else
		{
			gArray[gCounter++]=(char)(result[j]-10+'A');
			printf("%c",result[j]-10+'A');
		}
	printf("\n");
	partition[pCounter++]=gCounter-1;
}

void convertTo16other(long long int decimal,int outputBase)
{
	int result[100],i,j;
	// decimal her is the number to be converted to hexadecimal
	for(i=0;decimal;i++)
	{
		result[i]=decimal%outputBase;
		decimal/=outputBase;
	}
	for(j=0;j<i;j++)
		if(result[j]>=0 && result[j]<=9)
		{
			printf("%c",result[j]+'A');
		}
		else
		{
			printf("%c",result[j]+'A');
		}	
	printf("\n");
}
void convertBack()
{
	long long int num;
	int i,start=0;
	start=0;
	for(i=0;i<pCounter;i++)
	{
		num=convert(start,partition[i]);
		num=num-96;
		num/=37;
		convertTo16other(num,26);
		start=partition[i]+1;
	}
}
int main()
{	
	char str[1000];
	int i,len;
	long long int num;
	printf("Enter message (in Capital Letters) : ");
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len && i+4<=len;i+=4)
	{
		num=findEquivalentNumber(str,i,i+3);
		num*=37;
		num+=96;
		convertTo16(num,16);
		gArray[gCounter]='\0';
	}
	printf("\n");
	//printf("this is the final string : %s\n",gArray);
	convertBack();
	return 0;
}
