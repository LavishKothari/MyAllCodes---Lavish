#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **adjacencyMatrix;
	int A = 445, C = 700001, M = 2097152;
	int n,x,sum,i,j;
	long long int a,b,c,d;
	scanf("%d%d",&n,&x);
	adjacencyMatrix=(int**)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		adjacencyMatrix[i]=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adjacencyMatrix[i][j]=0;
	for(i=0;i<n;i++)
	{
		a=x=(A*x+C)%M;
		b=x=(A*x+C)%M;
		c=x=(A*x+C)%M;
		d=x=(A*x+C)%M;
		a=a%n;
		b=b%n+1;
		c=c%n;
		d=d%n+1;
		if(adjacencyMatrix[i][a]==0) adjacencyMatrix[i][a]=b;
		if(adjacencyMatrix[a][i]==0) adjacencyMatrix[a][i]=b;
		if(adjacencyMatrix[i][c]==0) adjacencyMatrix[i][c]=d;
		if(adjacencyMatrix[c][i]==0) adjacencyMatrix[c][i]=d;
	}
	for(i=0;i<n;i++)
		adjacencyMatrix[i][i]=0;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
			sum+=adjacencyMatrix[j][i];
		printf("%d ",sum);
	}
	return 0;
}
