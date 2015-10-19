#include<stdio.h>
int main()
{
    int t,n,i,flag;
    /*
        flag = 1 for indian
        flag = 2 for Not indian
        flag = 3 for not sure
    */
    char arr[1001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",arr);
        flag=3;
        for(i=0;i<n;i++)
        {
            if(arr[i]=='I')
            {
                flag=1;break;
            }
            else if(arr[i]=='Y')
            {
                flag=2;break;
            }
        }
        if(flag==1)
            printf("INDIAN\n");
        else if(flag==2)
            printf("NOT INDIAN\n");
        else
            printf("NOT SURE\n");
    }
}
