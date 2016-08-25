#include<iostream>
#include<math.h>
#include<vector>
#include<string.h>
#define MAX 100000
using namespace std;

int main()
{
	string str;
	getline(cin,str);
	vector<double>s;
	int len=str.length();
	for(int i=0;i<len;)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			double sum=0;
			while(i<len && str[i]>='0' && str[i]<='9')
			{
				sum=sum*10+str[i]-'0';
				i++;
			}
			s.push_back(sum);
			i++;
			//cout<<sum<<endl;
		}
		else
		{
			char temp[5];int counter=0;
			while(i<len && str[i]!=' ')
			{
				temp[counter++]=str[i];
				i++;
			}
			i++;
			temp[counter]='\0';
			//cout<<temp<<endl;
			if(strcmp(temp,"add")==0)
			{
				double v2=*(s.end()-1);
				s.erase(s.end()-1);
				double v1=*(s.end()-1);
				s.erase(s.end()-1);
				s.push_back(v1+v2);
			}
			else if(strcmp(temp,"sub")==0)
			{
				double v2=*(s.end()-1);
				s.erase(s.end()-1);
				double v1=*(s.end()-1);
				s.erase(s.end()-1);
				s.push_back(v1-v2);
			}
			else if(strcmp(temp,"mul")==0)
			{
				double v2=*(s.end()-1);
				s.erase(s.end()-1);
				double v1=*(s.end()-1);
				s.erase(s.end()-1);
				s.push_back(v1*v2);
			}
			else if(strcmp(temp,"div")==0)
			{
				double v2=*(s.end()-1);
				s.erase(s.end()-1);
				double v1=*(s.end()-1);
				s.erase(s.end()-1);
				s.push_back(v1/v2);
			}
			else if(strcmp(temp,"mod")==0)
			{
				double v2=*(s.end()-1);
				s.erase(s.end()-1);
				double v1=*(s.end()-1);
				s.erase(s.end()-1);
				s.push_back((int)v1%(int)v2);
			}
			else if(strcmp(temp,"sqrt")==0)
			{
				double v1=*(s.end()-1);
				s.erase(s.end()-1);
				s.push_back(sqrt(v1));
			}			
		}
		
	}
	cout<<s[0]<<endl;
	return 0;
}
