#include<iostream>

// simple illustration of function template.
using namespace std;
template <typename T>
T m(T a,T b)
{
    return a>b?a:b;
}

int main()
{
    cout<<m(3,4)<<endl;
    cout<<m(3.5,4.9)<<endl;
    cout<<m('1','7')<<endl;
    return 0;
}
