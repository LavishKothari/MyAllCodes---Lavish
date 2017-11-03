#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Point
{
	public:
		int x,y;
		long long int dist;
		Point(int,int);
		Point(){}

};

Point::Point(int x,int y)
{
	this->x=x;
	this->y=y;
}
bool c1(const Point &p1, const Point &p2)
{
	if(p1.x < p2.x)
		return true;
	else
		return false;
}
int maxix,minix,maxiy,miniy;

bool findMinMax(vector<Point>&points)
{
	int maxx,maxy,minx,miny,i;
	for(i=0;i<points.size();i++)
	{
		//printf("%d = %d,%d\n",points[i].number,points[i].x,points[i].y);
		if(i==0)
		{
			minx=points[i].x;
			miny=points[i].y;
			maxx=points[i].x;
			maxy=points[i].y;
			maxiy=minix=miniy=maxix=i;
		}
		else
		{
			if(minx>points[i].x)
			{
				minix=i;
				minx=points[i].x;
			}

			if(miny>points[i].y)
			{
				miniy=i;
				miny=points[i].y;
			}

			if(maxx<points[i].x)
			{
				maxix=i;
				maxx=points[i].x;
			}

			if(maxy<points[i].y)
			{
				maxiy=i;
				maxy=points[i].y;
			}

		}
	}
	for(i=0;i<points.size();i++)
		if(points[i].x==points[maxix].x && points[i].y==points[maxiy].y)
		{	
			printf("1\n%d SW\n",i+1);
			return true;
		}

	for(i=0;i<points.size();i++)
		if(points[i].x==points[maxix].x && points[i].y==points[miniy].y)
		{
			printf("1\n%d NW\n",i+1);
			return true;
		}
	for(i=0;i<points.size();i++)
		if(points[i].x==points[minix].x && points[i].y==points[maxiy].y)
		{
			printf("1\n%d SE\n",i+1);
			return true;
		}

	for(i=0;i<points.size();i++)
		if(points[i].x==points[minix].x && points[i].y==points[miniy].y)
		{
			printf("1\n%d NE\n",i+1);
			return true;
		}


	return false;
}
int main()
{
	int t,n,x,y,i;
	bool b;
	std::vector<Point>points;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&x,&y);
			points.push_back(Point(x,y));
		}

		b=findMinMax(points);
		if(!b)
		{
			if(points[maxix].y>points[minix].y)
				printf("2\n%d SW\n%d NE\n",maxix+1,minix+1);
			else
				printf("2\n%d NW\n%d SE\n",maxix+1,minix+1);
		}
		points.clear();
	}	
	return 0;
}
