#include<stdio.h>
#include<stdlib.h>
#define N 4
void printMat(int**mat)
{
	int i,j;
	
	printf("******\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	printf("******\n");
}

void update(int**mat,char move)
{
	int i,row,col,row1,col1;
	if(move=='D')
		for(col=0;col<N;col++)
			for(row=N-1;row>0;row--)
			{
				for(row1=row-1;row1>=0;row1--)
					if(mat[row1][col]!=0)
						break;
				if(row1!=-1)
				{
					if(mat[row1][col]==mat[row][col])
					{
						mat[row][col]+=mat[row][col];
						mat[row1][col]=0;
					}
					else if(mat[row][col]==0)
					{
						mat[row][col]=mat[row1][col];
						mat[row1][col]=0;
						row++;
					}
					else 
					{
						mat[row-1][col]=mat[row1][col];
						if(row1!=row-1)
							mat[row1][col]=0;
					}
				}
			}
	
	if(move=='U')
		for(col=0;col<N;col++)
			for(row=0;row<N-1;row++)
			{
				for(row1=row+1;row1<N;row1++)
					if(mat[row1][col]!=0)
						break;
				if(row1!=N)
				{
					if(mat[row1][col]==mat[row][col])
					{
						mat[row][col]+=mat[row][col];
						mat[row1][col]=0;
					}
					else if(mat[row][col]==0)
					{
						mat[row][col]=mat[row1][col];
						mat[row1][col]=0;
						row--;
					}
					else 
					{
						mat[row+1][col]=mat[row1][col];
						if(row+1!=row1)
							mat[row1][col]=0;
					}
					
				}
			}
	
	if(move=='R')
		for(row=0;row<N;row++)
		{
			for(col=N-1;col>0;col--)
			{
				for(col1=col-1;col1>=0;col1--)
					if(mat[row][col1]!=0)
						break;
				if(col1!=-1)
				{
					if(mat[row][col1]==mat[row][col])
					{
						mat[row][col]+=mat[row][col];
						mat[row][col1]=0;
					}
					else if(mat[row][col]==0)
					{
						mat[row][col]=mat[row][col1];
						mat[row][col1]=0;
						col++;
					}
					else 
					{
						mat[row][col-1]=mat[row][col1];
						if(col-1!=col1)
							mat[row][col1]=0;
					}
				}
			}
			
		}
	if(move=='L')
		for(row=0;row<N;row++)
			for(col=0;col<N-1;col++)
			{
				for(col1=col+1;col1<N;col1++)
					if(mat[row][col1]!=0)
						break;
				if(col1!=N)
				{
					if(mat[row][col1]==mat[row][col])
					{
						mat[row][col]+=mat[row][col];
						mat[row][col1]=0;
					}
					else if(mat[row][col]==0)
					{
						mat[row][col]=mat[row][col1];
						mat[row][col1]=0;
						col--;
					}
					else
					{ 
						mat[row][col+1]=mat[row][col1];
						if(col+1!=col1)
							mat[row][col1]=0;
					}
				}
			}
	
}
int main()
{
	int**mat,i,j,count[1<<16]={0},max=0;
	char str[1000];
	mat=(int**)malloc(sizeof(int*)*N);
	for(i=0;i<N;i++)
		mat[i]=(int*)malloc(sizeof(int)*N);
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&mat[i][j]);
	
	scanf(" %[^\n]s",str);
	for(i=0;str[i];i++)
		if(str[i]!=' ')
			update(mat,str[i]);
			
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			count[mat[i][j]]++;
	for(i=1;i<16;i++)
	{
		if(count[1<<i] && max<i)
			max=i;
	}
	for(i=1;i<=max;i++)
	{
		printf("%d ",count[1<<i]);
	}
	
	return 0;	
}
