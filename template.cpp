//함수 템플릿
//overloading에서 타입만 다른 경우 이걸쓰면 존나게 판하다.
//타입을 자유롭게 할 수 있음
#include<iostream>
using namespace std;

template<typename T>
T get_max(T x,T y)
{
    if(x>y) return x;
    return y;
}
int main()
{
    cout<<get_max(3.0,4.8)<<endl;
}