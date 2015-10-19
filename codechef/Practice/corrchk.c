#include<stdio.h>
long long int a,b,c;
void calculateABC(int);
long long int power(int,int);
char str[30];
int main()
{
    int t,flag=0,base,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        base = maxPossibleBase();
        //printf("base = %d\n",base);
        for(i=base;i<=16;i++)
        {
            calculateABC(i);
            //printf("%lld %lld %lld\n",a,b,c);
            if((a+b)==c)
            {
                flag++;
                break;
            }
        }
    }
    printf("%d",flag);

    return 0;
}
int maxPossibleBase()
{
    int i,j,max=0;
    for(i=0;str[i]!='+';i++);
    i--;
    for(j=i;j>=0;j--)
    {
        if(max==16)
            return max;
        if(str[j]=='f' && max<16)
            max=16;
        else if(str[j]=='e' && max<15)
            max=15;
        else if(str[j]=='d' && max<14)
            max=14;
        else if(str[j]=='c' && max<13)
            max=13;
        else if(str[j]=='b' && max<12)
            max=12;
        else if(str[j]=='a' && max<11)
            max=11;
        else if(str[j]=='9' && max<10)
            max=10;
        else if(str[j]=='8' && max<9)
            max=9;
        else if(str[j]=='7' && max<8)
            max=8;
        else if(str[j]=='6' && max<7)
            max=7;
        else if(str[j]=='5' && max<6)
            max=6;
        else if(str[j]=='4' && max<5)
            max=5;
        else if(str[j]=='3' && max<4)
            max=4;
        else if(str[j]=='2' && max<3)
            max=3;
        else if(str[j]=='1' && max<2)
            max=2;
    }

    for(i=0;str[i]!='=';i++);
    i--;
    for(j=i;str[j]!='+';j--)
    {
        if(max==16)
            return max;
        if(str[j]=='f' && max<16)
            max=16;
        else if(str[j]=='e' && max<15)
            max=15;
        else if(str[j]=='d' && max<14)
            max=14;
        else if(str[j]=='c' && max<13)
            max=13;
        else if(str[j]=='b' && max<12)
            max=12;
        else if(str[j]=='a' && max<11)
            max=11;
        else if(str[j]=='9' && max<10)
            max=10;
        else if(str[j]=='8' && max<9)
            max=9;
        else if(str[j]=='7' && max<8)
            max=8;
        else if(str[j]=='6' && max<7)
            max=7;
        else if(str[j]=='5' && max<6)
            max=6;
        else if(str[j]=='4' && max<5)
            max=5;
        else if(str[j]=='3' && max<4)
            max=4;
        else if(str[j]=='2' && max<3)
            max=3;
        else if(str[j]=='1' && max<2)
            max=2;
    }

    for(i=0;str[i];i++);
    i--;
    for(j=i;str[j]!='=';j--)
    {
        if(max==16)
            return max;
        if(str[j]=='f' && max<16)
            max=16;
        else if(str[j]=='e' && max<15)
            max=15;
        else if(str[j]=='d' && max<14)
            max=14;
        else if(str[j]=='c' && max<13)
            max=13;
        else if(str[j]=='b' && max<12)
            max=12;
        else if(str[j]=='a' && max<11)
            max=11;
        else if(str[j]=='9' && max<10)
            max=10;
        else if(str[j]=='8' && max<9)
            max=9;
        else if(str[j]=='7' && max<8)
            max=8;
        else if(str[j]=='6' && max<7)
            max=7;
        else if(str[j]=='5' && max<6)
            max=6;
        else if(str[j]=='4' && max<5)
            max=5;
        else if(str[j]=='3' && max<4)
            max=4;
        else if(str[j]=='2' && max<3)
            max=3;
        else if(str[j]=='1' && max<2)
            max=2;
    }

    return max;
}
void calculateABC(int base)
{
    int i,j,mul,counter;
    a=b=c=0;
    for(i=0;str[i]!='+';i++);
    i--;
    counter=0;
    for(j=i;j>=0;j--)
    {
        if(str[j]=='a')
            mul=10;
        else if(str[j]=='b')
            mul=11;
        else if(str[j]=='c')
            mul=12;
        else if(str[j]=='d')
            mul=13;
        else if(str[j]=='e')
            mul=14;
        else if(str[j]=='f')
            mul=15;
        else
            mul=(int)str[j]-48;


        a=a+mul*power(base,counter);
        counter++;
    }


    for(i=0;str[i]!='=';i++);
    i--;
    counter=0;
    for(j=i;str[j]!='+';j--)
    {
        if(str[j]=='a')
            mul=10;
        else if(str[j]=='b')
            mul=11;
        else if(str[j]=='c')
            mul=12;
        else if(str[j]=='d')
            mul=13;
        else if(str[j]=='e')
            mul=14;
        else if(str[j]=='f')
            mul=15;
        else
            mul=(int)str[j]-48;

        b=b+mul*power(base,counter);
        counter++;
    }


    for(i=0;str[i];i++);
    i--;
    counter=0;
    for(j=i;str[j]!='=';j--)
    {
        if(str[j]=='a')
            mul=10;
        else if(str[j]=='b')
            mul=11;
        else if(str[j]=='c')
            mul=12;
        else if(str[j]=='d')
            mul=13;
        else if(str[j]=='e')
            mul=14;
        else if(str[j]=='f')
            mul=15;
        else
            mul=(int)str[j]-48;

        c=c+mul*power(base,counter);
        counter++;
    }
}

long long int power(int base,int counter)
{
    int i;
    long long int pro=1;
    for(i=0;i<counter;i++)
    {
        pro=pro*base;
    }
    return pro;
}
