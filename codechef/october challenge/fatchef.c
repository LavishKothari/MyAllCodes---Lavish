#include<stdio.h>

void heapsort(int arr[],char ch[], unsigned int N)
{
    int t; /* the temporary value */
    char tch;
    unsigned int n = N, parent = N/2, index, child; /* heap indexes */
    /* loop until array is sorted */
    while (1) {
        if (parent > 0) {
            /* first stage - Sorting the heap */
            parent--;
            t = arr[parent];  /* save old value to t */
            tch=ch[parent];
        } else {
            /* second stage - Extracting elements in-place */
            n--;                /* make the heap smaller */
            if (n == 0) {
                return; /* When the heap is empty, we are done */
            }
            t = arr[n];
            tch=ch[n];         /* save lost heap entry to temporary */
            arr[n] = arr[0];
            ch[n]=ch[0];    /* save root entry beyond heap */
        }
        /* insert operation - pushing t down the heap to replace the parent */
        index = parent; /* start at the parent index */
        child = index * 2 + 1; /* get its left child index */
        while (child < n) {
            /* choose the largest child */
            if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
                child++; /* right child exists and is bigger */
            }
            /* is the largest child larger than the entry? */
            if (arr[child] > t) {
                arr[index] = arr[child]; /* overwrite entry with child */
                ch[index]=ch[child];
                index = child; /* move index to the child */
                child = index * 2 + 1; /* get the left child and go around again */
            } else {
                break; /* t's place is found */
            }
        }
        /* store the temporary value at its new location */
        arr[index] = t;
        ch[index]=tch;
    }
}

int main()
{
    char *ch,x,prevx;
    int n,y,m,*arr,t,prevy,answer,i;
    scanf("%d",&t);
    while(t--)
    {
        answer=1;
        scanf("%d%d",&n,&m);
        ch=(char*)malloc(sizeof(char)*m);
        arr=(int*)malloc(sizeof(int)*m);

        for(i=0;i<m;i++)
        {
            scanf(" %c%d",&ch[i],&arr[i]);
        }
        heapsort(arr,ch,m);
        for(i=1;i<m;i++)
        {
            if(ch[i]==ch[i-1])
            {
                arr[i]=arr[i-1];
                continue;
            }
            answer=(answer*(arr[i]-arr[i-1]))%1000000009;
        }
        printf("%d\n",answer);
    }

}
