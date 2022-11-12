#include <iostream>

using namespace  std;

////멤버함수 재정의
///*
//    function overloading
//    -함수 이름이 같아도 , parameter 개수,type,순서가 다르면 다른함수로 인식
//
//    method overloading
//    -클래스의 method
//
//    method overriding
//    -클래스에만 적용된다:OOP
//    -상속관계에서만 발생한다.
//    -자식 클래스에서 정의한 method가 동일한 signature(함수 이름,파라미터들)를 가진
//    부모 클래스의 method를 가려버리는 현상.
//
// */
//
////class Parent{
////public:
////    void whoareyou(){
////        cout<<"Parent"<<endl;
////    }
////};
//
////상속에서의 뜻
////public: public,protected->protected,private:불가능
////protected:public->protected,protected->protected
////private:public,protected->private
//
////class Child:public Parent{
////public:
////    void whoareyou(){
////        Parent::whoareyou(); //부모클래스의 method를 부름
////        cout<<"Child"<<endl;
////    }
////
////};
////int main1() {
////        Child c;
////        c.whoareyou();
////        c.Parent::whoareyou(); //부모클래스의 method를 호출할 떄 사용하는 것
////
////        Parent p;
////        p.whoareyou();
////
////    return 0;
////}
//
///*
// -multiple inheritance
// //다중상속 ->원래 소프트웨어 공학적으로 사용하면 안되는것이다. 알고는 있어야함.
//
// */
//class A{
//public:
//    int x;
//};
//class B{
//public:
//    int x;
//};
//class C:public A,public B{
//
//};
//int main2(){
//    C cc;
//    cc.A::x=10; //이런식으로 부모namespace를 사용하여 사용해야함.
//    cc.B::x=20;
//    return 0;
//}
//
//
//
///*
// 다형성 polymorphism
// ==>객체 지향에서 최고급 개념
// ==>어떤 멤버 함수를 부를지, 그때 그때 상황이 달라진다.
//
// 정적 polymorphism:method overriding
// 동적 polymorphism:dynamic binding 어려운개념이다.
// */
//
//class Parent{
//public:
//    int x;
//    virtual void show(){
//    }
//};
//
//class Child:public Parent{
//public:
//    int y;
//};
//
//int main(){
//
//    //upcasting
//    //부모클래스타입의 포인터로 자식클래스의 객체를 가리키는 일
//    //많이 사용하지만 부모포인터로 자식클래스 멤버를 건들 수는 없음
//    //Parent *p=new Child();
//    //p->x=10;
//    //p->y=000 p의 y의 공간이 없으므로 에러가난다.
//
//
//
//    //Child* c=new Parent(); ->문법적으로 서로 다른타입이기에 되지 않는다.
//    Parent *p=new Parent();
//
//
//    //Child* c=(Child *)p; //이건 쌉가능 but y값을 넣을때에 문제가 생길 수 있다. downcasting
//    Child *c=dynamic_cast<Child *>(p);
//
//    c->x=50;
//    return 0;
//}


/*
    polymorphism
    dynamic binding
*/
//virtual: 나를 밟고 가시오,상속 받은 자식중에 overriding이 있으면 자식의 method를 부르시오 이런뜻이다.
//dynamic binding: 어느 speak()이 불릴지는 runtime에 가봐야 한다.
//포인터타입(&포함)에 대해서만 성립함.
// == late binding
class Animal{
public:
    virtual void speak(){
        cout<<"Animal"<<endl;
    }
};
class Dog:public Animal{
public:
    void speak() {
        cout << "Dog" << endl;
    }
};

int main1(){
    Animal *a=new Dog();
    a->speak(); //부모의 method를 사용한다.

    Dog d;
    Animal &k=d;
    k.speak();//dog를 부른다.


    Dog d2;
    Animal a2=d2;
    a2.speak(); //Animal을 부른다.
    return 0;
}

class P2{
public:
   virtual ~P2(){
        cout<<"p2 del"<<endl;
    }
};
class C2:public P2{
public:
    int *p;
    C2(){
        p=new int[40];
    }
    ~C2(){
        delete[] p;
        cout<<"C2 del"<<endl;
    }
};
int main(){
    P2* p=new C2(); //upcasting
    delete p;
    //C2* c=new C2();
    //delete c;
    return 0;
}