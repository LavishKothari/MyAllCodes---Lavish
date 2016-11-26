#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	unsigned int n;
    	scanf("%u",&n);
    	vector<unsigned int>arr(2*n+2);
    	unsigned int xxory=0;
    	for(int i=0;i<2*n+2;i++)
    	{
    	    scanf("%u",&arr[i]);
    	    xxory=xxory^arr[i];
    	}
    	unsigned int x=0,y=0;
        unsigned int pivot=xxory & ~(xxory-1);
        for(int i=0;i<2*n+2;i++)
        {
            if(arr[i]&pivot)
                x=x^arr[i];
            else y=y^arr[i];
        }
        cout<<(int)min(x,y)<<" "<<(int)max(x,y)<<endl;
	}
	return 0;
}