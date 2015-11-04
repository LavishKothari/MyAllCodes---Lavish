#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<map>
using namespace std;


struct Element
{
	int value,index;	
};
int cmpf(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
    int n;
    scanf("%d",&n);
    Element*arr=(Element*)malloc(sizeof(Element)*n);
    vector<int>odd;
    vector<int>even;
    
    int*finalArray;
    finalArray=(int*)malloc(sizeof(int)*n);
    int j,k;j=k=0;
    std::map<int,int>indices;
    for(int i=0;i<n;++i)
    {
    	int tempo;
        scanf("%d",&tempo);
        indices[tempo]=i;
        arr[i].value=tempo;
        arr[i].index=i;
        
        if(((arr[i].value)&1)==0)
        	even.push_back(arr[i].value);
        else
        	odd.push_back(arr[i].value);
    }
    std::sort(odd.begin(),odd.end());
    std::sort(even.begin(),even.end());
   	j=k=0;
    for(int i=0;i<n;++i)
    {
    	if((i&1)==0)
	    	finalArray[i]=odd[j++];
	    else finalArray[i]=even[k++];
	}
   
    int answer=0;
    for(int i=0;i<n;i++)
    {
    	//printf("%d\n",i);
    	if(finalArray[i]==arr[i].value)
    	{
    		// means element is in its correct position.
    		continue;
    	}
    	else
    	{
    		int ind=indices[finalArray[i]];
    		// swap arr[i].value and arr[ind].value
    		int temp;
    		temp=arr[i].value;
    		arr[i].value=arr[ind].value;
    		arr[ind].value=temp;
    		
    		//swap finalArray[arr[i].value] and finalArray[arr[ind].value]
    		temp=indices[arr[i].value];
    		indices[arr[i].value]=indices[arr[ind].value];
    		indices[arr[ind].value]=temp;
    		
    		answer++;
    	}	
    }
    printf("%d",answer);
    return 0;
}
