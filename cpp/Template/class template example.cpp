#include<iostream>
using namespace std;
template <class T>
class NewClass
{
    public:
        T a;
        T b;
        T sum()
        {
            return a+b;
        }
};
int main()
{
    NewClass<double> obj;
    obj.a=2.8;
    obj.b=3.3;
    cout<<obj.sum();
    return 0;
}
