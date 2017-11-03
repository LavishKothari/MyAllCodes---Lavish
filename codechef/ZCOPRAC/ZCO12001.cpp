#include<stdio.h>
#include<vector>
using namespace std;
vector<int>s;
int main()
{
	int n,t,max,i,second,counter,currentstart,finalstart,third,element,fourth;
	scanf("%d",&n);
	counter=max=finalstart=currentstart=third=element=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(t==1)
			counter++;
		else counter--;
		if(counter>max)
		{
			second=i;
			max=counter;
			finalstart=currentstart;
		}
		element++;
		if(counter==0)
		{
			if(third<element)
			{
				third=element;
				fourth=i-third+2;
			}
			element=0;
			currentstart=i+1;
		}
	}
	printf("%d %d %d %d\n",max,second+1,third,fourth);

	return 0;
}
