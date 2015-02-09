#include<stdio.h>
void sort(int *arr,char*suit)
{
    int i,j,n,flag,temp;
    n=5;
    for(i=1;i<n;i++)
    {
        flag=0;
        for(j=0;j<n-i;j++)
            if(arr[j]>arr[j+1])
            {
                flag=1;

                temp=arr[j];
                arr[j]=arr[j+1] ;
                arr[j+1]=temp;

                temp=suit[j];
                suit[j]=suit[j+1] ;
                suit[j+1]=temp;
            }
        if(flag==0)
            break;
    }
}
int inCaseOfTie(int*value1,int*value2)
{
    int i=4;
    while(value1[i]==value2[i])
        i--;
    if(value1[i]>value2[i])
        return 1;
    return 2;
}

int isSameSuit(char*suit)
{
    int i;
    for(i=0;i<4;i++)
        if(suit[i]!=suit[i+1])
            return 0;
    return 1;
}
int isRoyalFlush(int *value,char*suit)
{
    if(!isSameSuit(suit))
        return 0;
    if(value[0]==10 && value[0]==11 && value[0]==12 && value[0]==13 && value[0]==14)
        return 1;
    return 0;
}

int isStraightFlush(int *value,char*suit)
{
    if(!isSameSuit(suit))
        return 0;
    return isStraight(value,suit);
}

int isFourOfAKind(int *value)
{
    if(value[0]==value[1] && value[0]==value[2] && value[0]==value[3])
        return value[0];
    if(value[1]==value[2] && value[1]==value[3] && value[1]==value[4])
        return value[1];
    return 0;
}

int isThreeOfAKind(int *value)
{
    if(value[0]==value[1] && value[0]==value[2])
        return value[0];
    if(value[1]==value[2] && value[1]==value[3])
        return value[1];
    if(value[2]==value[3] && value[2]==value[4])
        return value[2];
    return 0;

}
int isTwoPairs(int*value)
{
    if(value[0]==value[1])
    {
        if(value[2]==value[3])
            return 123;
        if(value[3]==value[4])
            return 134;
    }
    if(value[1]==value[2] && value[3]==value[4])
        return 1234;
    return 0;
}

int isOnePair(int*value)
{
    if(value[0]==value[1])
        return value[0];
    if(value[1]==value[2])
        return value[1];
    if(value[2]==value[3])
        return value[2];
    if(value[3]==value[4])
        return value[3];
    return 0;
}
int isFullHouse(int *value)
{
    if(value[0]==value[1] && value[2]==value[3] &&  value[3]==value[4])
        return value[2];
    if(value[3]==value[4] && value[0]==value[1] &&  value[1]==value[2])
        return value[2];
    return 0;
}

int isFlush(char*suit)
{
    return isSameSuit(suit);
}

