#include<stdio.h>
#include<stdlib.h>
struct player
{
	int cost,bribe,isAlive;
};
struct match
{
	int x,y,willHappen;
};

int findMinBribeIndex(struct player*playerArray,int n)
{
	int i,min=2147483647,mini=-1;
	for(i=0;i<n;i++)
	{
		if(playerArray[i].isAlive && playerArray[i].bribe>0 && playerArray[i].bribe<min)
		{
		    mini=i;
		    //printf("hello Rakshit Kothari %d\n",mini);
			min=playerArray[i].bribe;
		}
	}
	return mini;
}

int main()
{
	int t,i,n,m,totalBribe,minIndex;
	struct player*playerArray;
	struct match*matchArray;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		
		playerArray=(struct player*)malloc(sizeof(struct player)*n);
		matchArray=(struct match*)malloc(sizeof(struct match)*m);
		
		for(i=0;i<m;i++)
			matchArray[i].willHappen=1;
		for(i=0;i<n;i++)
		{
		    playerArray[i].isAlive=1;
			playerArray[i].bribe=0;
		}
		for(i=0;i<n;i++)
			scanf("%d",&(playerArray[i].cost));
		
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&(matchArray[i].x),&(matchArray[i].y));
			matchArray[i].x--;matchArray[i].y--;
			playerArray[matchArray[i].x].bribe+=playerArray[matchArray[i].y].cost;
			playerArray[matchArray[i].y].bribe+=playerArray[matchArray[i].x].cost;
		}
		totalBribe=0;
		while(1)
		{
		    //printf("hello Lavish Kothari\n");
			minIndex=findMinBribeIndex(playerArray,n);
			//printf("minIndex = %d\n",minIndex);
			if(minIndex==-1)
				break;
			playerArray[minIndex].isAlive=0;
			for(i=0;i<m;i++)
			{
				if(matchArray[i].willHappen && matchArray[i].x==minIndex)
				{
					matchArray[i].willHappen=0;
					playerArray[matchArray[i].y].bribe-=playerArray[matchArray[i].x].cost;
				}
				if(matchArray[i].willHappen && matchArray[i].y==minIndex)
				{
					matchArray[i].willHappen=0;
					playerArray[matchArray[i].x].bribe-=playerArray[matchArray[i].y].cost;
				}
			}
			totalBribe+=playerArray[minIndex].bribe;
		}
		printf("%d\n",totalBribe);
	}
	return 0;
}

