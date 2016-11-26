#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define MOD 1000000007

int binomialCoeff(int n, int k)
{
    int C[2][k+1];
    for(int i=0;i<=k;i++)
    {
        C[0][i]=0;
        C[1][i]=0;
    }
    int i, j;
    // Caculate value of Binomial Coefficient in bottom up manner
    int flag=0;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            //cout<<i<<" "<<j<<endl;
            if (j == 0 || j == i)
                C[flag][j] = 1;
            else
                C[flag][j] = (C[flag^1][j-1] + C[flag^1][j])%MOD;
        }
        flag=flag^1;
    }
    return C[flag^1][k];
}


int main()
{
    cout<<binomialCoeff(1,7)<<endl;
    return 0;
}