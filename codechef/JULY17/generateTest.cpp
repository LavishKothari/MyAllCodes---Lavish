#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("test.txt","w",stdout);
	srand(time(NULL));
	int t=10;
	cout<<t<<endl;
	while(t--)
	{
		int n=rand()%10;
		int d=rand()%10+20;

		cout<<n<<" "<<d<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<rand()%d<<" "<<rand()%d<<" "<<rand()%10<<endl;
		}
	}
	return 0;
}
