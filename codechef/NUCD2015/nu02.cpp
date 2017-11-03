#include<stdio.h>
#include<vector>
using namespace std;
int findFirstOccurrence(vector<char>a,vector<char>b,int start)
{
	int i,j,ci;
	for(i=start;i<a.size();i++)
	{
		ci=i;
		for(j=0;j<b.size() && ci<a.size();j++,ci++)
		{
			if(a[ci]!=b[j])
				break;
		}
		if(j==b.size())
			return i;
	}
	return -1;
}
int main()
{
	int t,i,x,y;
	vector<char>st,en,data;
	char s[11],e[11],d[1001];
	scanf("%d",&t);
	while(t--)
	{
		data.clear();
		en.clear();
		st.clear();
		scanf(" %s",s);
		scanf(" %s",e);
		scanf(" %s",d);
		for(i=0;s[i];i++)
			st.push_back(s[i]);
		for(i=0;e[i];i++)
			en.push_back(e[i]);
		for(i=0;d[i];i++)
			data.push_back(d[i]);
		y=0;
		while(1)
		{
			//printf("hello\n");
			x=findFirstOccurrence(data,st,y);
			y=findFirstOccurrence(data,en,x+st.size());
			if(x==-1 || y==-1 || data.size()<=0)
				break;
			y+=en.size();
			/*
			   printf("world %d %d\n",x,y);

			   for(i=x;i<y;i++)
			   printf("%c",data[i]);
			   printf("\n");
			 */
			for(i=x;i<y;i++)
				data.erase(data.begin()+x);
			y=x;
		}
		//printf("this is the answer : \n");

		for(i=0;i<data.size();i++)
			printf("%c",data[i]);
		printf("\n");
	}
	return 0;
}
