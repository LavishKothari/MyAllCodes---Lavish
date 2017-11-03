#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
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

int main()
{
	Point p;
	int t,n,maxix,maxiy,minix,miniy,maxx,maxy,minx,miny,i,j,counter,answer,f,x,y;
	std::vector<Answer>answerArray;
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
			if(i==0)
			{
				minx=points[i].x;
				miny=points[i].y;
				minix=0;
				miniy=0;
				maxix=0;
				maxiy=0;
				maxx=points[i].x;
				maxy=points[i].y;
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
		if(maxix==maxiy)
			printf("1\n%d SW\n",maxix);
		else if(maxix==miniy)
			printf("1\n%d NW\n",maxix);
		else if(minix==maxiy)
			printf("1\n%d SE\n",minix);
		else if(minix==miniy)
			printf("1\n%d NE\n",minix);
		else
		{
			std::sort(points.begin(),points.end());
			//printf("sorted\n");
			i=answer=counter=0;
			while(points.size()!=0)
			{
				printf("/************************************/\n");
				f=0;
				for(i=0;i<points.size();i++)
				{
					printf("%d = %d,%d\n",points[i].number,points[i].x,points[i].y);
					//if(points[i].isAlive==1)
					{
						if(f==0)
						{
							f=1;
							minx=points[i].x;
							miny=points[i].y;
							minix=points[i].number;
							miniy=points[i].number;
							maxix=points[i].number;
							maxiy=points[i].number;
							maxx=points[i].x;
							maxy=points[i].y;
						}
						else
						{
							if(minx>points[i].x)
							{
								printf("a %d\n",points[i].number);
								minix=points[i].number;
								minx=points[i].x;
							}
							if(miny>points[i].y)
							{
								printf("b %d\n",points[i].number);
								miniy=points[i].number;
								miny=points[i].y;
							}
							if(maxx<points[i].x)
							{
								printf("c\n");
								maxix=points[i].number;
								maxx=points[i].x;
							}
							if(maxy<points[i].y)
							{
								printf("d\n");
								maxiy=points[i].number;
								maxy=points[i].y;
							}
						}
					}
				}
				printf("This is getting worse : %d %d %d %d\n",maxix,maxiy,minix,miniy);
				if(maxix==maxiy)
				{
					printf("I m going!!!!\n");
					answerArray.push_back(Answer(maxix,2));
					break;
				}
				else if(maxix==miniy)
				{
					answerArray.push_back(Answer(maxix,3));
					break;
				}
				else if(minix==maxiy)
				{
					answerArray.push_back(Answer(maxiy,1));
					break;
				}
				else if(minix==miniy)
				{
					answerArray.push_back(Answer(minix,0));
					break;
				}
				else
				{
					//printf("Till here its all okay\n");
					for(i=0;i<points.size();i++)
						//if(points[i].isAlive==1)
					{
						//answerArray[answer].number=points[i].number;
						if(points[i].x>=0 && points[i].y>=0)
							answerArray.push_back(Answer(points[i].number,0));
						else if(points[i].x>=0 && points[i].y<=0)
							answerArray.push_back(Answer(points[i].number,1));
						else if(points[i].x<=0 && points[i].y<=0)
							answerArray.push_back(Answer(points[i].number,2));
						else if(points[i].x<=0 && points[i].y>=0)
							answerArray.push_back(Answer(points[i].number,3));
						break;
					}
					//points[i].isAlive=0;
					//printf("\n\nthe value of i is : %d\n",i);
					/*
					   for(j=0;j<points.size();j++)
					   printf("point number %d %d,%d\n",points[j].number,points[j].x,points[j].y);
					 */
					if(points[i].x>=0 && points[i].y>=0)
					{
						for(j=1;j<points.size();j++)
							if(points[j].x<=points[i].x && points[j].y<=points[i].y)
							{
								printf("erasing %d %d\n",points[j].x,points[j].y);
								points.erase(points.begin()+j);
								j--;
							}
					}
					else if(points[i].x<=0 && points[i].y>=0)
					{
						for(j=1;j<points.size();j++)
							if(points[j].x>=points[i].x && points[j].y<=points[i].y)
							{
								printf("erasing %d %d\n",points[j].x,points[j].y);
								points.erase(points.begin()+j);
								j--;
							}
					}
					else if(points[i].x>=0 && points[i].y<=0)
					{
						for(j=1;j<points.size();j++)
							if(points[j].x<=points[i].x && points[j].y>=points[i].y)
							{
								printf("erasing %d %d\n",points[j].x,points[j].y);
								points.erase(points.begin()+j);
								j--;
							}
					}
					else if(points[i].x<=0 && points[i].y<=0)
					{
						for(j=1;j<points.size();j++)
							if(points[j].x>=points[i].x && points[j].y>=points[i].y)
							{
								printf("erasing %d %d\n",points[j].x,points[j].y);
								points.erase(points.begin()+j);
								j--;
							}
					}
					//printf("Till here also its all okay\n");
					printf("finally erasing %d %d\n",points[0].x,points[0].y);
					points.erase(points.begin());
				}

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
			//free(answerArray);
			answerArray.clear();
		}
		points.clear();
		//free(points);
	}
	return 0;
}
