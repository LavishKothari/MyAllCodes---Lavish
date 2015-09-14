#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 	for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    
    k = l;
    j = 0;
    i = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
	int t,answer,temp,i,count1,countOther,m,n,*arr;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		count1=countOther=0;
		arr=(int*)malloc(sizeof(int)*m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&arr[i]);
			temp=arr[i];
			if(temp==1)
				count1++;
			else countOther++;
		}
		//qsort(arr,m,sizeof(int),cmpfunc);
		mergeSort(arr,0,m-1);
		if(count1<countOther-1)
		{
			for(i=0;i<m;i++)
			{
				if(arr[i]==1)
					continue;
				else
				{
					if(count1+arr[i]>countOther-1)
					{
						count1=countOther-1;
						break;
					}
					else if(count1+arr[i]<countOther-2)
					{
						count1+=arr[i];
						countOther--;
					}
					else if(count1+arr[i]==countOther-2)
					{
						count1+=arr[i];
						countOther--;
					}
				}
			}
		}
		answer=0;
		if(count1==0)
		{
			answer=m-1;
		}
		else if(count1==m)
		{
			answer=m/2;
		}
		else if(count1<countOther)
		{
			answer+=countOther-1;
		}
		else if(count1>countOther)
		{
			answer+=m/2;
		}
		else answer=count1;
		printf("%d\n",answer);
		free(arr);
	}
}
