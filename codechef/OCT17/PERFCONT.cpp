#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&v,int p) {
	int c=0,h=0;
	for(int i=0;i<v.size();i++) {
		if(v[i] <= p/10)
			h++;
		else if(v[i] >= p/2)
			c++;
		if(c==2 || h==3)
			return false;
	}
	if(c==1 && h==2)
		return true;
	else return false;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,p;
		scanf("%d%d",&n,&p);
		vector<int>v(n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		if(isPossible(v,p))
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
