/*
	Name - Lavish Kothari
		Computer Science and Engineering - Information Security
		NITK
		
	Construct a hash function which takes university roll number and generates 2 digit
	integer out of it. Use this hash function to map a class of 54 students on to an integer.
	Out of 54 students, 27 are from Mtech CSE and other 27 are from Mtech CSE-IS
	Try developing the inverse hash function.
*/
#include<stdlib.h>
#include<stdio.h>
int isValidRollNumber(char *str)
{
	/*
		Roll number is valid if they begin with CS or IS
		and the numberical digit followed by them is in range [1,27] (including 1 and 27)
	*/
	if(str[0]=='C' && str[1]=='S' && (str[2]-'0')*10+str[3]-'0'<=27) return 1;
	if(str[0]=='I' && str[1]=='S' && (str[2]-'0')*10+str[3]-'0'<=27) return 1;
	return 0;
}
int convertToBase(int number,int inBase,int outBase) // inBase and outBase should be less than or equal to 10
{
	int len=0,p=1,arr[100],i,j,cnum;
	cnum=number;
	while(cnum)
	{
		len++;
		cnum/=10;
	}
	cnum=number;
	for(i=len-1;i>=0;cnum/=10,i--)
		arr[i]=cnum%10;
	number=arr[0];
	for(i=1;i<len;i++)
		number=number*inBase+arr[i];
	// now number is in base 10
	i=0;
	while(number)
	{
		arr[i++]=number%outBase;
		number/=outBase;
	}
	number=0;
	for(j=i-1;j>=0;j--)
		number=number*10+arr[j];
	return number;
}
int hash1(char *str) // example of perfect hashing.
{
	int number,temp=0;
	if(isValidRollNumber(str))
	{
		if(str[0]=='C') number=10;
		else number=50;
		number+=(str[2]-'0')*10+(str[3]-'0');
		return convertToBase(number,10,9);
	}
	else printf("The roll number you entered is not valid...\n");
	return -1;
}
char * hash1Inverse(int number)
{
	char *str;
	str=(char*)malloc(sizeof(char)*5);
	number=convertToBase(number,9,10);
	if(number>=50)
	{
		number-=50;
		str[0]='I';
		str[1]='S';
		str[2]=number/10+'0';
		str[3]=number%10+'0';
		str[4]='\0';
		return str;
	}
	else 
	{	
		number-=10;
		str[0]='C';
		str[1]='S';
		str[2]=number/10+'0';
		str[3]=number%10+'0';
		str[4]='\0';
		return str;
	}
}
int hash2(char *str) // example of perfect hashing.
{
	int number,temp=0;
	if(isValidRollNumber(str))
	{
		if(str[0]=='C') number=9900;
		else number=8800;
		number+=(str[2]-'0')*10+(str[3]-'0');
		number*=number;
		return (number/1000)%100;
	}
	else printf("The roll number you entered is not valid...\n");
	return -1;
}
void printHash2Inverse(int number)
{
	int i;
	char str[5];
	printf("the following are the roll numbers that give the same hash value : ");
	// for computer Science
	str[0]='C';
	str[1]='S';
	str[4]='\0';
	for(i=1;i<=27;i++)
	{
		str[3]=i%10+'0';
		str[2]=i/10+'0';
		//printf("%s\n",str);
		if(hash2(str)==number)
			printf("%s,",str);
	}
	str[0]='I';
	for(i=1;i<=27;i++)
	{
		str[3]=i%10+'0';
		str[2]=i/10+'0';
		if(hash2(str)==number)
			printf("%s,",str);
	}
	printf("\n");
}
int main()
{
	int number;
	char str[5];
	printf("\nEnter your roll number (Ex. 'IS12') : ");
	scanf("%s",str);
	printf("\nThese are the results of Hash Function 1 :\n");
	number=hash1(str);
	if(number!=-1)
	{
		printf("The number obtained by hash function is : %d\n",number);
		printf("Giving the above number in inverse of hash function yields : %s\n",hash1Inverse(number));
	}
	
	printf("\nThese are the results of Hash Function 2 :\n");
	number=hash2(str);
	if(number!=-1)
	{
		printf("The number obtained by hash function is : %d\n",number);
		printHash2Inverse(number);
	}
	printf("\n");	
	return 0;
}
