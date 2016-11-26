#include <iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;


vector <string> v;

void findSubstrings(string &str, int n) {
	
	int i, j;
	string temp;
	for(i=0; i<n; i++) {
		for(j=i; j<n; j++) {
			temp = str.substr(i,j-i+1);
			v.push_back(temp);
		}
	}
	//cout<<"v.size = "<<v.size()<<endl;
}
int longestpref(string &a, string &b) {
	
	int count = 0;
	int i;
	for(i=0; i<a.size() && i<b.size(); i++) {
		if(a[i] == b[i])
			count++;
		else
			return count;
	}
	return count;
}


int findAnswer(int n) {
	
	long long int ans=0;
	int i, j;
	for(i=0; i<v.size(); i++) {
		for(j=0; j<v.size(); j++) {
			ans = (ans + longestpref(v[i], v[j])) % MOD;
		}
	}
	return ans;
	
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		string a;
		scanf("%d",&n);
		cin >> a;
		findSubstrings(a, n);
		
		cout<<findAnswer(n)<<endl;
		v.erase(v.begin(),v.end());
	}

    return 0;
}
