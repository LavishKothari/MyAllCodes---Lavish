    #include<stdio.h>
    int main()
    {
    int t,arr[256],i,cost;
    char s[201];

	scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<256;i++)
        arr[i]=0;
        scanf("%s",s);
        i=0;
        while(s[i])
        {
            arr[s[i]]++;
            i++;
        }
        cost = 0;
        for(i='A';i<='z';i++)
            if(arr[i]%2==0)
                cost += arr[i]/2 + 1;
            else
                cost += arr[i]/2;
        printf("%d\n",cost);
    }
    return 0;
    }
