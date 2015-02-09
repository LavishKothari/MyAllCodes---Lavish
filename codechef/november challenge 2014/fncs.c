#include<stdio.h>
#include<stdlib.h>

long long int*makeT(long long int *arr,int n) // n is the length of the array.
{
    /* This function make the BIT */
    int i,j;
    long long int *answer;
    answer=(long long int *)malloc(sizeof(long long int)*(n+1));
    for(i=0;i<=n;i++)
        answer[i]=0;

    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;) // dont increment j in the for loop due to carelessness
        {
            answer[j]=answer[j]+arr[i];
            j=j+(j&(-j));
        }
    }
    return answer;
}

long long int GET(long long int *T,int i)
{
    /* GET (index) sums up A[1] → A[index]. */
    long long int s=0;
    while(i>0)
    {
        s+=T[i];
        i=i-(i&(-i));
    }
    return s;
}

void SET(long long int *T,int i,int v,int n)
{
    int j;
    /* n is the size of array T */
    /*The value at T[i] is increased by v*/
    /* SET (index,value) adds value units to A[index] */
    for(j=i;j<=n;)// dont increment j in the for loop due to carelessness
    {
        T[j]+=v;
        j=j+(j&(-j));
    }
}

int main()
{
    int i,temp,j;
    int n,*funarg1,*funarg2,q,a,b,c,**flag;
    long long int *fun,answer,change,*arrT,*funT,*arr;
    scanf("%d",&n);

    arr=(long long int*)malloc(sizeof(long long int)*(n+1));
    fun=(long long int*)malloc(sizeof(long long int)*(n+1));
    funarg1=(int*)malloc(sizeof(int)*(n+1));
    funarg2=(int*)malloc(sizeof(int)*(n+1));

    /* Taking the input of the original array */
    arr[0]=0; // for making the indexing start with 1
    for(i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    arrT=makeT(arr,n);
    funarg1[0]=funarg1[1]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&funarg1[i],&funarg2[i]);
        if(funarg1[i] > funarg2[i])
        {
            temp=funarg1[i];
            funarg1[i]=funarg2[i];
            funarg2[i]=temp;
        }
        fun[i]=GET(arrT,funarg2[i])-GET(arrT,funarg1[i])+arr[funarg1[i]];
    }
    funT=makeT(fun,n);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
        {
            change=c-arr[b];
            arr[b]=c;
            //SET(arrT,b,change,n);

            // updating the fun array
            for(i=1;i<=n;i++)
            {
                if(b>=funarg1[i] && b<=funarg2[i])
                {
                    fun[i]+=change;
                    SET(funT,i,change,n);
                }
            }
        }
        else if(a==2)
        {
            if(b>c)
            {
                temp=b;
                b=c;
                c=temp;
            }
            answer=GET(funT,c)-GET(funT,b)+fun[b];
            printf("%lld\n",answer);
        }
    }
    return 0;
}
