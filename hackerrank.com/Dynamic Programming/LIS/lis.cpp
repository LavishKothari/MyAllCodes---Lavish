#include<iterator>
#include<cstdio>
#include<set>
#include<utility>
using namespace std;
int main() 
{
    int n;
    scanf ("%d", &n);
   	int *a;
   	a=new int[n];
   	for (int i = 0; i < n; ++i)
   		scanf ("%d", &a[i]);
   	set<int>s;
   	s.clear();
   	for (int i=0;i<n;++i)
   	{
   		pair<std::set<int>::iterator,bool> p=s.insert(a[i]);
   		if(p.second==true)
   		{
	   		set<int>::iterator it=s.find(a[i]);
	   		++it;
	   		if (it != s.end())
	   			s.erase(it);
	   	}
   	}
   	printf ("%d\n",s.size());
   	return 0;
}
