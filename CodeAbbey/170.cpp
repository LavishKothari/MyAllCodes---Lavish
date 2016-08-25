#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Iptable
{
	public:
	string start,offset,country_code;
	Iptable(char *start,char*offset,char*country_code)
	{
		this->start=string(start);
		this->offset=string(offset);
		this->country_code=string(country_code);
		
	}
};
vector<Iptable>v;
long long int to10(const string&s)
{
	long long int answer=0;
	for(int i=0;i<s.size();i++)
		if(s[i]>=-'0' && s[i]<='9')
			answer=answer*36+s[i]-'0';
		else answer=answer*36+s[i]-'a'+10;
	return answer;
}
FILE* handlefile()
{
	FILE*fp=fopen("db-ip.txt","r");
	if(fp)
	{
		while(!feof(fp))
		{
			char start[100],offset[100],country_code[100];
			fscanf(fp," %s %s %s",start,offset,country_code);
			v.push_back(Iptable(start,offset,country_code));
		}
	}
	else printf("There was some error in opening the file!!\n");
	return fp;
}
bool cmp(const Iptable&a,const string & s)
{
	return to10(a.start)<to10(s);
}
string binary_search(const string& ip)
{
	int i=lower_bound(v.begin(),v.end(),ip,cmp)-v.begin();
	if(v[i].start != ip)
		i--;
	return v[i].country_code;
}
int main()
{
	FILE*fp;
	int t;char str[100];
	if(fp=handlefile())
		;//printf("");
	else printf("File operations were not successful\n");
	
	cin>>t;
	while(t--)
	{
		scanf(" %s",str);
		string ip=string(str);
		cout<<binary_search(ip)<<" ";
	}
	return 0;
}
