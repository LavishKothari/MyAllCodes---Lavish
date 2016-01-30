#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int answer=abs(n-m)-k;
		if(answer<0)
			printf("0\n");
		else printf("%d\n",answer);
	}
	return 0;
}
