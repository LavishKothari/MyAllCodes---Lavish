#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sol(int a,int b,int c,int d,char x[],char y[]){
	a%=12;c%=12;
	if(x[0]=='A' && y[0]=='P')
		return 1;
	else if(x[0]=='P' && y[0]=='A')
		return 2;

	if(a<c)
		return 1;
	else if(c<a)
		return 2;
	if(b<d)
		return 1;
	return 2;
}
int main() {
	int q;
	cin>>q;
	while( q--){
		char x[10],y[10];
		int a,b,c,d;
		scanf("%d:%d%s %d:%d%s",&a,&b,x,&c,&d,y);
		if(sol(a,b,c,d,x,y)==1)
			cout<<"First\n";
		else cout<<"Second\n";
	}
	return 0;
}
