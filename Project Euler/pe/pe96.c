#include<stdio.h>
#include<stdlib.h>
#define N 9
int isSafe(int**mat,int r,int c,int v)
{
	int i,j,x,y	;
	for(i=0;i<N;i++)
		if(mat[i][c]==v)
			return 0;
	for(j=0;j<N;j++)
		if(mat[r][j]==v)
			return 0;
	x=r/3*3;
	y=c/3*3;
	for(i=x;i<x+3;i++)
		for(j=y;j<y+3;j++)
			if(mat[i][j]==v)
				return 0;
	return 1;
}
int solveSudoku(int **mat,int row,int col)
{
	int r,c,i;
	//printf("%d %d\n",row,col);
	if(row>=N || col>=N)
		return 1;
	if(mat[row][col])
	{
		if(col==N-1)
		{
			r=row+1;
			c=0;
		}
		else
		{
		 	c=col+1;
		 	r=row;
		 }
		return solveSudoku(mat,r,c);
	}
	for(i=1;i<=N;i++)
		if(isSafe(mat,row,col,i))
		{
			mat[row][col]=i;
			if(col==N-1)
			{
				r=row+1;
				c=0;
			}
			else
			{
			 	c=col+1;
			 	r=row;
			 }
			if(solveSudoku(mat,r,c))
				return 1;
			mat[row][col]=0;
		}
	return 0;
}

int main()
{
	FILE*fp;
	int **mat,x,i,j,answer;
	char temp,temparr[100];
	fp=fopen("sudoku.txt","r");
	mat=(int**)malloc(sizeof(int*)*N);
	for(i=0;i<N;i++)
		mat[i]=(int*)malloc(sizeof(int)*N);
	if(fp)
	{
		answer=0;
		for(x=0;x<50;x++)
		{
			printf("Solving %d\n",x+1);
			fscanf(fp," %[^\n]s",temparr);
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
				{
					fscanf(fp," %c",&temp);
					mat[i][j]=temp-'0';
				}	
			solveSudoku(mat,0,0);// assuming all sudokus are valid.
			answer=answer+ mat[0][0]*100+mat[0][1]*10+mat[0][2];
			/*
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++)
					printf("%d ",mat[i][j]);
				printf("\n");
			}
			*/	
		}
		printf("Answer is = %d\n",answer);
	}
	else printf("File operation not successful\n");		
	return 0;
}
