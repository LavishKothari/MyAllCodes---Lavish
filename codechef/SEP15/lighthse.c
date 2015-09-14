#include<stdio.h>
#include<stdlib.h>
struct Point
{
	int number,x,y,isAlive;
	long long dist;
};
struct Answer
{
	int number,dir;
};
int cmpfunc(const void *a,const void *b)
{
	struct Point*c,*d;
	c=(struct Point*)a;
	d=(struct Point*)b;
	if((d->dist)==(c->dist))
		return 0;
	else if((d->dist)<(c->dist))
		return -1;
	else if((d->dist)>(c->dist))
		return 1;
}
int main()
{
	int t,n,maxix,maxiy,minix,miniy,maxx,maxy,minx,miny,i,j,counter,answer,f;
	struct Answer*answerArray;
	struct Point*points;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		points=(struct Point*)malloc(sizeof(struct Point)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&points[i].x,&points[i].y);
			points[i].number=i;
			points[i].isAlive=1;
			points[i].dist=(long long int)points[i].x*points[i].x+(long long int)points[i].y*points[i].y;
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
			printf("1\n%d SW\n",maxix+1);
		else if(maxix==miniy)
			printf("1\n%d NW\n",maxix+1);
		else if(minix==maxiy)
			printf("1\n%d SE\n",minix+1);
		else if(minix==miniy)
			printf("1\n%d NE\n",minix+1);
		else
		{
			qsort(points,n,sizeof(struct Point),cmpfunc);

			i=answer=counter=0;
			answerArray=(struct Answer*)malloc(sizeof(struct Answer)*n);
			while(counter!=n)
			{
				printf("hello lavish kothari\n");
				f=0;
				for(i=0;i<n;i++)
				{
					if(points[i].isAlive==1)
					{
						if(f==0)
						{
							f=1;
							minx=points[i].x;
							miny=points[i].y;
							minix=i;
							miniy=i;
							maxix=i;
							maxiy=i;
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
				}
				if(maxix==maxiy)
				{
					//printf("1\n%d SW\n",maxix+1);
					answerArray[answer].number=maxix+1;
					answerArray[answer].dir=2;
					
					answer++;
					break;
				}
				else if(maxix==miniy)
				{
					//printf("1\n%d NW\n",maxix+1);
					answerArray[answer].number=maxix+1;
					answerArray[answer].dir=3;
					
					answer++;
					break;
				}
				else if(minix==maxiy)
				{
					//printf("1\n%d SE\n",minix+1);
					answerArray[answer].number=maxiy+1;
					answerArray[answer].dir=1;
					
					answer++;
					break;
				}
				else if(minix==miniy)
				{
					//printf("1\n%d NE\n",minix+1);
					answerArray[answer].number=minix+1;
					answerArray[answer].dir=0;
					
					answer++;
					break;
				}
				else
				{
					for(;i<n;i++)
						if(points[i].isAlive==1)
						{
							answerArray[answer].number=points[i].number;
							if(points[i].x>=0 && points[i].y>=0)
								answerArray[answer].dir=0;
							else if(points[i].x>=0 && points[i].y<=0)
								answerArray[answer].dir=1;
							else if(points[i].x<=0 && points[i].y<=0)
								answerArray[answer].dir=2;
							else if(points[i].x<=0 && points[i].y>=0)
								answerArray[answer].dir=3;
							answer++;
							break;
						}
					if(i==n)
						break;
					counter++; // taking the firs in the array
					points[i].isAlive=0;
					if(points[i].x>=0 && points[i].y>=0)
					{
						for(j=i+1;j<n;j++)
						{
							if(points[j].isAlive==1 && points[j].x<=points[i].x && points[j].y<=points[i].y)
							{
								points[j].isAlive=0;
								counter++;
							}
						}
					}
					else if(points[i].x<=0 && points[i].y>=0)
					{
						for(j=i+1;j<n;j++)
						{
							if(points[j].isAlive==1 && points[j].x>=points[i].x && points[j].y<=points[i].y)
							{
								points[j].isAlive=0;
								counter++;
							}
						}
					}
					else if(points[i].x>=0 && points[i].y<=0)
					{
						for(j=i+1;j<n;j++)
						{
							if(points[j].isAlive==1 && points[j].x<=points[i].x && points[j].y>=points[i].y)
							{
								points[j].isAlive=0;
								counter++;
							}
						}
					}
					else if(points[i].x<=0 && points[i].y<=0)
					{
						for(j=i+1;j<n;j++)
						{
							if(points[j].isAlive==1 && points[j].x>=points[i].x && points[j].y>=points[i].y)
							{
								points[j].isAlive=0;
								counter++;
							}
						}
					}
				
				}
				printf("%d\n",answer);
				for(i=0;i<answer;i++)
				{
					printf("%d ",answerArray[i].number+1);
					if(answerArray[i].dir==0)
						printf("SW\n");
					if(answerArray[i].dir==1)
						printf("NW\n");
					if(answerArray[i].dir==2)
						printf("NE\n");
					if(answerArray[i].dir==3)
						printf("SE\n");
					
				}
				free(answerArray);
			}
		}
		
		free(points);
	}
	return 0;
}
