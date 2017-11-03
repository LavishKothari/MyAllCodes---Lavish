#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int randbet(int a,int b) // between a to b-1
{
	return rand()%(b-a+1) + a;
}
void solve(int n) {
	vector<unsigned int>a(n,1);
	unsigned int rem = 4294967295-n;
	a[1]=randbet(1,49999);
	a[2]=randbet(50000,100000);
	rem-=a[1];
	rem-=a[2];

	for(int i=0;i<n;i++) {
		if(rem!=0 && i!=1 && i!=2){
			int r = randbet(10000,min(rem,(unsigned int)99999));
			if(rem<99999)
				r=rem;
			rem = rem - r;
			a[i] += r;
		}
	}
	a[0]+=rem;

	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main() {
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}
