#include<stdio.h>
int east,west,north,south,x,y;
int width,height,length;
void findNext()
{
	if(south==east && south==1){ x++; y++; }
	else if(north==west && north==1){ x--; y--; }
	else if(north==east && north==1){ x++; y--; }
	else if(south==west && south==1){ x--; y++; }
	if(x+length>width)
	{
	    if(south==east && south==1){ x-=2; east=0; west=1; }
	    if(north==west && north==1){ }
	    if(north==east && north==1){ x-=2; east=0; west=1; }
	    if(south==west && south==1){ }
	}
	if(y>=height)
	{
	    if(south==east && south==1){ y-=2; south=0; north=1; }
	    if(north==west && north==1){ }
	    if(north==east && north==1){ }
	    if(south==west && south==1){ y-=2; south=0; north=1; }
	}
	if(x<0)
	{
		if(south==east && south==1){ }
	    if(north==west && north==1){ x+=2; west=0; east=1; }
	    if(north==east && north==1){ }
	    if(south==west && south==1){ x+=2; west=0; east=1; }
	}
	if(y<0)
	{
		if(south==east && south==1){ }
	    if(north==west && north==1){ y+=2; north=0; south=1; }
	    if(north==east && north==1){ y+=2; north=0; south=1; }
	    if(south==west && south==1){ }
	}
}
int main()
{
	int i;
	scanf("%d%d%d",&width,&height,&length);
	south=east=1;
	west=north=0;
	x=y=0;
	printf("0 0 ");
	for(i=0;i<100;i++)
	{
		findNext();
		printf("%d %d ",x,y);
	}
	return 0;
}
