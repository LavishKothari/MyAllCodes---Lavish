#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid,st,et,im;
    int isAlive;

};

struct request
{
    int pid,rt,mr;
};

void bubbleSortForProcessArray(struct process*pArray,int numberOfProcesses)
{
    int i,j;
    struct process temp;
    for(i=1;i<numberOfProcesses;i++)
    {
        for(j=0;j<numberOfProcesses-i;j++)
        {
            if(pArray[j].st>pArray[j+1].st)
            {
                temp=pArray[j];
                pArray[j]=pArray[j+1];
                pArray[j+1]=temp;
            }
        }
    }
}

void bubbleSortIndexedForRequestArray(struct request*rArray,int a,int b) // sorting subArray from arr[a] to arr[b]
{
    int i,j,n;
    struct request temp;
    n=b-a+1; // number of elements to be sorted
    for(i=0;i<n-1;i++)
    {
        for(j=a;j<b-i;j++)
        {
            if(rArray[j].pid>rArray[j+1].pid)
            {
                temp=rArray[j];
                rArray[j]=rArray[j+1];
                rArray[j+1]=temp;
            }
        }
    }
}

void bubbleSortForRequestArray(struct request*rArray,int numberOfRequests)
{
    // sorting the request Array according to the request time of each request.
    int i,j,ci;
    struct request temp;
    for(i=1;i<numberOfRequests;i++)
    {
        for(j=0;j<numberOfRequests-i;j++)
        {
            if(rArray[j].rt>rArray[j+1].rt)
            {
                temp=rArray[j];
                rArray[j]=rArray[j+1];
                rArray[j+1]=temp;
            }
        }
    }
    // now here we need to all the individual bunches of request array that have same request time
    for(i=0;i<numberOfRequests;i++)
    {
        ci=i;
        while(rArray[i].rt==rArray[i+1].rt && i+1<numberOfRequests)
            i++;
        if(i==numberOfRequests)
            i--;
        bubbleSortIndexedForRequestArray(rArray,ci,i);
        i=ci;
    }
}

void printProcessList(struct process*pArray,int numberOfProcesses)
{
    int i;
    printf("The process list is as follows : \n");
    for(i=0;i<numberOfProcesses;i++)
        printf("%d %d %d %d\n",pArray[i].pid,pArray[i].st,pArray[i].et,pArray[i].im);
}

void printRequestList(struct request*rArray,int numberOfProcesses)
{
    int i;
    printf("The request array is as follows : \n");
    for(i=0;i<numberOfProcesses;i++)
        printf("%d %d %d\n",rArray[i].pid,rArray[i].rt,rArray[i].mr);
}

int searchContiguousSmallest(int *memoryArray,int memory,int leastMemory) // searches contiguous smallest and sufficient.
{
    int blockSize=2147483647,minBlockSize=2147483647,flag=0,minStartingIndex=-1,startingIndex,is1present=0,i,exitFlag=0;
    for(i=0;i<memory;i++)
    {
        if(memoryArray[i])
        {
            is1present=1;
            flag=0;
            if(blockSize<minBlockSize && blockSize>=leastMemory)
            {
                minBlockSize=blockSize;
                minStartingIndex=startingIndex;
            }
            exitFlag=0;
        }
        else
        {
            if(flag==0)
            {
                blockSize=0;
                startingIndex=i;
                flag=1;
            }
            blockSize++;
            exitFlag=1;
        }
    }
    if(exitFlag==1)
    {
        if(blockSize<minBlockSize && blockSize>=leastMemory)
        {
            minBlockSize=blockSize;
            minStartingIndex=startingIndex;
        }
    }
    if(is1present)
        return minStartingIndex; // if not possible to allocate the memory return -1
    else if(blockSize>=leastMemory)
        return 0;
    else return -1; // if not possible to allocate the memory return -1
}

void terminateProcess(int processId,int *memoryArray,int *occupyingProcess,int memory)
{
    int i;

    for(i=0;i<memory;i++)
    {
        if(occupyingProcess[i]==processId)
            memoryArray[i]=0; // free
    }
    for(i=0;i<memory;i++)
    {
        if(occupyingProcess[i]==processId)
            occupyingProcess[i]=-1;
    }
}

int getProcessIndexByPID(int pid,struct process*pArray,int numberOfProcesses)
{
    int i;
    for(i=0;i<numberOfProcesses;i++)
    {
        if(pArray[i].pid==pid)
            return i;
    }
    return -1; // if no such process with pid exists
}

