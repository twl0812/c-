#include<iostream>
using namespace std;
// 순수 가상함수
//pure virtual (function) 아무것도 없어야함 
// 
// pure virtual method를 가진 클래스를 특별히 abstract class(추상클래스)라고 하고
// abstract class로 부터는 객체를 만들어내지 못한다. 
//

//Java의 interface 개념
//c++는 abstract class (virtual function)을 이용하여 interface 구현
//
//interface: 클래스가 반드시 구현해야 할 메소드들의 목록
class A{
    public:
    virtual void show()=0; //순수한 가상함수 
};
class B:public A{
    public:
    void show(){
        cout<<"B"<<endl;
    }
};
class C:public A{
    public:
    void show(){
        cout<<"C"<<endl;
    }
};
class shape{
    public:
    virtual double getArea()=0;
};
class Triangle:public shape{
    private:
    int width,height;
    public:
    Triangle(int w,int h): width(w),height(h){}
    double getArea(){
        return (double)(0.5*width*height);
    }
};
class Circle:public shape{
    private:
    double r;
    public:
    Circle(double _r):r(_r){}
    double getArea(){
        return (double)(3.14*r*r);
    }
};
class Rect:public shape{
     private:
    int width,height;
    public:
    Rect(int w,int h): width(w),height(h){}
    double getArea(){
        return (double)(width*height);
    }
};
int main1()
{
    Triangle t(10,10);
    Circle c(10.0);
    Rect r(10,10);
    shape* s[3];
    s[0]=&t; //upcasting
    s[1]=&c;
    s[2]=&r;
    for(int i=0;i<3;i++)
    {
      cout<<s[i]->getArea()<<endl;
    }
    return 0;
}
