#include<stdio.h>
#include<stdlib.h>
int sourcex,sourcey,destinationx,destinationy;
int findDirection(char**str,int r,int c,int startx,int starty)
{
	if(str[startx-1][starty]=='Y')
		startx--;
	else if(str[startx+1][starty]=='Y')
		startx++;
	else if(str[startx][starty-1]=='Y')
		starty--;
	else if(str[startx][starty+1]=='Y')
		starty++;

	/*
		EAST  => 0
		WEST  => 1
		NORTH => 2
		SOUTH => 3
		ANY   => 4
	*/
	if(starty+1!=c && str[startx][starty+1]=='Y')
		return 0;
	else if(starty!=0 && str[startx][starty-1]=='Y')
		return 1;
	else if(startx!=0 && str[startx-1][starty]=='Y')
		return 2;
	else if(startx+1!=r && str[startx+1][starty]=='Y')
		return 3;
	else return 4;
}

int findAnswer(char**str,int r,int c,int startx,int starty)
{
	int dir,answer0,answer1,answer2,answer3;

	printf("this is called %d %d\n",destinationx,destinationy);
	if(startx>=r || startx<0 || starty>=c || starty<0)
		return 0;
	if(startx==destinationx && starty==destinationy)
		return 1;
	if(str[startx][starty]=='*')
		return 0;

	str[startx][starty]='Y';
	dir=findDirection(str,r,c,startx,starty);
	printf("%d\n",dir);

    answer0=findAnswer(str,r,c,startx,starty+1);
    if(dir==0 && answer0)
		return 1;
	
	answer1=findAnswer(str,r,c,startx,starty-1);
    if(dir==1 && answer1)
		return 1;
	
	answer2=findAnswer(str,r,c,startx-1,starty);
    if(dir==2 && answer2)
		return 1;
	
	answer3=findAnswer(str,r,c,startx+1,starty);
    if(dir==3 && answer3)
		return 1;

	if(answer0 || answer1 || answer2 || answer3)
	    return 1;

	str[startx][starty]='.';
	return 0;
}
int main()
{
	int r,c,prevdir,dir,flag,i,j,turns;
	char **str;
	scanf("%d%d",&r,&c);
	str=(char**)malloc(sizeof(char*)*r);
	for(i=0;i<r;i++)
		str[i]=(char*)malloc(sizeof(char)*(c+1));
	for(i=0;i<r;i++)
		scanf("%s",str[i]);
	printf("hello lavish kothari\n");
	for(i=0;i<r;i++)
	{
		for(j=0;str[i][j];j++)
		{
			if(str[i][j]=='H')
			{
				sourcex=i;
				sourcey=j;
			}
			if(str[i][j]=='L')
			{
				destinationx=i;
				destinationy=j;
			}
		}
	}
	findAnswer(str,r,c,sourcex,sourcey);
	i=sourcex;
	j=sourcey;
	turns=0;
	flag=0;
	while(i!=destinationx || j!=destinationy)
	{
		if(flag==1)
			prevdir=dir;
		//previ=i;prevj=j;
		if(str[i+1][j]=='Y')
			{i++;dir=3;}
		else if(str[i-1][j]=='Y')
			{i--;dir=2;}
		else if(str[i][j+1]=='Y')
			{j++;dir=0;}
		else if(str[i][j-1]=='Y')
			{j--;dir=1;}
		if(flag==0)
		{
			flag=1;
			prevdir=dir;
		}
		if(prevdir!=dir)
			turns++;
	}
	return 0;
}
