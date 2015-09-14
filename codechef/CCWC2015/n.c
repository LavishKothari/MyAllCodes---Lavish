#include<stdio.h>
#include<math.h>
int fib(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( fib(n-1) + fib(n-2) );
} 

void main() {
    int q,sum=1,n,i,j;
    int a[100000],b[100000];

    scanf("%d",&q);
    if((0 < q) && (q < 100000)){
    for(i = 0; i < q; i++){
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }
    
    for(i =0; i<q; i++){
        for(j=a[i]; j<=b[i]; j++){
            n = fib(j);
            if(((n%4) != 2) && ((n%4) != 0))
                sum = sum*n;
        }
        printf("%d\n",(sum%4));

    }
    }


    


}
