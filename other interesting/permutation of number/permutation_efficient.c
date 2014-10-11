#include<stdio.h>
#include<stdlib.h>

void printPermutation(int n)
{
    long long int i,numberOfPermutations;
    int answer=0,*arr,len,newlen;
    len=countDigits(n);
    arr=formArray(n);
    bubbleSort(arr,0,len-1);
    for(i=0;i<len;i++)
        answer=answer*10+arr[i];
    n=answer;
    newlen=countDigits(n);
    numberOfPermutations=countNumberOfPermutations(n);
    if(len==newlen)
        for(i=0;i<numberOfPermutations;i++)
        {
            printf("%lld -> %d\n",(i+1),n);
            n=findNextPermutation(n);
        }
    else
    {
        for(i=0;i<findFactorial(newlen);i++)
        {
            printf("%lld -> %d\n",(i+1),n);
            n=findNextPermutation(n);
        }
    }
}
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    printPermutation(n);
    return 0;
}
