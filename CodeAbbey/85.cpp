#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Star
{
	public :
		string name;
		int x,y;
		Star(string s,double a,double b,double degree)
		{
			this->name=s;
			double angle=atan(b/a);
			if(b<0 && a<0)
				angle+=M_PI;
			else if(a<0)
				angle+=M_PI;
			else if(b<0)
				angle+=2*M_PI;
			angle+=degree*M_PI/180.0;
			while(angle<0)
				angle+=2*M_PI;
			while(angle>2*M_PI)
				angle-=2*M_PI;

			double dist=sqrt(a*a+b*b);
			x=(int)round(dist*cos(angle));
			y=(int)round(dist*sin(angle));
		}
};
bool cmpx(const Star&a,const Star&b)
{
	return a.x<b.x;
}
bool cmpy(const Star&a,const Star&b)
{
	return a.y<b.y;
}
int main()
{
	int t,degree;
	cin>>t>>degree;
	vector<Star>v;
	while(t--)
	{
		string s;
		double x,y;
		cin>>s>>x>>y;
		v.push_back(Star(s,x,y,degree));
	}
	stable_sort(v.begin(),v.end(),cmpx);
	stable_sort(v.begin(),v.end(),cmpy);
	for(int i=0;i<v.size();i++)
		cout<<v[i].name<<" "/*<<v[i].x<<" "<<v[i].y<<endl*/;
	return 0;
}
