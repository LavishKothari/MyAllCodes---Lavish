#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 2000010 
int *z,l;
void z_algorithm(char *s,char *p) // returns z array.
{
	char *str;
	int i,L,R,k;
	int lens,lenp;
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
	
	//printf("The resultant string is : %s\n",str);
	
	z[0]=l;
	L=R=0;
	for(i=1;i<l;i++)
	{
		//printf("%d ",i);
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
	printf("\n\n");
	for(i=0;i<l;i++)
		printf("%d ",z[i]);
	printf("\n\n");
	*/
}
int main()
{
	char s[MAX],p[MAX],answer[MAX],answercounter[MAX];
	int lenp,counter,ic,i,flag;
	scanf("%s%s",s,p);
	z_algorithm(s,p);	
	//printf("Z algorithm finished\n");
	lenp=strlen(p);
	flag=0;
	for(i=2;i<l;)
	{
		//printf("i = %d\n",i);
		if(z[i]!=lenp)
		{
			i++;
			continue;
		}
		ic=i;
		counter=0;
		while(ic<l && z[ic]==lenp)
		{
			counter++;
			ic+=lenp;
		}
		//printf("%d %d\n",i-lenp,counter);
		answer[flag]=i-lenp;
		answercounter[flag]=counter;
		flag++;
		if(ic>=l)
			break;
		if(counter>=1)
			i=i+(counter-1)*lenp+1;
		else 
			i++;
	}
	if(flag==0)
		printf("-1\n");
	else 
		for(i=flag-1;i>=0;i--)
			printf("%d %d\n",answer[i],answercounter[i]);
	return 0;	
}
