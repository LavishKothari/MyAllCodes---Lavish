#include<stdio.h>
#include<stdlib.h>

void bubble_sort(float *,int *,int *, int );

int main()
{
    int t,n,k,i,*cost,*weight,current_weight,current_cost,current_counter;
    float *weightPerRupee;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        cost=(int*)malloc(sizeof(int)*n);
        weight=(int*)malloc(sizeof(int)*n);
        weightPerRupee=(float*)malloc(sizeof(float)*n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&cost[i],&weight[i]);
            weightPerRupee[i]=(float)weight[i]/cost[i];
        }

        bubble_sort(weightPerRupee,weight,cost,n);

        current_cost=0;
        current_weight=0;
        current_counter=n-1;
        while(current_counter>=0)
        {
            if(k-current_cost>=cost[current_counter])
            {
                current_weight+=weight[current_counter];
                current_cost+=cost[current_counter];
            }
            current_counter--;
        }
        free(cost);
        free(weight);
        printf("%d\n",current_weight);

    }
    return 0;

}

void bubble_sort(float*arr,int* arrr,int *arrrr, int n)
{
 int i,j,tmp,flag=0;
 for(i=0;i<n;i++)
 {
  flag=0;
  for(j=0;j<n-i-1;j++)
  {
   if(arr[j]>arr[j+1])
   {
    flag=1;
    tmp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=tmp;

    tmp=arrr[j];
    arrr[j]=arrr[j+1];
    arrr[j+1]=tmp;

    tmp=arrrr[j];
    arrrr[j]=arrrr[j+1];
    arrrr[j+1]=tmp;
   }
  }
  if(flag==0)
   break;
 }
}
