#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
ll gcdExcept(vector<ll>&arr,int index){
	ll g;
	if(index!=0)
		g=arr[0];
	else 
		g=arr[1];
	for(int i=0;i<arr.size();i++)
		if(i!=index)
			g=gcd(g,arr[i]);
	return g;
}
ll findAnswer(vector<ll>&arr){
	int n=arr.size();

	ll full=gcdExcept(arr,-1);
	for(int i=0;i<n;i++)
	{
		ll some = gcdExcept(arr,i);
		if(some!=full)
		{
			return some;
		}
	}
	return 1;
}
int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int a_i = 0; a_i < n; a_i++){
		cin >> a[a_i];
	}
	cout<<findAnswer(a)<<endl;
	return 0;
}
