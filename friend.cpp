#include<iostream>
using namespace std;





// ==> <<,>> 연산자의 중복,operator overloading by friend 함수를 이용함
 
//  class Point{
//     private:
//     friend ostream& operator<<(ostream& os,Point& p);
//     friend istream& operator>>(istream& in,Point& p);
//     int x,y;
//     public:
//     Point(int _x,int _y):x(_x),y(_y){}

//     void showPoint(){
//         cout<<x<<" , "<<y<<endl;
//     }

//  };

//  ostream& operator<<(ostream& os,Point& p){ ////outputsream

//     os<<p.x<<" , "<<p.y<<endl;
//     return os; //꼭해주어야함
//  }

//  istream& operator>>(istream& in,Point& p)
//  {
//     in>>p.x>>p.y;
//     return in;
//  }
// int main()
// {
//     Point p(0,20);
//     cin>>p;
//     cout<<p<<p;
// }



//operator overloading은 기존의 연산자를 재정의 하는 것임
//
//새로운 연산자를 만들 수는 없다. => !!! ?!? ?* 이런거 정의는 불가능하다.




//상속,inheritance

//상속 ==>생산성을 위한 필수개념


//private는 상속이 안됌
//protected 상속에는 public 외부에는 private


//생성자는 부모부터 생성,소멸자는 자식부터 소멸



class A{
public:
    int a;
    int b;
    A(){
        a=10;
        b=20;
        cout<<"부모"<<endl;
    }
    A(int _a,int _b):a(_a),b(_b){
        cout<<"부모생성자2"<<endl;
    }
    ~A()
    {
        cout<<"부모아웃"<<endl;
    }
    void show(){
    cout<<a<<" , "<<b<<endl;
    }

};
class AA: public A{ //public은 그대로 상속을 받겠다는 의미
    //AA는 아무런 데이터가 없어도 A로부터 상속받은 a,b가 있다.
    public:
    int c;
    AA():A(21,31){
        cout<<"자식"<<endl;
    }
    ~AA()
    {
        cout<<"자식아웃"<<endl;
    }
void sum(){
    cout<<(a+b)<<endl;
    }
};

class AAA : public AA{

};
int main()
{
    AA aa;
    AAA aaa;
    aaa.sum();
    aaa.show();
    aaa.a=10;
    aaa.b=20;
    aa.show();
    aa.sum();
    cout<<aa.a<<" "<<aa.b<<endl;
}






//private:access specifier,접근지정자
//=>OOP의 중요한 개념인 information hiding(정보은닉)
//=> 정보은닉:객체내부의 private는 객체 내부의 함수를 통해서만 접근
//=>코드 security & safety를 위해서 중요
// ==>경고 이것은 보안을 무너뜨리는 행위이므로 반드시 꼭 필요할때만 사용한다.


// class A{
//     private:
//     int a;
//     public:
//     friend void show(A _a);
//     friend class B;
//     A(int _a):a(_a){}
//     void setA(int _a){
//         if(_a<0) a=0;
//         else a=_a;
//     }
// };
// void show(A _a){
//     _a.a=-9999;
//     cout<<_a.a<<endl;
// }
// class B{ //friend로 A의 값 접근가능(private)
//     public:
//     B(){

//     }
//     void show(A _a)
//     {
//         A k(10);
//         k.a=10;
//         cout<<_a.a<<endl;
//     }
// };

