#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct person
{
	char name[33];
	int points;
};
int compare(const void*a,const void*b)
{
	struct person*p1,*p2;
	p1=(struct person*)a;
	p2=(struct person*)b;
	return strcmp(p1->name,p2->name);
}
int main()
{
	int n,i,j,index,max,flag,currentPoints;
	char*winner,name[33];
	int points;
	struct person*persons;
	scanf("%d",&n);
	persons=(struct person*)malloc(sizeof(struct person)*n);
	index=0;
	max=0;
	for(j=0;j<n;j++)
	{
		scanf(" %s%d",name,&points);
		flag=0;
		for(i=0;i<index;i++)
		{
		    if(strcmp(persons[i].name,name)==0)
		    {
		        flag=1;
		        persons[i].points=persons[i].points+points;
		        if(persons[i].points>max)
		        {
		            max=persons[i].points;
		            winner=persons[i].name;
		        }
		        break;
		    }
		}
		if(flag==0)
		{
		    strcpy(persons[index].name,name);
		    persons[index].points=points;
		    if(persons[index].points>max)
		    {
		        max=persons[index].points;
		        winner=persons[index].name;
		    }
		    index++;
		}
	}
	/*
	qsort(persons,n,sizeof(struct person),compare);
	
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",persons[i].name,persons[i].points);
	}
	max=0;
	for(i=0;i<n;i++)
	{
	    flag=0;
	    //printf("helllo lavish kothari\n");
	    currentPoints=persons[i].points;
		while(i+1<n && strcmp(persons[i].name,persons[i+1].name)==0)
		{
		    flag=1;
			currentPoints+=persons[i].points;
			i++;
		}
		if(flag==1)
		    i--;
		if(currentPoints>max)
		{
		    max=currentPoints;
		    winner=persons[i].name;
		}
	}
	*/
	printf("%s\n",winner);
	return 0;
}