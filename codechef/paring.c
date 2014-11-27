#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,*x,*y,*answer,n,m,i,*isxnotfree;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);

        x=(int*)malloc(sizeof(int)*m);
        y=(int*)malloc(sizeof(int)*m);
        answer=(int*)calloc(m,sizeof(int));
        isxnotfree=(int*)calloc(n,sizeof(int));

        for(i=0;i<n;i++)
            isxnotfree[i]=0;
        for(i=0;i<m;i++)
            answer[i]=0;


        for(i=0;i<m;i++)
            scanf("%d%d",&x[i],&y[i]);
        answer[m-1]=1;
        isxnotfree[x[m-1]]=1;
        isxnotfree[y[m-1]]=1;

        for(i=m-2;i>=0;i--)
            if(isxnotfree[x[i]]==0 && isxnotfree[y[i]]==0)
                answer[i]=isxnotfree[x[i]]=isxnotfree[y[i]]=1;
        for(i=0;i<m;i++)
            if(answer[i])
                printf("%d ",i);
        printf("\n");
        free(x);
        free(y);
        free(answer);
        free(isxnotfree);

    }
    return 0;
}
