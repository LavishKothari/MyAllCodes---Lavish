#include<stdio.h>
#include<stdlib.h>
long long int **table;
struct Dish
{
	int rating,mincost;
};
struct Judge
{
	int L,R,C;
};
int cmpfunc(const void*a,const void*b)
{
	struct Judge x,y;
	x=*(struct Judge*)a;
	y=*(struct Judge*)b;
	return x.C-y.C;
}
long long int max(long long int x,long long int y)
{
	return x>y?x:y;
}
long long int findMax(const int k,int*weight,int*value,const int n)
{
	int i,j;
	long long int answer;
   	//long long int table[n+1][k+1];
   	table=(long long int**)malloc(sizeof(long long int*)*(n+1));
   	for(i=0;i<=n;i++)
   		table[i]=(long long int *)malloc(sizeof(long long int)*(k+1));
   	for (i=0;i<=n;i++)
   	{
   	    for(j=0;j<=k;j++)
      	{
           	if(i==0||j==0)
               	table[i][j]=0;
           	else if(weight[i-1]<=j)
        		table[i][j]=max(value[i-1]+table[i-1][j-weight[i-1]],table[i-1][j]);
           	else
                table[i][j]=table[i-1][j];
       	}
   	}
   	answer=table[n][k];
   	
   	for(i=0;i<=n;i++)
   		free(table[i]);
   	free(table);
   	
   	return answer;
}
int main()
{
	long long int sum;
	int*weight,*value;
	struct Judge*judges;
	struct Dish*dishes;
	int t,i,n,k,m,j,counter;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&m);
		dishes=(struct Dish*)malloc(sizeof(struct Dish)*n);
		judges=(struct Judge*)malloc(sizeof(struct Judge)*m);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&(dishes[i].rating));
			sum+=(dishes[i].rating);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&judges[i].L,&judges[i].R,&judges[i].C);
			(judges[i].R)--;
			(judges[i].L)--;
		}
		// input complete
		qsort(judges,m,sizeof(struct Judge),cmpfunc);
		
		for(i=0;i<n;i++)
		{
			if(dishes[i].rating<0)
			{	
				for(j=0;j<m;j++)
				{
					if(i>=judges[j].L && i<=judges[j].R)
					{
						dishes[i].mincost=judges[j].C;
						break;
					}
				}
				if(j==m)
				{
					dishes[i].mincost=k+1;
				}
			}
		}
		counter=0;
		for(i=0;i<n;i++)
		{
			if(dishes[i].rating<0)
				counter++;
		}
		weight=(int *)malloc(sizeof(int)*counter);
		value=(int *)malloc(sizeof(int)*counter);
		counter=0;
		for(i=0;i<n;i++)
		{
			if(dishes[i].rating<0)
			{
				weight[counter]=dishes[i].mincost;
				value[counter]=abs(dishes[i].rating);
				counter++;
				//printf("this is a check : %d %d\n",weight[counter],value[counter]);
			}
		}
		
		//printf("sum = %lld\n",sum);
		//printf("dp : %lld\n",findMax(k,weight,value,counter));
		//findMax(k,weight,value,counter);
		printf("%lld\n",sum+findMax(k,weight,value,counter));
		free(dishes);
		free(judges);
	}
	return 0;
}
