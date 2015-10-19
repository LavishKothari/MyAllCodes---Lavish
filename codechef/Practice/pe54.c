#include<stdio.h>
int winner(char*,char*);
int isRoyalFlush(char*);
int main()
{
    char ch,str1[14],str2[14];
    FILE*fptr;
    int i,answer=0;
    if(fptr=fopen("pe54.txt","r"))
    {
        while(!feof(fptr))
        {
            for(i=0;i<14;i++)
                fscanf(fptr,"%c",&str1[i]);
            fscanf(fptr,"%c",&ch);
            for(i=0;i<14;i++)
                fscanf(fptr,"%c",&str2[i]);
            answer+=winner(str1,str2);
        }
        printf("answer = %d\n",answer);
    }
    else
        printf("there was an error in opening the file...");
    return 0;
}
int winner(char*str1,char*str2)
{
    // returns 1 if player1 wins
    // returns 0 if player2 wins
    if(isRoyalFlush(str1) && isRoyalFlush(str2))
        checkForRoyalFlush(str1,str2);
    if(isStraightFlush(str1) && isStraightFlush(str2))
        checkForStraightFlush(str1,str2);
    if(isFourOfAKind(str1) && isFourOfAKind(str2))
        checkForFourOfAKind(str1,str2);
    if(isFullHouse(str1) && isFullHouse(str2))
        checkForFullHouse(str1,str2);
    if(isFlush(str1) && isFlush(str2))
        checkForFlush(str1,str2);
    if(isStraight(str1) && isStraight(str2))
        checkForStraight(str1,str2);
    if(isStraight(str1) && isStraight(str2))
        checkForStraight(str1,str2);
    if(isThreeOfAKind(str1) && isThreeOfAKind(str2))
        checkForThreeOfAKind(str1,str2);
    if(isTwoPairs(str1) && isTwoPairs(str2))
        checkForTwoPairs(str1,str2)
    if(isOnePair(str1) && isOnePair(str2))
        checkForOnePair(str1,str2)

}
int isSame(char*str,int a,int b,int c,int d,int e,char p,char q,char r,char s char t)
{
    if(str[a]==p || str[a]==q || str[a]==r || str[a]==s || str[a]==t)
        if(str[b]==p || str[b]==q || str[b]==r || str[b]==s || str[b]==t)
            if(str[c]==p || str[c]==q || str[c]==r || str[c]==s || str[c]==t)
                if(str[d]==p || str[d]==q || str[d]==r || str[d]==s || str[d]==t)
                    if(str[e]==p || str[e]==q || str[e]==r || str[e]==s || str[e]==t)
                        return 1;
    return 0;

}
int isRoyalFlush(char*str)
{
    if(isSame(str,0,3,6,9,12,'T','J','Q','K','A'))
        if(str[1]==str[4] && str[7]==str[4] && str[7]==str[10] && str[10]==str[13])
            return 1;
    return 0;
}
int isStraightFlush(char*str)
{
    if(str[1]==str[4] && str[7]==str[4] && str[7]==str[10] && str[10]==str[13])
        if(isSame(str,0,3,6,9,12,'2','3','4','5','6'))
            if(isSame(str,0,3,6,9,12,'3','4','5','6','7'))
                if(isSame(str,0,3,6,9,12,'4','5','6','7','8'))
                    if(isSame(str,0,3,6,9,12,'5','6','7','8','9'))
                        if(isSame(str,0,3,6,9,12,'6','7','8','9','T'))
                            if(isSame(str,0,3,6,9,12,'7','8','9','T','J'))
                                if(isSame(str,0,3,6,9,12,'8','9','T','J','Q'))
                                    if(isSame(str,0,3,6,9,12,'9','T','J','Q','K'))
                                        if(isSame(str,0,3,6,9,12,'T','J','Q','K','A'))
                                            return 1;
    return 0;
}
int isFourOfAKind(char*str)
{
    if(str[0]==str[3] && str[3]==str[6] && str[6]==str[9] && str[9]!=str[12])
        return 1;
    if(str[12]==str[3] && str[3]==str[6] && str[6]==str[9] && str[9]!=str[0])
        return 1;
    if(str[12]==str[6] && str[9]==str[6] && str[0]==str[9] && str[9]!=str[3])
        return 1;
    if(str[12]==str[3] && str[3]==str[9] && str[3]==str[9] && str[9]!=str[6])
        return 1;
    if(str[12]==str[3] && str[3]==str[6] && str[6]==str[0] && str[9]!=str[0])
        return 1;
    return 0;
}
int isFullHouse(char*str)
{
    if(str[0]==str[3] && str[6]==str[9] && str[9]==str[12])
        return 1;
    if(str[0]==str[6] && str[3]==str[9] && str[9]==str[12])
        return 1;
    if(str[0]==str[9] && str[6]==str[3] && str[3]==str[12])
        return 1;
    if(str[0]==str[12] && str[6]==str[9] && str[9]==str[3])
        return 1;
    if(str[6]==str[3] && str[0]==str[9] && str[9]==str[12])
        return 1;
    if(str[9]==str[3] && str[6]==str[0] && str[0]==str[12])
        return 1;
    if(str[12]==str[3] && str[6]==str[9] && str[9]==str[0])
        return 1;
    if(str[6]==str[9] && str[0]==str[3] && str[3]==str[12])
        return 1;
    if(str[6]==str[12] && str[0]==str[9] && str[9]==str[3])
        return 1;
    if(str[12]==str[9] && str[6]==str[0] && str[0]==str[3])
        return 1;
    return 0;

}
int isFlush(char*str)
{
    if(str[1]==str[4] && str[7]==str[4] && str[7]==str[10] && str[10]==str[13])
        return 1;
}
int isStraight(char*str)
{
    if(isSame(str,0,3,6,9,12,'2','3','4','5','6'))
        if(isSame(str,0,3,6,9,12,'3','4','5','6','7'))
            if(isSame(str,0,3,6,9,12,'4','5','6','7','8'))
                if(isSame(str,0,3,6,9,12,'5','6','7','8','9'))
                    if(isSame(str,0,3,6,9,12,'6','7','8','9','T'))
                        if(isSame(str,0,3,6,9,12,'7','8','9','T','J'))
                            if(isSame(str,0,3,6,9,12,'8','9','T','J','Q'))
                                if(isSame(str,0,3,6,9,12,'9','T','J','Q','K'))
                                    if(isSame(str,0,3,6,9,12,'T','J','Q','K','A'))
                                        return 1;
    return 0;
}
int isThreeOfAKind(char*str)
{
    if(str[6]==str[9] && str[9]==str[12])
        return 1;
    if(str[3]==str[9] && str[9]==str[12])
        return 1;
    if(str[6]==str[3] && str[3]==str[12])
        return 1;
    if(str[6]==str[9] && str[9]==str[3])
        return 1;
    if(str[0]==str[9] && str[9]==str[12])
        return 1;
    if(str[6]==str[0] && str[0]==str[12])
        return 1;
    if(str[6]==str[9] && str[9]==str[0])
        return 1;
    if(str[0]==str[3] && str[3]==str[12])
        return 1;
    if(str[0]==str[9] && str[9]==str[3])
        return 1;
    if(str[6]==str[0] && str[0]==str[3])
        return 1;
    return 0;
}
int isTwoPairs(char*str)
{
    if(str[3]==str[6] && str[9]==str[12])
        return 0;
    if(str[3]==str[9] && str[6]==str[12])
        return 0;
    if(str[0]==str[6] && str[9]==str[12])
        return 0;
    if(str[0]==str[9] && str[6]==str[12])
        return 0;
    if(str[3]==str[0] && str[9]==str[12])
        return 0;
    if(str[3]==str[9] && str[0]==str[12])
        return 0;
    if(str[3]==str[6] && str[0]==str[12])
        return 0;
    if(str[3]==str[0] && str[6]==str[12])
        return 0;
    if(str[3]==str[6] && str[9]==str[0])
        return 0;
    if(str[3]==str[0] && str[9]==str[6])
        return 0;
}
int isOnePair(char*str)
{
    if(str[0]==str[3])
        return 1;
    if(str[0]==str[6])
        return 1;
    if(str[0]==str[9])
        return 1;
    if(str[0]==str[12])
        return 1;
    if(str[3]==str[6])
        return 1;
    if(str[3]==str[9])
        return 1;
    if(str[3]==str[12])
        return 1;
    if(str[6]==str[9])
        return 1;
    if(str[6]==str[12])
        return 1;
    if(str[9]==str[12])
        return 1;

}
