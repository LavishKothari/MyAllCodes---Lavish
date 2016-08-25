#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int* z_algorithm(char *s,char *p) // returns z array.
{
	char *str;
	int *z,i,L,R,k;
	int lens,lenp,l;
	lens=strlen(s);
	lenp=strlen(p);
	l=lens+lenp+1;
	
	str=(char*)malloc(sizeof(char)*(l+1));
	z=(int*)malloc(sizeof(int)*(l+1));
	
	for(i=0;i<l;i++)
	{
		if(i<lenp) str[i]=p[i];
		else if(i==lenp) str[i]='$';
		else str[i]=s[i-lenp-1];
	}
	str[i]='\0';
	
	printf("The resultant string is : %s\n",str);
	
	z[0]=l;
	L=R=0;
	for(i=1;i<l;i++)
	{
		printf("%d ",i);
		if(i>R)
		{
			L=R=i;
			while (R<l && str[R-L] == str[R])
                R++;
            z[i] = R-L;
            R--;
		}
		else
		{
			k=i-L;
			if (z[k] < R-i+1)
            	z[i] = z[k];
 
            else
            {
            	L = i;
                while (R<l && str[R-L] == str[R])
                    R++;
                z[i] = R-L;
                R--;
            }
		}
	}
	/*
	printf("\n");
	for(i=0;i<l;i++)
		printf("%d ",z[i]);
	printf("\n");
	*/
}
int main()
{
	char s[100001],p[100001];
	int*z;
	scanf("%s%s",s,p);
	z=z_algorithm(s,p);	
	
		
		
}
