#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	char v[2][1001];
	while(t--) {
		int n,m;
		scanf("%d%d",&n,&m);
		int flag=0;
		bool answer=true;
		for(int i=0;i<n;++i,flag=!flag) {
			scanf(" %s",v[flag]);
			for(int j=0;answer && j<m;++j)
				if((i==0 && ((j>0 && v[flag][j]=='W' && v[flag][j-1]=='A') || (v[flag][j]=='W' && (j==0 || j==m-1)) || (j>0 && v[flag][j]=='A' && v[flag][j-1]=='W'))) || (i!=0 && ((v[flag][j]=='W' && (j==0 || j==m-1)) || (v[!flag][j]=='B' && v[flag][j]!='B') || (v[!flag][j]=='W' && v[flag][j]=='A') || (j>0 && v[flag][j]=='W' && v[flag][j-1]=='A') || (j>0 && v[flag][j]=='A' && v[flag][j-1]=='W'))))
					answer=false;
		}
		if(answer)
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
// :P small enough haan ??
