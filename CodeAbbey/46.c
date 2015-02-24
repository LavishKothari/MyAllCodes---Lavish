#include<stdio.h>
#include<stdlib.h>
#define ROWS 3
#define COLS 3
int isCompleted(int flag[ROWS][COLS])
{
	int i,j,check1=1,check0=0,f1,f0;
	// CHECKING FOR EACH ROW
	for(i=0;i<ROWS;i++)
	{
		f1=f0=0;
		for(j=0;j<COLS;j++)
		{
			if(flag[i][j]==check0)
				f0++;
			else if(flag[i][j]==check1)
				f1++;
		}
		if(f1==COLS || f0==COLS)
			return 1;
	}

	// CHECKING FOR EACH COLUMN
	for(i=0;i<COLS;i++)
	{
		f1=f0=0;
		for(j=0;j<ROWS;j++)
		{
			if(flag[j][i]==check0)
				f0++;
			else if(flag[j][i]==check1)
				f1++;
		}
		if(f1==ROWS || f0==ROWS)
			return 1;
	}

	//MAIN DIAGONAL
	f1=f0=0;
	for(i=0;i<ROWS;i++)
	{
		if(flag[i][i]==check0)
			f0++;
		else if(flag[i][i]==check1)
			f1++;
	}
	if(f1==ROWS || f0==ROWS)
		return 1;

	// OTHER DIAGONAL
	f1=f0=0;
	for(i=0,j=ROWS-1;i<ROWS;i++,j--)
	{
		if(flag[i][j]==check0)
			f0++;
		else if(flag[i][j]==check1)
			f1++;
	}
	if(f1==ROWS || f0==ROWS)
		return 1;

	// NO OTHER POSSIBILITY REMAINS
	return 0;
}
void print(int flag[ROWS][COLS])
{
	int j,i;
	printf("your responses are as follows : \n");
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			printf("%d",flag[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int t,n,flag[ROWS][COLS],i,j,f,*arr;
	scanf("%d",&t);
	arr=(int*)malloc(sizeof(int)*(ROWS*COLS));
	while(t--)
	{
		for(i=0;i<ROWS;i++)
			for(j=0;j<COLS;j++)
				flag[i][j]=-1;
		f=1;
		for(i=0;i<ROWS*COLS;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<ROWS*COLS;i++)
		{
			n=arr[i];
			flag[(n-1)/ROWS][(n-1)%ROWS]=f;
			f=!f;
			if(isCompleted(flag))
				break;
		}
		if(isCompleted(flag)) printf("%d ",(i+1));
		else printf("0 ");
	}
}
