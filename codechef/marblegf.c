#include<stdio.h>
#include<stdlib.h>

int *val,*Index;
int *arr,n;
int *Sum,*answer;

int main()
{
	int q,a,x,b,i,counter=0,y,cval=0,ans;
	char ch;
	scanf("%d%d",&n,&q);	
	
	arr=(int*)malloc(sizeof(int)*n);
	Sum=(int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(i==0)
			Sum[i]=arr[i];
		else
			Sum[i]=Sum[i-1]+arr[i];
	}
	for(i=0;i<n;i++)
		printf("%d\t",Sum[i]);
	printf("\n");
	for(i=0;i<q;i++)
	{
		scanf(" %c%d%d",&ch,&a,&b);
		switch (ch)
		{
			case 'S':
				for(x=0;x<n;x++)
					printf("%d\t",Sum[x]);
				counter++;
				ans=0;
				answer=(int*)realloc(answer,sizeof(int)*counter);
				for(x=0;x<cval;x++)
				{
					if(Index[x]>=a && Index[x]<=b)
						ans+=val[x];	
				}
				if(a==0)
					answer[counter-1]=Sum[b]+ans;	
				else
					answer[counter-1]=Sum[b]-Sum[a-1]+ans;
				break;
			case 'G':
				cval++;
				val=(int*)realloc(val,sizeof(int)*cval);
				Index=(int*)realloc(Index,sizeof(int)*cval);	
				val[cval-1]=b;
				Index[cval-1]=a;
				arr[a]+=b;
				break;
			case 'T':
				cval++;
				val=(int*)realloc(val,sizeof(int)*cval);
				Index=(int*)realloc(Index,sizeof(int)*cval);
				val[cval-1]=-b;
				Index[cval-1]=a;
				arr[a]-=b;
				break;
		}
	}
	for(i=0;i<counter;i++)
		printf("%d\n",answer[i]);
			
	return 0;
}
