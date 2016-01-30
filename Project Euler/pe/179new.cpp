#include<stdio.h>
#include<vector>

#define MAX 10000000
using namespace std;

vector<int>divisors(MAX+1);
void populateDivisors()
{
	for(int i=0;i<=MAX;i++)
		divisors[i]=1;
	for(int i=2;i<=MAX;i++)
		for(int j=i;j<=MAX;j+=i)
			divisors[j]++;
}
int main()
{
	populateDivisors();
	printf("populating done\n");
	int answer=0;
	for(int j=2;j<MAX;j++)
	{
		if(divisors[j]==divisors[j+1])
			answer++;
	}
	printf("%d\n",answer);
	return 0;
}
