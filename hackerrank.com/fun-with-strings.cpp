#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
void getZarr(string str, int *Z)
{
    int n = str.length();
    int L, R, k;
 
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            k = i-L;
 
            if (Z[k] < R-i+1)
                 Z[i] = Z[k];
 		   else
            {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
    Z[0]=n;
}
int fSubstrings(int from,int len,int n)
{
	if(from>=n || from+len-1>=n)
		return 0;
	return n-(from+len-1);
}
ll findAnswer(int*z,int n)
{
	ll answer=(n*(n+1))/2;
	for(int i=1;i<n;i++)
	{
		if(z[i]==0)
			continue;
		answer+=fSubstrings(i,z[i],n)*z[i];
		if(z[i]>0)
			answer+=((z[i]-1)*z[i])/2;
	}
	return answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string text;
		int n;
		cin>>n;
		cin>>text;
		ll answer=0;
		for(int j=0;j<n;j++)
		{
			int*z;
			z=new int[text.size()];
			getZarr(text,z);
			for(int i=0;i<text.size();i++)
				cout<<z[i]<<" ";
			cout<<endl;
			
			answer=answer+findAnswer(z,text.size());
		
			text.erase(text.begin());
			delete z;
		}
		printf("%lld\n",answer);
	}
    return 0;
}
