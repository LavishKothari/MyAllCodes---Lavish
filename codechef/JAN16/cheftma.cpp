#include<stdio.h>
#include<stdlib.h>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
class O
{
	public:
	int a,b,number,diff;
	O(int,int,int,int);
};
O::O(int a,int b,int number,int diff)
{
	this->a=a;
	this->b=b;
	this->number=number;
	this->diff=diff;
}
class Button
{
	public:
	int value;bool isw,isUsed;
	Button(int,bool,bool);
};
Button::Button(int value,bool isw,bool isUsed)
{
	this->value=value;
	this->isw=isw;
	this->isUsed=isUsed;
}

bool cmpfdiff(const O&x,const O&y)
{
	return x.diff>y.diff;
}
bool cmpfButtons(const Button&x,const Button&y)
{
	return y.value>x.value;
}
bool compareLower(int v,const Button&x)
{
	return v<x.value;
}
long long int findAnswer(vector<O>o,vector<Button>buttons,int n,int kplusm)
{
	sort(buttons.begin(),buttons.end(),cmpfButtons);
	sort(o.begin(),o.end(),cmpfdiff);
	long long int answer=0;
	for(int i=0;i<n;i++)
	{
		int index=upper_bound(buttons.begin(),buttons.end(),o[i].diff,compareLower)-buttons.begin();
		index--;
		//printf("index = %d and diff = %d\n",index,o[i].diff);
		while(index>=0)
		{
			//index--;
			if(buttons[index].isUsed==false)
			{
				answer-=buttons[index].value;
				buttons[index].isUsed=true;
				break;
			}
			index--;
		}
	}
	return answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,m;
		scanf("%d%d%d",&n,&k,&m);
		vector<O>objects;
		vector<Button>buttons;
		
		int*a=new int[n];
		int*b=new int[n];
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		long long int answer=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			answer+=a[i]-b[i];
		}
		
		for(int i=0;i<n;i++)
		{
			objects.push_back(O(a[i],b[i],i,a[i]-b[i]));
			//printf("hello %d\n",a[i]-b[i]);
		}
		delete a;
		delete b;
		int*value=new int[k+m];
		bool*isw=new bool[k+m];
		bool*isUsed=new bool[k+m];
		
		for(int i=0;i<k;i++)
		{	
			scanf("%d",&value[i]);
			isw[i]=true;
			isUsed[i]=false;
		}
		for(int i=k;i<m+k;i++)
		{
			scanf("%d",&value[i]);
			isw[i]=false;
			isUsed[i]=false;
		}
		for(int i=0;i<m+k;i++)
			buttons.push_back(Button(value[i],isw[i],isUsed[i]));
		delete value;
		delete isw;
		delete isUsed;
		printf("%lld\n",answer+findAnswer(objects,buttons,n,k+m));
	}
	return 0;
}
