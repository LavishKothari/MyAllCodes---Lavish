#include<stdio.h>
long long int a,b,c;
void calculateABC(int);
long long int power(int,int);
char str[30];
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
int main()
{
    scanf("%s",str);
    calculateABC(16);
    printf("%lld %lld %lld\n",a,b,c);
    return 0;
}
