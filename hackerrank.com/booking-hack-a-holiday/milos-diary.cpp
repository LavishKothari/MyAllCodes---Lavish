#include<stdio.h>
#include<bitset>
using namespace std;
bitset<1000000008>flag;
bool findAnswer(int*arr,int m)
{
	int second,first;
	for(int i=0;i<m;i++)
	{
		int temp=arr[i];
		if(flag[temp])
			return false;
		if(i==0)
		{
			first=second=temp;
			flag[temp]=1;
		}
		else
		{
			if(temp>first)
			{
				if(temp!=first+1)
					second=temp;
				first=temp;
				flag[temp]=1;
				continue;
			}
			int j;	
			for(j=second-1;j>0;j--)
			{
				if(!flag[j])
					break;
			}
			//printf("temp=%d and j=%d\n",temp,j);
			if(temp==j)
			{
				second=temp;
				flag[temp]=1;
			}
			else return false;
		}
	}
	return true;
}
int main()
{
	int m;
	scanf("%d",&m);
	flag.reset();
	int *arr=new int[m];
	for(int i=0;i<m;i++)
	{
		scanf("%d",&arr[i]);
	}
	bool a=findAnswer(arr,m);
	if(a)
		printf("YES\n");
	else printf("NO\n");

	return 0;
}
