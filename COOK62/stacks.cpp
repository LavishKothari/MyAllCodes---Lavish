#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#define MAX 2147483647
using namespace std;
int main()
{
    int t,n,j,*arr,i,min,minj,anothermin,insertAt;
    vector<int>answer;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        answer.push_back(arr[0]);
        for(i=1;i<n;i++)
        {
            min=MAX;
            minj=-1;
            anothermin=MAX;
            insertAt=-1;
            for(j=0;j<answer.size();j++)
            {
                if(arr[i]>answer[j])
                {
                    //anothermin=answer[j];
                    insertAt=j;
                }
                if(answer[j]>arr[i] && min>answer[j])
                {
                    min=answer[j];
                    minj=j;
                    break;
                }
            }
            if(minj==-1)
            {
                //printf("pusing %d\n",arr[i]);
                answer.insert(answer.begin()+insertAt,arr[i]);
            }
            else
                answer[minj]=arr[i];
        }
        sort(answer.begin(),answer.end());
        printf("%d ",answer.size());
        for(i=0;i<answer.size();i++)
            printf("%d ",answer[i]);
        printf("\n");
        answer.clear();
    }
    return 0;
}
