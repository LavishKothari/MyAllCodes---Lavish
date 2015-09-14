#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Point
{
	public:
	int number,x,y;
	long long dist;
	Point(int,int,int,long long int);
	Point(){}
	
};
bool operator<(const Point &p1, const Point &p2)
{
    if(p2.dist < p1.dist)
        return true;
    else
        return false;
}
Point::Point(int number,int x,int y,long long int dist)
{
	this->x=x;
	this->y=y;
	this->number=number;
	this->dist=dist;
}
class Answer
{
	public:
	int number,dir;
	Answer(int,int);
};
Answer::Answer(int number,int dir)
{
	this->number=number;
	this->dir=dir;
}

std::vector<Answer>answerArray;

bool findMinMax(vector<Point>&points)
{
	int maxix,maxiy,minix,miniy,maxx,maxy,minx,miny,i;
	
	for(i=0;i<points.size();i++)
	{
		//printf("%d = %d,%d\n",points[i].number,points[i].x,points[i].y);
		if(i==0)
		{
			minx=points[i].x;
			miny=points[i].y;
			maxx=points[i].x;
			maxy=points[i].y;
			maxiy=minix=miniy=maxix=points[i].number;
		}
		else
		{
			if(minx>points[i].x)
			{
				minix=points[i].number;
				minx=points[i].x;
			}
			if(miny>points[i].y)
			{
				miniy=points[i].number;
					miny=points[i].y;
			}
			if(maxx<points[i].x)
			{
				maxix=points[i].number;
				maxx=points[i].x;
			}
			if(maxy<points[i].y)
			{
				maxiy=points[i].number;
				maxy=points[i].y;
			}
		}
	}
	//printf("maxmin = %d %d %d %d\n",maxix,maxiy,minix,miniy);
	if(maxix==maxiy)
	{	
		answerArray.push_back(Answer(maxix,0));
		//printf("you are here : dir = 2 SW\n");
		points.clear();
		return true;
	}
	else if(maxix==miniy)
	{
		answerArray.push_back(Answer(maxix,2));
		points.clear();
		return true;
	}
	else if(minix==maxiy)
	{
		answerArray.push_back(Answer(maxiy,3));
		points.clear();
		return true;
	}
	else if(minix==miniy)
	{
		answerArray.push_back(Answer(minix,1));
		points.clear();
		return true;
	}
	return false;
}
int main()
{
	Point p;
	int t,n,maxix,maxiy,minix,miniy,maxx,maxy,minx,miny,i,j,counter,answer,f,x,y,dir;
	
	std::vector<Point>points;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		//points=(struct Point*)malloc(sizeof(struct Point)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			points.push_back(Point(i+1,x,y,(long long int)x*x+(long long int )y*y));
		}
		
		std::sort(points.begin(),points.end());
		//printf("sorted\n");
		while(points.size()!=0)
		{
			if(!findMinMax(points))
			{
				dir=findDir(points);
				for(i=0;i<points.size();i++)
				{
					//answerArray[answer].number=points[i].number;
					if(dir==0)
						answerArray.push_back(Answer(points[i].number,0));
					else if(dir==1)
						answerArray.push_back(Answer(points[i].number,1));
					else if(dir==2)
						answerArray.push_back(Answer(points[i].number,2));
					else if(dir==3)
						answerArray.push_back(Answer(points[i].number,3));
					break;
				}
				
				if(dir==0)
				{
					for(j=1;j<points.size();j++)
						if(points[j].x<=points[i].x && points[j].y<=points[i].y)
						{
							points.erase(points.begin()+j);
							j--;
						}
				}
				else if(dir==3)
				{
					for(j=1;j<points.size();j++)
						if(points[j].x>=points[i].x && points[j].y<=points[i].y)
						{
							points.erase(points.begin()+j);
							j--;
						}
				}
				else if(dir==1)
				{
					for(j=1;j<points.size();j++)
						if(points[j].x<=points[i].x && points[j].y>=points[i].y)
						{
							points.erase(points.begin()+j);
							j--;
						}
				}
				else if(dir==2)
				{
					for(j=1;j<points.size();j++)
						if(points[j].x>=points[i].x && points[j].y>=points[i].y)
						{
							points.erase(points.begin()+j);
							j--;
						}
				}
				//printf("Till here also its all okay\n");
				points.erase(points.begin());
			}
			else break;
				
		}
		printf("%d\n",answerArray.size());
		for(i=0;i<answerArray.size();i++)
		{
			printf("%d ",answerArray[i].number);
			if(answerArray[i].dir==0)
				printf("SW\n");
			if(answerArray[i].dir==1)
				printf("NW\n");
			if(answerArray[i].dir==2)
				printf("NE\n");
			if(answerArray[i].dir==3)
				printf("SE\n");
					
		}
		answerArray.clear();
		points.clear();
	}
	
	return 0;
}
