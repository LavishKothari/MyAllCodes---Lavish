/*
    PROGRAM TO DISPLAY MULTI POINT CROSSOVER USING BIT PATTERN AND ALSO USE THE GRAPHICAL REPRENTATIONS
*/

#include<stdio.h>

void printBitRepresentation(unsigned int parent, unsigned int crossOverPoint1,unsigned int crossOverPoint2)
{
    unsigned int num,i;
    num=1<<31;
    for(i=0;i<32;num>>=1,i++)
    {
        if(parent & num)
            printf("1");
        else
            printf("0");

        if(i==crossOverPoint1-1)
            printf(" | ");

        if(i==crossOverPoint2-1)
            printf(" | ");
    }
    printf("\n");
}
void printChildren(unsigned int parent1,unsigned int parent2,unsigned int crossOverPoint1,unsigned int crossOverPoint2)
{
    unsigned int num,i,a=0,b=0,c=0,d=0,e=0,f=0,child1,child2;
    num=1<<31;
    for(i=0;i<crossOverPoint1;num>>=1,i++)
    {
        if(parent1 & num)
            a+=num;
        if(parent2 & num)
            d+=num;
    }
    for(i=crossOverPoint1;i<crossOverPoint2;num>>=1,i++)
    {
        if(parent1 & num)
            b+=num;
        if(parent2 & num)
            e+=num;
    }
    for(i=crossOverPoint2;i<32;num>>=1,i++)
    {
        if(parent1 & num)
            c+=num;
        if(parent2 & num)
            f+=num;
    }
    child1=a+e+c;
    child2=d+b+f;
    printf("\n\nChild 1 = %u\n",child1);
    printf("Child 2 = %u\n",child2);

    printBitRepresentation(child1,crossOverPoint1,crossOverPoint2);
    printBitRepresentation(child2,crossOverPoint1,crossOverPoint2);

}
int main()
{
    unsigned int parent1,parent2,crossOverPoint1,crossOverPoint2;
    printf("Enter parent number 1 :");
    scanf("%d",&parent1);
    printf("Enter parent number 2 :");
    scanf("%d",&parent2);

    printf("Enter the Cross-Over point 1 [between 0 to 32]: \n");
    scanf("%d",&crossOverPoint1);
    printf("Enter the Cross-Over point 2 [between 0 to 32]: \n");
    scanf("%d",&crossOverPoint2);


    printf("\n\nBit representation for Parents is : \n");
    printBitRepresentation(parent1,crossOverPoint1,crossOverPoint2);
    printBitRepresentation(parent2,crossOverPoint1,crossOverPoint2);

    printChildren(parent1,parent2,crossOverPoint1,crossOverPoint2);
    return 0;
}
