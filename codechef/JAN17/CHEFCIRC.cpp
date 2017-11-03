#include <bits/stdc++.h>

using namespace std;

double dist2(pair<double,double>a,pair<double,double>b)
{
	double x1=a.first,y1=a.second,x2=b.first,y2=b.second;
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
class Circle
{
	public:
		double xc,yc,r;
		Circle(double xc,double yc,double r)
		{
			this->xc = xc;
			this->yc = yc;
			this->r = r;
		}
};
bool operator<(const Circle &a,const Circle &b)
{
	double epsilon=0.0001;
	return (a.xc-b.xc)<epsilon || (a.yc-b.yc)<epsilon || (a.r-b.r)<epsilon;
}
bool findCircle(int i,int j,int k,vector<pair<double,double> >&points,double &xc,double &yc,double &radius2)
{
	set<pair<double,double> >sp;
	sp.insert(points[i]);
	sp.insert(points[j]);
	sp.insert(points[k]);
	//cout<<"spsizze = "<<sp.size()<<endl;
	if(sp.size()==1)
	{
		xc = points[i].first;
		yc = points[i].second;
		radius2=0;
		return true;
	}
	else if(sp.size()==2)
	{
		pair<double,double>p1 = *sp.begin();
		sp.erase(p1);
		pair<double,double>p2 = *sp.begin();

		double x1=p1.first,x2=p2.first,y1=p1.second,y2=p2.second;
		xc = (x1+x2)/2;
		yc = (y1+y2)/2;
		radius2 = dist2(p1,p2)/4;
		return true;
	}

	double x1=points[i].first,y1=points[i].second,x2=points[j].first,y2=points[j].second,x3=points[k].first,y3=points[k].second;

	if(y2==y3 && y1==y2)
		return false;

	if(y2==y3)
	{
		double m1 = (x1-x2)/(y2-y1);
		double c1 = (y2+y1)/2 - (x2+x1)/2*m1;	
		xc = (x3+x2)/2;
		yc = m1*xc+c1;
		radius2 = (xc-x1)*(xc-x1) + (yc-y1)*(yc-y1);
		return true;
	}

	if(y1==y2)
	{
		double m2 = (x3-x2)/(y2-y3);
		double c2 = (y2+y3)/2 - (x2+x3)/2*m2;
		xc = (x1+x2)/2;
		yc = m2*xc+c2;
		radius2 = (xc-x1)*(xc-x1) + (yc-y1)*(yc-y1);
		return true;
	}

	double m1,m2,c1,c2;
	m1 = (x1-x2)/(y2-y1);
	m2 = (x3-x2)/(y2-y3);
	c2 = (y2+y3)/2 - (x2+x3)/2*m2;
	c1 = (y2+y1)/2 - (x2+x1)/2*m1;

	if(abs(m2-m1)<0.0001)
		return false;

	xc = (c2-c1)/(m1-m2);
	yc = m1*xc+c1;
	radius2 = (xc-x1)*(xc-x1) + (yc-y1)*(yc-y1);

	return true;
}
bool isSatisfying(double xc,double yc,double r2,double x,double y)
{
	if( (x-xc)*(x-xc) + (y-yc)*(y-yc) - r2 <= 0.0001)
		return true;
	return false;
}
void findAnswer(vector<pair<double,double> >&points,int m)
{
	int n=points.size();
	if(n==1 || m==1)
	{
		cout<<"0.000000"<<endl;
		return;
	}
	if(m==2)
	{
		double minradius = FLT_MAX;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				double xc=(points[i].first+points[j].first)/2,yc=(points[i].second+points[j].second)/2,r=sqrt(dist2(points[i],points[j]))/2;
				//cout<<xc<<" "<<yc<<" "<<r<<endl;
				int satisfying=0;
				for(int k=0;k<n;k++)
					if(isSatisfying(xc,yc,r*r,points[k].first,points[k].second))
						satisfying++;
				if(satisfying>=m && r<minradius)
					minradius=r;
			}
		cout<<fixed;
		cout<<setprecision(6)<<minradius<<endl;
		return;
	}
	set<Circle>circleSet;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				double xc,yc,radius2;
				if(findCircle(i,j,k,points,xc,yc,radius2))
				{
					Circle c = Circle(xc,yc,sqrt(radius2));
					circleSet.insert(c);
				}
			}
		}
	}
	if(!circleSet.empty())
	{
		//cout<<circleSet.size()<<endl;
		double minradius = DBL_MAX;
		for(set<Circle>::iterator it = circleSet.begin();it!=circleSet.end();it++)
		{

			int satisfying=0;
			double xc = it->xc;
			double yc = it->yc;
			double r = it->r;

			//cout<<xc<<" "<<yc<<" "<<r<<endl;
			//int l = lower_bound(points.begin(),points.end(),make_pair(xc-r,yc))-points.begin();
			for(int l=0;l<n;l++)
			{
				//if(xc+r<points[l].first)
				//break;
				if(isSatisfying(xc,yc,r*r,points[l].first,points[l].second))
					satisfying++;
			}
			if(satisfying>=m && r<minradius)
				minradius=r;
		}
		cout<<fixed;
		cout<<setprecision(6)<<minradius<<endl;
	}
	else // all points are colinear
	{
		double minradius = FLT_MAX;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				double xc=(points[i].first+points[j].first)/2,yc=(points[i].second+points[j].second)/2,r=sqrt(dist2(points[i],points[j]))/2;
				int satisfying=0;
				for(int k=0;k<n;k++)
					if(isSatisfying(xc,yc,r*r,points[k].first,points[k].second))
						satisfying++;
				if(satisfying>=m && r<minradius)
					minradius=r;
			}
		cout<<fixed;
		cout<<setprecision(6)<<minradius<<endl;

	}
}


int main()
{
	int n,m;
	cin>>n>>m;

	vector<pair<double,double> >points(n);
	for(int i=0;i<n;i++) 
		cin>>points[i].first>>points[i].second;
	sort(points.begin(),points.end());
	findAnswer(points,m);
	return 0;
}
