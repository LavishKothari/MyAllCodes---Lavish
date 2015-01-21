/*
    PROGRAM TO DISPLAY SINGLE POINT CROSSOVER USING BIT PATTERN AND ALSO USE THE GRAPHICAL REPRENTATIONS
*/

#include<stdio.h>

void printBitRepresentation(unsigned int parent, unsigned int crossOverPoint)
{
    unsigned int num,i;
    num=1<<31;
    for(i=0;i<32;num>>=1,i++)
    {
        if(parent & num)
            printf("1");
        else
            printf("0");

        if(i==crossOverPoint-1)
            printf(" | ");
    }
    printf("\n");
}
void printChildren(unsigned int parent1,unsigned int parent2,unsigned int crossOverPoint)
{
    unsigned int num,i,a=0,b=0,c=0,d=0,child1,child2,j;
    num=1<<31;
    for(i=0;i<crossOverPoint;num>>=1,i++)
    {
        if(parent1 & num)
            a+=num;
        if(parent2 & num)
            c+=num;
        if(i==crossOverPoint-1)
        {
            num>>=1;
            for(j=crossOverPoint;j<32;num>>=1,j++)
            {
                if(parent1 & num)
                    b+=num;
                if(parent2 & num)
                    d+=num;
            }
        }
    }

    child1=a+d;
    child2=c+b;
    printf("\n\nChild 1 = %u\n",child1);
    printf("Child 2 = %u\n",child2);

    printBitRepresentation(child1,crossOverPoint);
    printBitRepresentation(child2,crossOverPoint);
}
int main()
{
    unsigned int parent1,parent2,crossOverPoint;
    printf("Enter parent number 1 :");
    scanf("%u",&parent1);
    printf("Enter parent number 2 :");
    scanf("%u",&parent2);

    printf("Enter the Cross-Over point for single Point cross over [between 0 to 32]: \n");
    scanf("%d",&crossOverPoint);

    printf("\n\nBit representation for Parents is : \n");
    printBitRepresentation(parent1,crossOverPoint);
    printBitRepresentation(parent2,crossOverPoint);

    printChildren(parent1,parent2,crossOverPoint);
    return 0;
}
