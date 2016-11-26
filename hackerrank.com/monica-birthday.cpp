#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
int **mat;
int n,c1,c2, count1=0, count2=0;

int table[1010] = {0};

int findTable(int no) {

	int max = 0, index;
	
	for(i=0; i<no; i++) {
		if(mat[i][no] > max) {
			max = mat[i][no];
			index = i;
		}
	} 
	
	if(table[index] == 1)
		return 2;
	else
		return 1;

}


void findanswer() {

	int t;
	for(i=1; i<n; i++) {
		t = findTable(i);
		if(t==1 && count1 <= c1) {
			table[i] = 1;
			count1++;
		}
		else {
			table[i] = 2;
			count2++;
		}
	}
}


int main()
{
    scanf("%d%d%d",&n,&c1,&c2);
    mat=new int*[n];
    for(int i=0;i<n;i++)
    	mat[i]=new int[n];
    
    for(int i=0;i<n ;i++) {
    	for(int j=0;j<n;j++)
    	{
    		scanf("%d",&mat[i][j]);
    	}
	}
	
	table[0] = 1;
	count1++;
	
	
	findAnswer();
 
	
 
 
	 
    printf("%d\n",count1);
    
    for(i=0; i<n; i++) {
    	if(table[i] == 1)
    		printf("%d ",i+1;
    }
    printf("\n");
    
    }
   
   /* 
    for(int i=0; i<c1; i++)
    	printf("%d ",i+1);
    printf("\n");
    */
    
    return 0;
}

