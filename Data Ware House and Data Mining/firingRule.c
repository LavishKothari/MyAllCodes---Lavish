/*
TABLE SHOWN BELOW DISPLAY THE    INPUT DATA   AND CORESSPONDING OUT DATA
APPLY THE FIRING RULE TO ABTAIN THE CORRECT TABLE USING. WE HAVE THE (0 TOUGHT SET) AND (1-TOUGHT SET)

X1:       0      0        0        0       1      1      1      1
X2:       0      0        1        1       0      0      1      1
X3:       0      1        0        1       0      1      0      1

OUT:      0      0       0/1      0/1     0/1     1     0/1     1

*/

#include<stdio.h>
void print(int*arr,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n\n");
}
int main()
{
    int i,j,counter,maxMatch,oneCount,zeroCount,current_j;
    int x1[]={0,0,0,0,1,1,1,1};
    int x2[]={0,0,1,1,0,0,1,1};
    int x3[]={0,1,0,1,0,1,0,1};

    int out[]={0,0,-1,-1,-1,1,-1,1};
    int newOut[8];

    for(i=0;i<8;i++)
        newOut[i]=out[i];
    for(i=0;i<8;i++)
    {
        counter=0;
        maxMatch=0;
        if(out[i]==-1)
        {
            for(j=0;j<8;j++)
            {
                counter=0;
                if(out[j]!=-1 && j!=i)
                {
                    if(x1[j]==x1[i])
                        counter++;
                    if(x2[j]==x2[i])
                        counter++;
                    if(x3[j]==x3[i])
                        counter++;
                }
                if(counter>maxMatch)
                    maxMatch=counter;
            }
            zeroCount=0;
            oneCount=0;
            for(j=0;j<8;j++)
            {
                counter=0;
                if(out[j]!=-1 && j!=i)
                {
                    if(x1[j]==x1[i])
                        counter++;
                    if(x2[j]==x2[i])
                        counter++;
                    if(x3[j]==x3[i])
                        counter++;

                    if(counter==maxMatch)
                    {
                        if(out[j]==0)
                            zeroCount++;
                        else if(out[j]==1)
                            oneCount++;
                    }
                }
            }
            if(zeroCount>oneCount)
                newOut[i]=0;
            else if(zeroCount<oneCount)
                newOut[i]=1;
            else
                newOut[i]=-1;
        }
    }
    printf("x1 : \n");
    print(x1,8);

    printf("x2 : \n");
    print(x2,8);

    printf("x3 : \n");
    print(x3,8);

    printf("old out : \n");
    print(out,8);

    printf("new out : \n");
    print(newOut,8);

    return 0;
}
