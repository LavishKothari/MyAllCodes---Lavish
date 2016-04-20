#include<stdio.h>

int main()
{
	char str[51];
	int t,x,i,y;scanf("%d",&t);
	while(t--)
	{
		x=0;y=0;
		scanf(" %s",str);
		for(i=0;str[i];i++)
		{
			if(str[i]=='N') {x+=0;y+=1;}
			if(str[i]=='S') {x+=0;y-=1;}
			if(str[i]=='E') {x+=1;y+=0;}
			if(str[i]=='W') {x-=1;y+=0;}
		}	
		if(y==0 && x<0) printf("WEST\n");
		else if(y==0 && x>0) printf("EAST\n");
		else if(y<0 && x==0) printf("SOUTH\n");
		else if(y>0 && x==0) printf("NORTH\n");
		else if(y<0 && x<0) printf("SOUTHWEST\n");
		else if(y<0 && x>0) printf("SOUTHEAST\n");
		else if(y>0 && x<0) printf("NORTHWEST\n");
		else if(y>0 && x>0) printf("NORTHEAST\n");
	}
	return 0;
}
