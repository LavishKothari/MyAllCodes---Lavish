#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdlib.h>
using namespace std;
#define MAX 10000000
bitset<MAX+1>isPrime;

void getPrimes()
{
    isPrime.reset();
    isPrime.flip();
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<=MAX;i++)
        if(isPrime[i])
            for(int j=i*i;j<=MAX;j+=i)
                isPrime[j]=0;
}

int**getUlamSpiral(int N)
{
    int **M;
    M=new int*[2*N+1];
    for(int i=0;i<2*N+1;i++)
        M[i]=new int[2*N+1];

    int r,c,current,counter;
    
    M[N][N]=1;
    r=N;
    c=N+1;
    counter=2;
    current=2;

    for(int j=0;j<N;j++,counter+=2)
    {
        for(int i=0;i<counter;i++)
            M[r--][c]=current++;
        r++;
        c--;
        for(int i=0;i<counter;i++)
            M[r][c--]=current++;
        c++;
        r++;
        for(int i=0;i<counter;i++)
            M[r++][c]=current++;
        r--;
        c++;
        for(int i=0;i<counter;i++)
            M[r][c++]=current++;
    }

    return M;
}
void printUlamSpiral(int **M,int N)
{
    for(int i=0;i<2*N+1;i++)
    {
        for(int j=0;j<2*N+1;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
}
int**filterPrimes(int**M,int N)
{
    int **M01;
    M01=new int*[2*N+1];
    for(int i=0;i<2*N+1;i++)
        M01[i]=new int[2*N+1];

    for(int i=0;i<1+2*N;i++)
    {
        for(int j=0;j<1+2*N;j++)
        {
            if(isPrime[M[i][j]])
                M01[i][j]=1;
            else M01[i][j]=0;
        }
    }
    return M01;
}
void writeToFile(string fileName,int**M,int N)
{
    FILE*fp;
    fp=fopen(fileName.c_str(),"w");
    if(fp)
    {
        fprintf(fp,"%d\n",N);
        for(int i=0;i<1+2*N;i++)
        {
            for(int j=0;j<1+2*N;j++)
            {
                fprintf(fp,"%d ",M[i][j]);
            }
            fprintf(fp,"\n");
        }
    }
    else cout<<"there is an error in opening the file\n";
}
int**fillRandom(int N)
{
    int **m;
    m=(int**)malloc(sizeof(int*)*(2*N+1));
    for(int i=0;i<2*N+1;i++)
        m[i]=(int*)malloc(sizeof(int)*(2*N+1));
    srand(time(NULL));
    for(int i=0;i<2*N+1;i++)
        for(int j=0;j<2*N+1;j++)
            m[i][j]=rand()%2;
    return m;
}
int main()
{
    int N;
    getPrimes();
    cin>>N;
    int **M=getUlamSpiral(N);
    //printUlamSpiral(M,N);
    int **M01=filterPrimes(M,N);
    int**R01=fillRandom(N);
    writeToFile("ulam.txt",M01,N);
    writeToFile("random.txt",R01,N);
    return 0;
}
