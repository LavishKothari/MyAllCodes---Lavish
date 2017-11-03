#include<bits/stdc++.h>
using namespace std;
void solve(vector<bool>&v,int k) {
	for(int i=0;i<v.size();i++)	{
		if(!v[i] && k==0) {	
			printf("%d\n",i);
			return ;
		}
		if(!v[i]) {
			k--;
		}
	}
}
int main() {
	int t,n,k,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		vector<bool>v(300010,false);
		for(int i=0;i<n;i++) {
			scanf("%d",&x);
			v[x]=true;
		}
		solve(v,k);
	}
	return 0;
}
