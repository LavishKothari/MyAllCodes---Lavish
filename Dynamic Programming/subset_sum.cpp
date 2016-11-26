#include<bits/stdc++.h>
using namespace std;

// function to print the elements of subset that forms the given sum
void printSubset(int*arr,int n,int S,bool**table,int i,int j)
{
    if(i<=0 || j<=0)
        return;

    if(table[i][j-1]) // the jth element was not taken for sure.
    {
        printSubset(arr,n,S,table,i,j-1);
    }
    else // the jth element was taken for sure.
    {
        cout<<arr[j-1]<<" ";
        printSubset(arr,n,S,table,i-arr[j-1],j-1);
    }
}

bool isSubsetSum(int *arr,int n,int S)
{
    bool **table; // table of size S x n
    table=new bool*[S+1];
    for(int i=0;i<=S;i++)
        table[i]=new bool[n+1];

    // table[i][j] will be true if sum 'i' can be achieved using first j elements of the array.

    //base cases

    // from the first 0 elements you can never achieve any sum.
    for(int i=0;i<=S;i++)
        table[i][0]=false;
    // 0 sum can be achieved by any number of elements.
    for(int i=0;i<=n;i++)
        table[0][i]=true;

    for(int i=1;i<=S;i++)
        for(int j=1;j<=n;j++)
        {
            table[i][j]=table[i][j-1];
            if(!table[i][j] && i-arr[j-1]>=0)
                table[i][j]=table[i][j] || table[i-arr[j-1]][j-1];
        }

    bool answer=table[S][n];
    
    if(answer)
        printSubset(arr,n,S,table,S,n);
    for(int i=0;i<=S;i++)
        delete table[i];
    delete table;
    
    return answer;
}

bool isSubsetSumOptimized(int*arr,int n,int S)
{
    bool *table;
    table=new bool[S+1];
    table[0]=1;
    for(int i=0;i<n;i++)
        for(int j=S;j>=arr[i];j--)
            table[j]=table[j]||table[j-arr[i]];
    return table[S];
}
int main()
{
    int n;
    cout<<"Enter the number of elements of the array : ";
    cin>>n;
    int *arr;
    arr=new int[n];
    
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int S;
    cout<<"Enter the sum : ";
    cin>>S;
    cout<<endl<<isSubsetSum(arr,n,S)<<endl;;
    cout<<endl<<isSubsetSumOptimized(arr,n,S)<<endl;;
    return 0;
}