#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
	return a>b?a:b;
}
void print(int **T,int i,int j,int*w)
{
	if(i<1 || j<1)
		return;
		
	if(T[i][j]==T[i-1][j])
	{
		print(T,i-1,j,w);
		return;
	}
	print(T,i-1,j-w[i-1],w);
	printf("%d ",i-1);
}
void printOptimal(int*w,int*v,int N,int W)
{
	int i,j,**T;
	
	T=(int**)malloc(sizeof(int*)*(N+1));
	for(i=0;i<=N;i++)
		T[i]=(int*)malloc(sizeof(int)*(W+1));
	
	
	for(i=0;i<=W;i++)
		T[0][i]=0;
	for(i=0;i<=N;i++)
		T[i][0]=0;
	
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=W;j++)
		{
			T[i][j]=T[i-1][j];
			if(j-w[i-1]>=0)
				T[i][j]=max(T[i][j],T[i-1][j-w[i-1]]+v[i-1]);
		}
	}
	/*
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=W;j++)
			printf("%d ",T[i][j]);
		printf("\n");
	}
	*/
	print(T,N,W,w);
	
	//printf("%d\n",T[N][W]);
}
int main(){

	int i,N,W,*v,*w;
	scanf("%d%d",&N,&W);
	v=(int*)malloc(sizeof(int)*N);
	w=(int*)malloc(sizeof(int)*N);
	
	for(i=0;i<N;i++)
		scanf("%d%d",&w[i],&v[i]);
	printOptimal(w,v,N,W);
	return 0;
}
