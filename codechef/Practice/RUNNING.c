#include<stdio.h>
#include<stdlib.h>
int N[50001],K[50001],D[50001],n,k,z[100020],l;
int start,end,lens,lenp;
void z_algorithm(int *s,int *p) // returns z array.
{
	int *str;
	int i,L,R,k;
	l=lens+lenp+1;
	
	str=(int*)malloc(sizeof(int)*l);
	//z=(int*)malloc(sizeof(int)*l);
	
	for(i=0;i<l;i++)
	{
		if(i<lenp) str[i]=p[i];
		else if(i==lenp) str[i]=2147483647;
		else str[i]=s[i-lenp-1];
	}
	
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
	free(str);
	/*
	printf("\n\n");
	for(i=0;i<l;i++)
		printf("%d ",z[i]);
	printf("\n\n");
	*/
}

int findSubString()
{
	int i;
	for(i=0;i<k && start+i<n-1;i++)
	{
		//printf("i=%d start+i=%d\n",i,start+i);
		if(D[start+i]!=K[i])
			return 0;
	}
	if(i==k)
		return 1;
	return 0;
}
int findAnswer()
{
	int i,answer;
	for(i=1;i<n;i++)
		D[i-1]=N[i]-N[i-1];
	start=0;answer=0;
	while(1)
	{
		//printf("Hello lavish kothari %d\n",start);
		if(findSubString())
		{
			answer++;
			//printf("Substring found\n");
		}
		start++;
		if(start>=n-1)
			break;
	}
	return answer;
}
void findAnswer1()
{
	int i,answer=0;
	for(i=1;i<n;i++)
		D[i-1]=N[i]-N[i-1];
	z_algorithm(D,K);
	for(i=1;i<l;i++)
		if(z[i]==lenp)
			answer++;
	printf("%d\n",answer);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		lens=n-1;lenp=k;
		for(i=0;i<n;i++)
			scanf("%d",N+i);
		for(i=0;i<k;i++)
			scanf("%d",K+i);
		//printf("%d\n",findAnswer());
		findAnswer1();
		
	}
	return 0;
}
