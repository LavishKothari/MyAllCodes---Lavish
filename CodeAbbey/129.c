#include<stdio.h>
typedef long long int ll;
#define N 36
ll nck[N+1][N+1]={0};
char A[36];
ll n,k,in;
void populateNCK()
{
	int i,j;
	for(i=0;i<=N;i++)
		for(j=0;j<=i;j++)
			if(j==0 || i==j)
				nck[i][j]=1;
			else 
				nck[i][j]=nck[i-1][j-1]+nck[i-1][j];
}
void populateA()
{
	int i,counter=0;
	for(i=0;i<10;i++)
		A[counter++]=i+'0';
	for(i=0;i<26;i++)
		A[counter++]=i+'A';
}
void print(ll start,ll end,ll k,ll index)
{
	ll sum=0;
	if(start>end)
		return;
	if(nck[n-start-1][k-1]<=index)
		print(start+1,end,k,index-nck[n-start-1][k-1]);
	else 
	{
		printf("%c",A[start]);
		print(start+1,end,k-1,index);	
	}
}
int main()
{
	int t;
	
	populateA();
	populateNCK();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&in);
		print(0,n-1,k,in);
		printf(" ");
	}
	return 0;
}
