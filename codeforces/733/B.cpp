#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int lsum,rsum;
	lsum=rsum=0;
	vector<int>L(n);
	vector<int>R(n);

	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&L[i],&R[i]);
		lsum+=L[i];
		rsum+=R[i];
	}

	int goodIndex=0;
	int answer=0;
	int LminusR=abs(lsum-rsum);
	for(int i=0;i<n;i++)
	{
		int newlsum=lsum-L[i]+R[i];
		int newrsum=rsum-R[i]+L[i];
		int newLminusR=abs(newlsum - newrsum);
		if(newLminusR>LminusR && answer<newLminusR)
		{	
			answer=newLminusR;
			goodIndex=i;
		}
	}
	if(answer>LminusR)
		cout<<goodIndex+1<<endl;
	else cout<<"0\n";

	return 0;
}
