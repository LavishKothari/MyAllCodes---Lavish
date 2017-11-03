#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
void fun(ll &maxValue,ll a,ll b,ll c)
{
	if((a+b+c)%2!=0 && a+b+c>maxValue)
		maxValue=a+b+c;
	if((a+b+c)%2==0 && a+b+c-1>maxValue)
		maxValue=a+b+c-1;

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,c,d,e,f,g,h,i;
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
		ll maxValue=0;
		fun(maxValue,a,b,c);
		fun(maxValue,d,e,f);
		fun(maxValue,g,h,i);
		fun(maxValue,a,d,g);
		fun(maxValue,b,e,h);
		fun(maxValue,c,f,i);
		cout<<maxValue<<endl;
	}
	return 0;
}
