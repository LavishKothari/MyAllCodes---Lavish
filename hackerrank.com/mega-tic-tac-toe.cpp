#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void check(vector < vector <char> > &v, int n, int m, int k) {
    int x=0, o=0, i, j;
    for(i=0; i<n; i++) {
        int count=1;
        for(j=1; j<m; j++) {
            if(v[i][j] == v[i][j-1] && v[i][j] != '-')
                count++;
            else
                count = 1;
            if(count >= k) {
                if(v[i][j] == 'X')
                    x = 1;
                else
                    o=1;
            }
        }
    }
    //cout<<"a\n"<<endl;
    for(i=0; i<m; i++) {
        int count=1;
        for(j=1; j<n; j++) {
            if(v[j][i] == v[j-1][i] && v[j][i] != '-')
                count++;
            else
                count = 1;
            if(count >= k) {
                if(v[j][i] == 'X')
                    x = 1;
                else
                    o=1;
            }
        }
    }
    //cout<<"a\n"<<endl;
    
    for(int i=0;i<n;i++)
    {
        if(i+k>n)
            break;
        for(int j=0;j<m;j++)
        {
            if(j+k>m)
                break;
            int p,q;
            int count=1;
            //cout<<i<<" "<<j<<endl;
            for(p=i+1,q=j+1;p<n && q<m;p++,q++)
            {
                //cout<<x<<" "<<y<<endl;
                if(v[p][q]==v[p-1][q-1] && v[p][q]!='-')
                    count++;
                else
                    count=1;
                if(count>=k)
                {
                    if(v[p][q]=='X')
                        x=1;
                    else 
                        o=1;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i+k>n)
            continue;
        for(int j=0;j<m;j++)
        {
            if(j-k+1<0)
                continue;
            int p,q;
            int count=1;
            //cout<<i<<" "<<j<<endl;
            for(p=i+1,q=j-1;p<n && q>=0;p++,q--)
            {
                //cout<<p<<" "<<q<<endl;
                if(v[p][q]==v[p-1][q+1] && v[p][q]!='-')
                    count++;
                else
                    count=1;
                //cout<<"this is count = "<<count<<endl;
                if(count>=k)
                {
                    //cout<<"going here"<<v[p][q]<<endl;
                    if(v[p][q]=='X')
                        x=1;
                    else 
                        o=1;
                }
            }
            //cout<<"$$$$$$$$$$$$$$$$$$"<<endl;
        }
    }
    //cout<<"x and o = "<<x<<" "<<o<<endl;
    if(x==1 && o==1)
        cout << "NONE" << endl;
    else if(o==1 )
        cout << "WIN" << endl;
    else if(x==1)
        cout << "LOSE" << endl;
    else
        cout <<"NONE"<<endl;
    
    
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int g;
    cin >> g;
    while(g--) {
        int n, m, k;
        cin >>n>>m>>k;
        vector < vector <char> > v(n, vector<char> (m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> v[i][j];
            
         check(v,n, m, k);
    }
    return 0;
}
