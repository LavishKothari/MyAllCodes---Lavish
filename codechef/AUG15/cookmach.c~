#include<stdio.h>

#include<math.h>
int f,g;
int l(int n)
{
	return (int)(log2(n));
}
void findfg(int n)
{
	int i,j;
	unsigned int temp=((unsigned int)1<<31);
	for(i=0;i<32;i++)
	{
		if((n&temp)!=0)
		{
			g=i;
			temp=(temp>>1);
			break;
		}
		temp=(temp>>1);
	}
	//printf("i = %d\n",i);
	for(f=j=i+1;j<32;j++)
	{
		if((n&temp)!=0)
		{
			f=j;
			return;
		}
		temp=(temp>>1);
	}
	f=32;
}
int main()
{
	unsigned int t,a,b,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		k=l(b);
		findfg(a);
		//printf("f,g,k = %d %d %d\n",f,g,k);
		printf("%d\n",31-f+1+abs(f-g-1-k));
	}
	return 0;
}
