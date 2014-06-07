#include<stdio.h>
#include<math.h>
int getLevel(int n)
{
    return ((int)log2(n));
}
int parent(int n)
{
    return ((int)(n/2));
}
int main()
{
    int n,i,j,a,b,levela,levelb,answer;
    scanf("%d",&n);
    while(n--)
    {
        answer=0;
        scanf("%d%d",&a,&b);
        levela=getLevel(a);
        levelb=getLevel(b);

        /*
        while(levela!=levelb)
        {
            if(levela>levelb)
            {
                answer++;
                levela--;
                a/=2;
            }
            else if(levela<levelb)
            {
                answer++;
                levelb--;
                b/=2;
            }
        }
        */

        answer+=abs(levela-levelb);
        if(levela>levelb)
        {
            a/=((int)pow(2,levela-levelb));
        }
        else if(levela<levelb)
        {
            b/=((int)pow(2,levelb-levela));
        }
        /**************/

        if(a==b)
        {
            printf("%d\n",answer);
            continue;
        }
        while(parent(a)!=parent(b))
        {
            answer+=2;
            a/=2;
            b/=2;
        }

        answer+=2;
        printf("%d\n",answer);

    }
    return 0;
}
