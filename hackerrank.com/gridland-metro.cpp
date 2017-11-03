
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct track {
	int r;
	int c1;
	int c2;
};

bool cmp(track lhs, track rhs) { return lhs.r < rhs.r; }


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	long long int n,m,k;
	cin >> n >> m >> k;
	if(k==0){
		cout<<n*m<<endl;
		return 0;
	}
	track t[1001];
	for(int i=0; i<k; i++) {
		int r, c1, c2;
		cin >> r >> c1 >> c2;
		t[i].r = r;
		t[i].c1 = c1;
		t[i].c2 = c2;
	}

	sort(t, t+k, cmp);


	long long int ans = 0, row = t[0].r, start = t[0].c1, end = t[0].c2;
	for(int i=1; i<k; i++) 
	{
		if(t[i].r == row) {
			if(start > t[i].c1)
				start = t[i].c1;
			if(end < t[i].c2)
				end = t[i].c2;
		}




		else {
			ans = ans + (end-start+1);
			// cout << "******* end  " << end << " " << start << " " << ans << endl;
			row = t[i].r;
			start = t[i].c1;
			end = t[i].c2;
		}
	}
	ans = ans + (end-start+1);
	//  cout << "******* end  " << end << " " << start << " " << ans << endl;

	cout << n*m - ans << endl;


	return 0;
}

/*

   4 4 5
   2 2 3
   3 1 4
   4 4 4
   1 1 2
   1 3 3

 */
