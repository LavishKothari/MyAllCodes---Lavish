// time complexity is not an issue here, Accuracy is an issue...
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void printVector(vector<ll>&x)
{
	for(int i=0;i<x.size();i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
ll getSum(vector<ll>s,int start,int end)
{
	if(start<0 || end<0)
		return 0;
	if(start<end)
	{
		if(start-1>=0)
			return s[end-1]-s[start-1];
		return s[end-1];
	}
	else if(start>end)
	{
		ll x=s[s.size()-1]-s[start-1];
		ll y=0;
		if(end-1>=0)
			y=s[end-1];
		return x+y;
	}	
	else 
	{
		if(start==0)
			return s[start];
		return s[start]-s[start-1];
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<ll>v(n),cs(n),sc(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(i==0)
				cs[i]=v[i];
			else cs[i]=cs[i-1]+v[i];
		}

		for(int i=n-1;i>=0;i--)
		{
			if(i==n-1)
				sc[i]=v[i];
			else sc[i]=sc[i+1]+v[i];
		}
		int start,end;
		cin>>start>>end;
		start--;end--;
		ll totalSum=cs[n-1];
		/******************************************************************************************************/
		// right case
		ll minimum=0;
		ll sum=0;
		for(int i=start;i<end;i++)
		{
			sum+=v[i];
			minimum=min(minimum,sum);
		}
		ll x=0,y=0;

		if(start-1>=0)
			x=cs[start-1];
		y=cs[cs.size()-1]-cs[end-1];

		ll answer1=x+y+2*minimum;
		if(minimum==0)
			answer1=min(answer1,answer1+totalSum);

		/******************************************************************************************************/
		// left case
		x=y=0;
		if(start-1>=0)
			x=cs[end-1]-cs[start-1];
		else x=cs[end-1]; 
		sum=0;
		minimum=0;
		for(int i=(start-1+n)%n;;i=(i-1+n)%n)
		{
			sum+=v[i];
			minimum=min(minimum,sum);
			if(i==end)
				break;
		}
		ll answer2=x+2*minimum;
		if(minimum==0)
			answer2=min(answer2,answer2+totalSum);
		/******************************************************************************************************/
		// right1 case
		if(start-1>=0)
			x=cs[end-1]-cs[start-1];
		else x=cs[end-1];
		sum=0;
		minimum=0;
		for(int i=end;i!=start;i=(i+1)%n)
		{
			sum+=v[i];
			minimum=min(minimum,sum);
		}
		ll answer3=minimum*2+x;
		if(minimum==0)
			answer3=min(answer3,answer3+totalSum);
		/******************************************************************************************************/
		// left1 case

		x=0;
		for(int i=(start-1+n)%n;;i=(i-1+n)%n)
		{
			x+=v[i];
			if(i==end)
				break;
		}
		sum=minimum=0;
		for(int i=(end-1+n)%n;i>=start;i=(i-1+n)%n)
		{
			sum+=v[i];
			minimum=min(sum,minimum);
			if(i==start)
				break;
		}
		ll answer4=2*minimum+x;
		if(minimum==0)
			answer4=min(answer4,totalSum+answer4);
		/******************************************************************************************************/
		// weird case :P 1 
		x=y=0;
		if(start-1>=0)
			x=cs[end-1]-cs[start-1];
		else x=cs[end-1]; 

		int index1,index2;

		sum=0;
		ll minimum1=0;
		for(int i=(start-1+n)%n;;i=(i-1+n)%n)
		{
			sum+=v[i];
			minimum1=min(minimum1,sum);
			if(minimum1==sum)
				index1=i;
			if(i==end)
				break;
		}

		sum=0;
		ll minimum2=0;
		for(int i=end;i!=start;i=(i+1)%n)
		{
			sum+=v[i];
			minimum2=min(minimum2,sum);
			if(minimum2==sum)
				index2=i;
		}
		ll answer5=x;
		if(minimum1!=0 && minimum2!=0)
		{
			if(index2>index1 || (index2<start && index1>=end))
				answer5+=2*minimum1+2*minimum2;
		}
		/******************************************************************************************************/
		// weird case :P 2 
		x=0;
		for(int i=(start-1+n)%n;;i=(i-1+n)%n)
		{
			x+=v[i];
			if(i==end)
				break;
		}

		sum=minimum1=0;
		for(int i=(end-1+n)%n;i>=start;i=(i-1+n)%n)
		{
			sum+=v[i];
			minimum1=min(sum,minimum1);
			if(minimum1==sum)
				index1=i;
			if(i==start)
				break;
		}

		minimum2=0;
		sum=0;
		for(int i=start;i<end;i++)
		{
			sum+=v[i];
			minimum2=min(minimum2,sum);
			if(minimum2==sum)
				index2=i;
		}
		ll answer6=x;
		cout<<"this is a test "<<index1<<" "<<index2<<" "<<minimum1<<" "<<minimum2<<endl;
		if(minimum1!=0 && minimum2!=0 && index1>index2)
			answer6=answer6+2*minimum1+2*minimum2;
		/******************************************************************************************************/

		cout<<"answer1 and answer2 = "<<answer1<<" "<<answer2<<" "<<answer3<<" "<<answer4<<" "<<answer5<<" "<<answer6<<endl;
		cout<<min(min(min(min(min(answer1,answer2),answer3),answer4),answer5),answer6)<<endl;
	}
	return 0;
}
