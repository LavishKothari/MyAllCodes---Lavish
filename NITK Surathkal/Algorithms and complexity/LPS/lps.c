#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 9	
void generateTestCases()
{
	FILE*f;
	int i;
	f=fopen("tests.txt","w");
	srand(time(NULL));
	for(i=0;i<MAX;i++)
		fprintf(f,"%c",(char)(random()%26+'A'));
	fclose(f);
}
void printLPS(char*str,int **direction,int n,int a,int b)
{
	if(a>b)
		return ;
	if(a==b)
		printf("%c",str[a]);
	else if(direction[a][b]==0)
		printLPS(str,direction,n,a,b-1);
	else if(direction[a][b]==1)
	{
		printf("%c",str[a]);
		printLPS(str,direction,n,a+1,b-1);
		printf("%c",str[b]);
	}
	else if(direction[a][b]==2)
		printLPS(str,direction,n,a+1,b);	
}
void print2d(int**direction,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",direction[i][j]);
		printf("\n");
	}
}
int LPS(char*str,int n)
{
	int**L,**direction;
	int answer,i,j;
	L=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		L[i]=(int*)malloc(sizeof(int)*n);
	
	direction=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		direction[i]=(int*)malloc(sizeof(int)*n);
	/*
		L[i][j] will store the length of longest palindromic subsequence for the sub-array str[i]..str[j]
	*/
	for(i=0;i<n;i++)
	{
		L[i][i]=1; 	// In the sub-array with only one element you can have LPS of length 1
		if(i!=0)
			L[i][i-1]=0;			
	}
	
	for(i=n-2;i>=0;i--)
	{
		for(j=i+1;j<n;j++)
		{
			if(str[i]==str[j])
			{
				L[i][j]=2+L[i+1][j-1];
				direction[i][j]=1;
			}
			else if(L[i+1][j]>=L[i][j-1])
			{
				L[i][j]=L[i+1][j];
				direction[i][j]=2;
			}
			else if(L[i+1][j]<L[i][j-1])
			{
				L[i][j]=L[i][j-1];
				direction[i][j]=0;
			}
		}
	}
	//print2d(L,n);
	printf("The Longest Palindromic subsequence is : ");
	printLPS(str,direction,n,0,n-1);
	printf("\n");
	//print2d(direction,n);
	answer=L[0][n-1];
	for(i=0;i<n;i++)
		free(L[i]);
	free(L);
	return answer;
}
int main()
{
	clock_t begin,end;
	FILE*f;
	int n,len;
	char str[MAX+1];
	//system("clear");
	//generateTestCases();
	f=fopen("tests.txt","r");
	fscanf(f,"%s",str);
	begin=clock();
	len=LPS(str,MAX);
	end=clock();
	printf("The length of longest palindromic subsequence is : %d\n",len);
	printf("Execution time : %f\n",(end-begin)/(float)CLOCKS_PER_SEC);
	return 0;
}
