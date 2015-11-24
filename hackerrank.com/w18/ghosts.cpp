#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int a,b,c,d,A,B,C,D,counter=0;
	// town street house appartment
	scanf("%d%d%d%d",&A,&B,&C,&D);
	for(a=1;a<=A;a++)
	{
		for(b=1;b<=B;b++)
		{
			if(abs(a-b)%3!=0)
				continue;
			for(c=1;c<=C;c++)
			{
				if((b+c)%5!=0)
					continue;
				for(d=1;d<=D;d++)
				{
					//printf("hello lavish kothari\n");
					if(abs(a-b)%3==0 && (b+c)%5==0 && (a*c)%4==0 && gcd(a,d)==1)
						counter++;				
				}
			}
		}
	}
	printf("%d\n",counter);
	return 0;
}
