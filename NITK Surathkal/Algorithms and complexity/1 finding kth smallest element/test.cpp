/*
	this program generates the test cases for median of median Algorithm
*/
#include"header.h"
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#define MAX_N 5000000
int*arr;
int main1()
{
	int counter,i,d;
	FILE*fp;
	arr=(int*)malloc(sizeof(int)*(MAX_N+1));
	fp=fopen("./test.txt","w");
	srand(time (NULL));
	for(i=0;i<MAX_N+1;i++)
		arr[i]=0;
	counter=0;
	fprintf(fp,"%d\n",MAX_N);
	while(counter!=MAX_N)
	{
		d=random()%MAX_N+1;
		if(arr[d]==0)
		{
			counter++;
			fprintf(fp,"%d\n",d);
			arr[d]=1;
		}
	}
	fclose(fp);	
	return 0;
}
