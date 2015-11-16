#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAX 1000
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
long long int modularInverse(long long int a,long long int b)
{
	/*
		this function return x such that
			a*x = 1 (mod b)
	*/
	long long int temp,q,remainder,quotient,px,py,ca,cb,x,y;
	py=x=0;
	ca=a;
	cb=b;
	px=y=1;
	while(b!=0)
	{
		quotient=a/b;
		remainder=a%b;
		a=b;
		b=remainder;
		if(remainder==0)
			break;
		
		temp=x;
		x=px-x*quotient;
		px=temp;
		
		temp=y;
		y=py-y*quotient;
		py=temp;
		//printf("%lld = %lld * %lld + %lld * %lld\n",remainder,x,ca,y,cb);
	}
	if(x>=0)
		return x;
	else 
		while(x<0)
			x+=cb;
	return x;
}
char*encipher(char*plain,int a,int b)
{
	int i;
	char *cipher;
	cipher=(char*)malloc(sizeof(char)*MAX);
	for(i=0;plain[i];i++)
		cipher[i]=(((plain[i]-'a')*a+b)%26)+'a';
	cipher[i]='\0';
	return cipher;	
}
void cryptosystem()
{
	int a,b;
	long long int adash,bdash;
	char plain[MAX],cipher[1000];
	printf("\nFor the equation \"C = aP + b (mod 26) \" Enter the value of a and b\n");
	printf("Enter the value of a such that gcd(a,26)>1\n");
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	if(gcd(a,26)!=1)
	{
		printf("GCD(%d,26)!=1 \nExiting...\n",a);
		return;
	}
	printf("Enter the text to be enciphered (in small letters) : ");
	scanf("%s",plain);
	printf("The Cipher Text is : %s\n\n",encipher(plain,a,b));
	
	printf("\nFor the equation \"P = a'C + b' (mod 26) \"\n");
	adash=modularInverse(a,26);
	bdash=-adash*b;
	while(bdash<=0)
		bdash+=26;
	printf("a' = %lld\nb' = %lld\n\n",adash,bdash);	
	printf("Enter the text to be deciphered : ");
	scanf("%s",cipher);
	printf("The decrypted text is : %s\n\n",encipher(cipher,adash,bdash));
}
void cryptanalysis()
{
	FILE*f;
	int a,b,found;
	char cipher[MAX],*decipher,word[MAX];
	printf("Enter the text that you want to decipher : ");
	scanf("%s",cipher);
	printf("Searcing in Dictionary...\n");
	found=0;
	for(a=1;a<26;a++)
	{
		if(gcd(a,26)!=1)
			continue;
		for(b=0;b<26;b++)
		{
			decipher=encipher(cipher,a,b);
			/* now you need to match each of the possible deciphered text in the dictionary to get a matching word */
			f=fopen("words.txt","r");
			if(f)
			{
				while(!feof(f))
				{
					fscanf(f,"%s",word);
					if(strcmp(word,decipher)==0)
					{
						printf("Word Found...\n");
						printf("a' = %d\nb' = %d\n",a,b);
						printf("Deciphered Text = %s\n\n",word);
						found = 1;
					}
				}
			}
			else printf("There was an error in opening the dictionary.\n");
		}
	}
	if(found==0)
		printf("No such word found in dictionary\n");
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n**************************************\n");
		printf("\nYou have the following choices : \n");
		printf("1. Test Cryptosystem\n");
		printf("2. Test Cryptanalysis\n");
		printf("3. Clear Screen\n");
		printf("4. Exit\n");
		
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				cryptosystem();
				break;
			case 2:
				cryptanalysis();
				break;
			case 3:
				system("clear");
				break;
			case 4:
				return 0;
				break;
			default: printf("You entered a wrong choice...\n");
		}
	}
	return 0;
}
