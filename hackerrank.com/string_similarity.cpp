#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<limits>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int stringS(char a[],char b[])
{
	int i;
	for(i=0;b[i] && a[i]==b[i];i++);
	return i;
}
long long int stringSimilarity(char a[]) 
{
	long long int answer=0;
	answer+=strlen(a);
	for(int i=1;a[i];i++)
	{
		answer+=stringS(a,a+i);
	}
	return answer;
}
int main() 
{
	int t, i;
	scanf("%d",&t);
	char a[100001];
	for (i=0;i<t;i++) 
	{
		scanf("%s",a);
		long long int res=stringSimilarity(a);
		printf("%lld\n",res);  
	}
	return 0;
}
