#include<stdio.h>
#include<vector>
#define MOD 1000000007
using namespace std;
vector<long long int>f,g;
int main()
{
	int q,i,flag_f=0,flag_g=0;
	scanf("%d",&q);
	f.push_back(1);
	f.push_back(1);
	g.push_back(0);
	g.push_back(1);
	for(i=2;;i++)
	{
		f.push_back(((f[i-1]+f[i-2])%MOD+2*g[i-2])%MOD);
		g.push_back((f[i-1]+g[i-1])%MOD);
		if(i%100000==0)
			printf("i = %d\n",i);

		if(f[f.size()-1]==1)
			flag_f=1;
		if(g[g.size()-1]==0)
			flag_g=1;

		if(flag_f && flag_g)
			break;
	}
	printf("f = %d \ng = %d\n",f.size(),g.size());
	/*
	   while(q--)
	   {
	   scanf("%d%c",&n,&c);
	   }
	 */
	return 0;
}
