//함수 템플릿
//overloading에서 타입만 다른 경우 이걸쓰면 존나게 판하다.
//타입을 자유롭게 할 수 있음
#include<iostream>
using namespace std;

/*
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
*/

/*
    class template ->class
    class -->object,instance;
*/




template <typename T>

class Box{
    private:
        T data;
    public:
        Box(){}
        Box(T _data):data(_data){}
        T getdata(){
            return data;
        }
        void setData(T _data){
            data=_data;
            }
            void show();
};
template <typename T>
void Box<T>::show()
{
    cout<<data<<endl;
}
class MyItem{
    private:
    int k;
    public:
    MyItem():k(99){}
    void showK(){
        cout<<k<<endl;
    }
};




template<typename T1,typename T2>
class Dbox{
    private:
  T1 data1;
  T2 data2;  
};
int main(){
    //1단계 int를 데이터로 갖는 class를 만든다.
    //2단계 만들어진 클래스 Box<int>로 부터 객체를 만든다.

    Dbox<string,int>db;
    Dbox<string,string>db2;
    Box<MyItem> my_box;
    MyItem i;
    my_box.setData(i);
    MyItem v=my_box.getdata();
    v.showK();
    

}
