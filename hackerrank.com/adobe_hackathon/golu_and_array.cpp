#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;


class Element
{
	public :
	int value,index;
	Element(int,int);
	Element();
	void print();
};
void Element::print()
{
	printf("(%d,%d)\n",value,index);
}
Element::Element(){}
Element::Element(int value,int index)
{
	this->value=value;
	this->index=index;
}
struct less_than_key
{
    inline bool operator() (const Element* struct1, const Element* struct2)
    {
        return ((*struct1).value < (*struct2).value);
    }
};

int main()
{
    int n;
    scanf("%d",&n);
    vector<Element>arr;
    vector<Element*>odd;
    vector<Element*>even;
    vector<Element*>finalArray; 
    
    for(int i=0;i<n;++i)
    {
    	int tempo;
        scanf("%d",&tempo);
        arr.push_back(Element(tempo,i));
        if(((arr[i].value)&1)==0)
        	even.push_back(&(arr[i]));
        else odd.push_back(&(arr[i]));
    }
    std::sort(odd.begin(),odd.end(),less_than_key());
    std::sort(even.begin(),even.end(),less_than_key());
    
    int j,k;j=k=0;
    for(int i=0;i<n;++i)
    {
    	printf("************************%d,%d\n",arr[i].value,arr[i].index);
    	if((i&1)==0)
	    	finalArray.push_back(odd[j++]);
	    else finalArray.push_back(even[k++]);
	    printf("%d,%d\n",(*finalArray[i]).value,(*finalArray[i]).index);
   		
	}
	for(int i=0;i<finalArray.size();i++)
		printf("%d ",(*(finalArray[i])).value);
	printf("\n");
    
    /*
    int answer=0;
    for(int i=0;i<n;i++)
    {
    	int ind=finalArray[i].index;
    	if(finalArray[i].value==arr[i].value)
    	{
    		// means element is in its correct position.
    		continue;
    	}
    	else
    	{
    		printf("swapping these two elements\n");
    		arr[i].print();
    		arr[ind].print();
    		// swap arr[i] and arr[ind]
    		Element temp;
    		temp=arr[i];
    		arr[i]=arr[ind];
    		arr[ind]=temp;
    		answer++;
    		
    		// swap index
    		int t;
    		t=arr[i].index;
    		arr[i].index=arr[ind].index;
    		arr[ind].index=t;
    	}
    	
    }
    */
	//printf("%d\n",answer);
    return 0;
}