int findAnswer(struct process*pArray,int numberOfProcesses,struct request*rArray,int numberOfRequests,int memory,int maxEndingTime,int minStartingTime)
{
    int currentTime,index,blockSize,answer=0,requestIndex;
    int i,j;
    int *memoryArray,*occupyingProcess;
    memoryArray=(int*)malloc(sizeof(int)*memory);
    for(i=0;i<memory;i++)
        memoryArray[i]=0; // means at the starting the memory is not occupied by any process
    occupyingProcess=(int*)malloc(sizeof(int)*memory);
    for(i=0;i<memory;i++)
        occupyingProcess[i]=-1; // means at the starting the memory is not occupied by any process

    for(currentTime=minStartingTime;currentTime<=maxEndingTime;currentTime++)
    {
        printf("\n\nCurrent Time = %d\n",currentTime);

        for(i=0;i<numberOfProcesses;i++)
        {
            if(pArray[i].isAlive && pArray[i].et==currentTime) // process terminated due to ending time.
            {
                terminateProcess(pArray[i].pid,memoryArray,occupyingProcess,memory);
                pArray[i].isAlive=0;
                printf("terminating due to end of time ->> pid : %d\n",pArray[i].pid);
            }
        }
        for(i=0;i<numberOfProcesses;i++)
        {
            if(pArray[i].st==currentTime)
            {
                pArray[i].isAlive=1;
                index=searchContiguousSmallest(memoryArray,memory,pArray[i].im);
                if(index==-1) // process terminates as no sufficient memory is available
                {
                    // here the process needs to be terminated and increment answer
                    // for the termination of the process you need to free the resources allocated to it.
                    terminateProcess(pArray[i].pid,memoryArray,occupyingProcess,memory);
                    pArray[i].isAlive=0;
                    answer++;
                    printf("terminating by process due to lack of memory ->> pid : %d\n",pArray[i].pid);
                    continue;
                }
                printf("Request made by %d successful\n",pArray[i].pid);
                for(j=index;j<index+pArray[i].im;j++)
                {
                    memoryArray[j]=1;
                    occupyingProcess[j]=pArray[i].pid;
                }
            }
        }

        for(i=0;i<numberOfRequests;i++) // allcating the memory from the request Array
        {
            requestIndex=getProcessIndexByPID(rArray[i].pid,pArray,numberOfProcesses);
            if(rArray[i].rt==currentTime && pArray[requestIndex].isAlive==1 && pArray[requestIndex].et>currentTime)
            {
                index=searchContiguousSmallest(memoryArray,memory,rArray[i].mr);
                if(index==-1)
                {
                    // here the process needs to be terminated and increment answer
                    // for the termination of the process you need to free the resources allocated to it.
                    terminateProcess(pArray[requestIndex].pid,memoryArray,occupyingProcess,memory);
                    pArray[requestIndex].isAlive=0;
                    printf("terminating by request due to lack of memory : %d\n",pArray[requestIndex].pid);
                    answer++;
                    continue;
                }
                printf("Request made by %d successful\n",pArray[requestIndex].pid);
                for(j=index;j<index+rArray[i].mr;j++)
                {
                    memoryArray[j]=1;
                    occupyingProcess[j]=pArray[j].pid;
                }
            }
        }
    }
    return answer;
}

int main()
{
    int n,i;
    struct process*pArray;
    struct request*rArray;
    int numberOfProcesses,numberOfRequests,maxEndingTime,minStartingTime;
    scanf("%d%d",&n,&numberOfProcesses);
    pArray=(struct process*)malloc(sizeof(struct process)*numberOfProcesses);
    maxEndingTime=0;
    minStartingTime=2147483647;
    for(i=0;i<numberOfProcesses;i++)
    {
        scanf("%d%d%d%d",&pArray[i].pid,&pArray[i].st,&pArray[i].et,&pArray[i].im);
        pArray[i].isAlive=0;
        if(maxEndingTime<pArray[i].et)
            maxEndingTime=pArray[i].et;
        if(minStartingTime>pArray[i].st)
            minStartingTime=pArray[i].st;
    }

    scanf("%d",&numberOfRequests);
    rArray=(struct request*)malloc(sizeof(struct process)*numberOfRequests);

    for(i=0;i<numberOfRequests;i++)
        scanf("%d%d%d",&rArray[i].pid,&rArray[i].rt,&rArray[i].mr);

    bubbleSortForProcessArray(pArray,numberOfProcesses);
    bubbleSortForRequestArray(rArray,numberOfRequests);

    //printProcessList(pArray,numberOfProcesses);
    //printRequestList(rArray,numberOfRequests);

    printf("Answer = %d",findAnswer(pArray,numberOfProcesses,rArray,numberOfRequests,n,maxEndingTime,minStartingTime));
    return 0;
}
