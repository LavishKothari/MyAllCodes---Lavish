#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MOD 1000000007
typedef long long int ll;
int*fillFlag(char *str)
{
	int i;
	int *flag;
	flag=(int*)malloc(sizeof(int)*26);
	for(i=0;i<26;i++) flag[i]=0;
	for(i=0;str[i];i++)
	{
		flag[str[i]-'a']++;
	}
	return flag;
}
ll factorial(ll n)
{
	ll i,pro=1;
	for(i=1;i<=n;i++)
		pro=(pro*i)%MOD;
	return pro;
}
ll power(ll a,ll b)
{
	if(b==0) return 1;
	if(b==1) return a;
	ll t;
	t=power(a,b/2);
	if(b&1) return ((t*t)%MOD*a)%MOD;
	else return (t*t)%MOD;
}
ll modularInverse(ll a)
{
	return power(a,MOD-2);
}
ll c3(ll n)
{
	if(n<3)
		return 0;
	return ((((n*(n-1))%MOD*(n-2))%MOD)%MOD*modularInverse(6))%MOD;
}
ll c2(ll n)
{
	if(n<2)
		return 0;
	return (((n*(n-1))%MOD)*modularInverse(2))%MOD;
}
ll c4(ll n)
{
	if(n<4)
		return 0;
	return ((((n*(n-1))%MOD*(n-2))%MOD*(n-3))%MOD*modularInverse(24))%MOD;
}
ll findAnswer(char *str)
{
	int count=0,i;
	ll f,answer;
	int*flag;
	flag=fillFlag(str);
	
	f=answer=factorial(strlen(str));
	//printf("Factorial = %lld\n",answer);
	for(i=0;i<26;i++)
	{
		if(flag[i]!=0)
		{
			count++;
			if(flag[i]!=1)
			{
				answer=(answer*modularInverse(factorial(flag[i])))%MOD;
				//printf("hello lavish kothari %lld\n",answer);
			}
		}
	}
	//printf("tt  =  %lld\n",answer);
	if(count==1)
		return 0;
	if(count==2)
		return 0;
	if(count==3)
		return 0;
	answer=(answer*(1+((2*c3(count))%MOD+c2(count))%MOD+(3*c4(count))%MOD)%MOD)%MOD;
	if((f*f-answer)%MOD >= 0)
		return (f*f-answer)%MOD;
	else return (f*f-answer)%MOD+MOD;
}
int main()
{
	char str[100001];
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf(" %s",str);
		printf("%lld\n",findAnswer(str));
	}
	return 0;
}
