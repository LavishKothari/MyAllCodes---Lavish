#include<bits/stdc++.h>

using namespace std;
int sol(int a)
{
	int aa=0;
	if(a<=10)
		aa=a*10;
	else if(a>10)
		aa=100;
	return aa;
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",sol(a)+sol(b)+sol(c));
	return 0;
}
