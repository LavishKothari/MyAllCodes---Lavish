#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	string s,ns;
	cin>>s;
	int a,b; // a rows and b cols
	b=a=(int)sqrt(s.size());
	if(b*a<s.size())
		b++;
	if(b*a<s.size())
		a++;
	string *f=new string[a];
	int counter=0;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			f[i]=f[i]+s[counter++];
			if(counter==s.size())
				goto lavish;			
		}
	}
lavish:;
	   for(int i=0;i<b;i++)
	   {
		   for(int j=0;j<a;j++)
			   if(j!=a-1 || (j==a-1 && i<s.size()%b) || (j==a-1 && s.size()%b==0))
				   cout<<f[j][i];
		   cout<<" ";
	   }
	   return 0;
}
