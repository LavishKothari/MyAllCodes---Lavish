#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,t,n,*counter,element,max,countMax;
    scanf("%d",&t);
    while(t--)
    {
        countMax=0;
        scanf("%d",&n);

        counter=(int*)calloc(10001,sizeof(int));

        while(n--)
        {
            scanf("%d",&element);
            counter[element]++;
        }

        for(i=0;i<10001;i++)
            if(countMax<counter[i])
            {
                countMax=counter[i];
                max=i;
            }
        printf("%d %d\n",max,countMax);
        free(counter);
    }
    return 0;
}