int isStraight(int *value)
{
    if(value[1]==value[0]+1 && value[2]==value[0]+2 && value[3]==value[0]+3 && value[4]==value[0]+4)
        return 1;
    return 0;
}
int whoWins(int*value1,char*suit1,int*value2,char*suit2)
{
    int player1pair1,player1pair2,player2pair1,player2pair2,a,b,c,d;
    if(isRoyalFlush(value1,suit1))
        return 1;
    if(isRoyalFlush(value2,suit2))
        return 2;

    if(isStraightFlush(value1,suit1) && !isStraightFlush(value2,suit2))
        return 1;
    if(!isStraightFlush(value1,suit1) && isStraightFlush(value2,suit2))
        return 2;
    if(isStraightFlush(value1,suit1) && isStraightFlush(value2,suit2))     // means both of the players are having a Straight Flush
        return inCaseOfTie(value1,value2);

    if(isFourOfAKind(value1) && !isFourOfAKind(value2))
        return 1;
    if(!isFourOfAKind(value1) && isFourOfAKind(value2))
        return 2;
    if(isFourOfAKind(value1) && isFourOfAKind(value2))
    {
        if(isFourOfAKind(value1)> isFourOfAKind(value2))
            return 1;
        if(isFourOfAKind(value1)< isFourOfAKind(value2))
            return 2;
        return inCaseOfTie(value1,value2);
    }

    if(isFullHouse(value1) && !isFullHouse(value2))
        return 1;
    if(!isFullHouse(value1) && isFullHouse(value2))
        return 2;
    if(isFullHouse(value1) && isFullHouse(value2))
    {
        if(isFullHouse(value1)> isFullHouse(value2))
            return 1;
        if(isFullHouse(value1)< isFullHouse(value2))
            return 2;
        return inCaseOfTie(value1,value2);
    }

    if(isFlush(suit1) && !isFlush(suit2))
        return 1;
    if(!isFlush(suit1) && isFlush(suit2))
        return 2;
    if(isFlush(suit1) && isFlush(suit2))
        return inCaseOfTie(value1,value2);

    if(isStraight(value1) && !isStraight(value2))
        return 1;
    if(!isStraight(value1) && isStraight(value2))
        return 2;
    if(isStraight(value1) && isStraight(value2))
        return inCaseOfTie(value1,value2);

    if(isThreeOfAKind(value1) && !isThreeOfAKind(value2))
        return 1;
    if(!isThreeOfAKind(value1) && isThreeOfAKind(value2))
        return 2;
    if(isThreeOfAKind(value1) && isThreeOfAKind(value2))
    {
        if(isThreeOfAKind(value1)> isThreeOfAKind(value2))
            return 1;
        if(isThreeOfAKind(value1)< isThreeOfAKind(value2))
            return 2;
        return inCaseOfTie(value1,value2);
    }

    if(isTwoPairs(value1) && !isTwoPairs(value2))
        return 1;
    if(!isTwoPairs(value1) && isTwoPairs(value2))
        return 2;
    if(isTwoPairs(value1) && isTwoPairs(value2))
    {
        player1pair1=value1[isTwoPairs(value1)%10];
        player1pair2=value1[(isTwoPairs(value1)/100)%10];
        player2pair1=value2[isTwoPairs(value2)%10];
        player2pair2=value2[(isTwoPairs(value2)/100)%10];
        a=(player1pair1>player1pair2?player1pair1:player1pair2);
        b=(player1pair1<player1pair2?player1pair1:player1pair2);
        c=(player2pair1>player2pair2?player2pair1:player2pair2);
        d=(player2pair1<player2pair2?player2pair1:player2pair2);
        if(a>c)
            return 1;
        else if (a<c)
            return 2;
        else if(b>d)
            return 1;
        else if (b<d)
            return 2;

        return inCaseOfTie(value1,value2);
    }

    if(isOnePair(value1) && !isOnePair(value2))
        return 1;
    if(!isOnePair(value1) && isOnePair(value2))
        return 2;
    if(isOnePair(value1) && isOnePair(value2))
    {
        if(isOnePair(value1)> isOnePair(value2))
            return 1;
        if(isOnePair(value1)< isOnePair(value2))
            return 2;
        return inCaseOfTie(value1,value2);
    }
    return inCaseOfTie(value1,value2);
}
void print(int*value,char *suit)
{
    int i;
    for(i=0;i<5;i++)
        printf("%d%c ",value[i],suit[i]);
    printf("\n");
}
int main()
{
    int n,i,j,answer=0;
    int value1[10],value2[10];
    char suit1[10],suit2[10],temp;
    FILE *f;
    n=1000;
    f=fopen("poker.txt","r");
    if(f)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++)
            {
                fscanf(f," %c%c",&temp,&suit1[j]);
                if(temp=='T')
                    value1[j]=10;
                else if(temp=='J')
                    value1[j]=11;
                else if(temp=='Q')
                    value1[j]=12;
                else if(temp=='K')
                    value1[j]=13;
                else if(temp=='A')
                    value1[j]=14;
                else
                    value1[j]=temp-48;
            }
            for(j=0;j<5;j++)
            {
                fscanf(f," %c%c",&temp,&suit2[j]);
                if(temp=='T')
                    value2[j]=10;
                else if(temp=='J')
                    value2[j]=11;
                else if(temp=='Q')
                    value2[j]=12;
                else if(temp=='K')
                    value2[j]=13;
                else if(temp=='A')
                    value2[j]=14;
                else
                    value2[j]=temp-48;
            }
            sort(value1,suit1);
            sort(value2,suit2);

            if(whoWins(value1,suit1,value2,suit2)==1)
                answer++;
        }
        printf("answer = %d",answer);
    }
    else
        printf("There was some error in opening the file\n");
    return 0;
}
