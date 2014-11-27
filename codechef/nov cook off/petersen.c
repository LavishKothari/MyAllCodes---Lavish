#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int* find(char c1,char c2)
{
    int *r;
    r=(int*)malloc(sizeof(int)*2);
    if(c1==c2)
    {
        r[0]=-1;
        r[1]=-1;
        return r;
    }
    if(c1=='A' && c2=='B')
    {
        r[0]=0;
        r[1]=1;
        return r;
    }
    if(c1=='A' && c2=='E')
    {
        r[0]=0;
        r[1]=4;
        return r;
    }

    if(c1=='B' && c2=='A')
    {
        r[0]=1;
        r[1]=0;
        return r;
    }
    if(c1=='B' && c2=='C')
    {
        r[0]=1;
        r[1]=2;
        return r;
    }

    if(c1=='C' && c2=='B')
    {
        r[0]=2;
        r[1]=1;
        return r;
    }
    if(c1=='C' && c2=='D')
    {
        r[0]=2;
        r[1]=3;
        return r;
    }

    if(c1=='D' && c2=='C')
    {
        r[0]=3;
        r[1]=2;
        return r;
    }
    if(c1=='D' && c2=='E')
    {
        r[0]=3;
        r[1]=4;
        return r;
    }

    if(c1=='E' && c2=='A')
    {
        r[0]=4;
        r[1]=0;
        return r;
    }

    if(c1=='E' && c2=='D')
    {
        r[0]=4;
        r[1]=3;
        return r;
    }
    /**************/

    if(c1=='A' && c2=='C')
    {
        r[0]=5;
        r[1]=7;
        return r;
    }
    if(c1=='A' && c2=='D')
    {
        r[0]=5;
        r[1]=8;
        return r;
    }

    if(c1=='B' && c2=='D')
    {
        r[0]=6;
        r[1]=8;
        return r;
    }
    if(c1=='B' && c2=='E')
    {
        r[0]=6;
        r[1]=9;
        return r;
    }

    if(c1=='C' && c2=='A')
    {
        r[0]=7;
        r[1]=5;
        return r;
    }
    if(c1=='C' && c2=='E')
    {
        r[0]=7;
        r[1]=9;
        return r;
    }

    if(c1=='D' && c2=='A')
    {
        r[0]=8;
        r[1]=5;
        return r;
    }

    if(c1=='D' && c2=='B')
    {
        r[0]=8;
        r[1]=6;
        return r;
    }

    if(c1=='E' && c2=='B')
    {
        r[0]=9;
        r[1]=6;
        return r;
    }

    if(c1=='E' && c2=='C')
    {
        r[0]=9;
        r[1]=7;
        return r;
    }

    r[0]=-2;
    r[1]=-2;
    return r;
}
char findChar(int n)
{
    if(n==0)
        return 'A';
    if(n==1)
        return 'B';
    if(n==2)
        return 'C';
    if(n==3)
        return 'D';
    if(n==4)
        return 'E';
    if(n==5)
        return 'A';
    if(n==6)
        return 'B';
    if(n==7)
        return 'C';
    if(n==8)
        return 'D';
    if(n==9)
        return 'E';

}
int findNum(char ch)
{
    if(ch=='A')
        return 0;
    if(ch=='B')
        return 1;
    if(ch=='C')
        return 2;
    if(ch=='D')
        return 3;
    if(ch=='E')
        return 4;

}
void printWalk(char*str)
{
    int *r,i,j,counter,flag,temp=0,len,*answer,index=0;
    len=strlen(str);
    answer=(int*)malloc(sizeof(int)*len);
    for(i=0;str[i]&&str[i+1];i++)
    {
        counter=0;
        r=find(str[i],str[i+1]);
        if(r[0]==-2 && r[1]==-2)
        {
            printf("-1\n");
            return ;
        }
        if(r[0]!=-1 && r[1]!=-1)
        {
            answer[index++]=r[0];
            temp=r[0];
            continue;
        }
        while(r[0]==-1 && r[1]==-1 && str[i+1] && str[i])
        {
            counter++;
            i++;
            if(str[i]&&str[i+1])
            {
                r=find(str[i],str[i+1]);
                if(r[0]==-2 && r[1]==-2)
                {
                    printf("-1\n");
                    return ;
                }
            }
            else
            {
                // SOMETING TO BE DONE HERE
                flag=0;
                if(str[i-2])
                    flag=1;

                if(flag==1 && temp<5)
                {
                    for(j=0;j<=counter;j++)
                    {
                        if(j%2==0)
                        {
                            answer[index++]=findNum(str[i-1]);
                            temp=findNum(str[i-1]);
                        }
                        else
                        {
                            answer[index++]=findNum(str[i-1])+5;
                            temp=findNum(str[i-1])+5;
                        }
                    }
                }
                else
                {
                    for(j=0;j<=counter;j++)
                    {
                        if(j%2==0)
                        {
                            answer[index++]=findNum(str[i-1])+5;
                            temp=findNum(str[i-1])+5;
                        }
                        else
                        {
                            answer[index++]=findNum(str[i-1]);
                            temp=findNum(str[i-1]);
                        }
                    }
                }
                printf("\n");
                return;
            }
        }
        if(counter!=0)
        {
            if(counter%2==0)
            {
                for(j=0;j<=counter;j++)
                {
                    if(j%2==0)
                    {
                        answer[index++]=r[0];
                        temp=r[0];
                    }
                    else
                    {
                        temp=5+r[0];
                        answer[index++]=5+r[0];
                    }
                }
            }
            else if(counter%2!=0)
            {
                for(j=0;j<=counter;j++)
                {
                    if(j%2==0)
                    {
                        temp=5+r[0];
                        answer[index++]=5+r[0];
                    }
                    else
                    {
                        temp=r[0];
                        answer[index++]=r[0];
                    }
                }
            }
        }

    }
    answer[index++]=r[1];
    for(i=0;str[i];i++)
        printf("%d",answer[i]);
    printf("\n");
}
int main()
{
    int t;
    char str[100001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        printWalk(str);
    }
    return 0;
}
