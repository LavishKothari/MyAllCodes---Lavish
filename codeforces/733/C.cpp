#include <bits/stdc++.h>
using namespace std;

bool isOkay(vector<int>&arr,vector<int>::iterator it1,vector<int>::iterator it2)
{
	if(it2==it1)
		return true;

	int x=*it1;
	int counter=0;
	for(vector<int>::iterator i=it1;i<=it2;i++)
		if(*i == x)
			counter++;
	if(counter-1!=(it2-it1))
	{
		while(it2!=it1)
		{
			int i;
			int count=0;
			for(i=it2-arr.begin();i>it1-arr.begin();i--)
			{
				count++;
				if(arr[i]<arr[i-1])
					continue;
				else break;
			}
			for(int j=0;j<count;j++)
				cout<<i<<" R"<<endl; 
			it2=i;
		}
	}
	else return false;
}
void printAnswer(vector<int>&arr,vector<int>&sumarr)
{
	int j=0;
	int currentsum=0;
	int prev=0;
	for(int i=0;i<arr.size();i++)
	{
		cout<<i<<endl;
		currentsum+=arr[i];
		if(currentsum==sumarr[j] && isOkay(arr,arr.begin()+prev,arr.begin()+i))
		{
			cout<<"hello lavish kothari\n";
			j++;
			arr[i]=currentsum;
			currentsum=0;
			//i--;
			prev=i+1;
		}
		else if(currentsum >= sumarr[j])
		{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";	
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int m;
	scanf("%d",&m);
	vector<int>sumarr(m);
	for(int i=0;i<m;i++)
		scanf("%d",&sumarr[i]);
	printAnswer(arr,sumarr);
	return 0;
}
