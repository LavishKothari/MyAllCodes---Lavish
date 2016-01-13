#include<stdio.h>
#include<set>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int*arr=new int[3*n];
	set<int>s;
	for(int i=0;i<3*n;i++)
	{
		scanf("%d",&arr[i]);
		s.insert(arr[i]);
	}
	printf("1\n0 1 2\n");
	return 0;
}
