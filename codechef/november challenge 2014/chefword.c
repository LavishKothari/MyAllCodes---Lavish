#include<stdio.h>

int main()
{
    int t;
    double p[26][26];
    char originalWord[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        scanf("%s",originalWord);
        for(i=0;i<26;i++)
            for(j=0;j<26;j++)
                scanf("%lf",&p[i][j]);

    }
    return 0;
}
