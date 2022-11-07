//정적 변수, 정적함수
/*
 static method의 제약사항
  반드시 static 변수,다른 스태틱 메소드만 사용가능.
 
 non static method는 static-method를 부를 수 있음. 부를 수 있음.
 
 전역변수를 사용하게 되면 생산성이 많이 떨어지기 때문에 이것을 사용하는 것이다. 의존성을 끊어야 생산성이 올라감.
 */


//singleton design pattern(디자인패턴)
// 기본적으로 알아야하는 패턴

// 상황:문제상황 .......
//싱글톤의 상황:: 특정 클래스에서 오직 1개의 객체만 만들어지도록 할 수 있을까? 무조건 1개만 만들도록 설계





#include <iostream>
using namespace std;


//operator overloading 연산자 오버로딩
//function overloading

class Myvector{
private:
    int x,y;
public:
    Myvector(int _x,int _y):x(_x),y(_y){}
    void showXY(){
        cout<<x<<" "<<y<<endl;
    }
    //Myvector addTwovectors(Myvector& v)
    //{
       // Myvector temp(this->x+v.x,this->y+v.y);
        //return temp;
    //}
    Myvector operator+(Myvector& other){
        cout<<"first overloading"<<endl;
        Myvector temp(this->x+other.x,this->y+other.y);
        return temp;
    }
    Myvector* operator+(Myvector* other){
        cout<<"second overloading"<<endl;
        Myvector* temp=new Myvector(this->x+other->x,this->y+other->y);
        return temp;
    }
    bool operator==(Myvector& other){
        return (this->x==other.x && this->y==other.y);
    }
    bool operator!=(Myvector& other){
        //return (this->x!=other.x || this->y!=other.y);
        return !(*this ==other);
    }
};

int main6()
{
    Myvector *v1=new Myvector(10,10);
    Myvector v2(20,20);
    Myvector v3=*v1+v2; //객체에 대하여만 overloading 이 먹힌다 포인터끼리는 연산자가 안먹힘.
    v3.showXY();
    return 0;
}


int main10()
{
    Myvector v1(10,20);
    Myvector v2(10,20);
    cout<<boolalpha;
    cout<<(v1==v2)<<endl;
    return 0;
}
//++ -- increment operator
class MyValue{
private:
    int x;
public:
    MyValue(int _x):x(_x){}
    MyValue& operator++()
    {
        this->x=this->x+1;
        return *this;
    }
    MyValue operator++(int){ //postfix 여기서 복사를 한번더함
        MyValue temp=*this; //나를 복사해서 하나를 만든다.
        this->x=this->x+1;
        return temp;
    }
    MyValue operator=(const MyValue & other)
    {
        this->x=2*other.x;
        return *this;
    }
    void show(void)
    {
        cout<<this->x<<endl;
    }
    /*
        idx operator overloading
        p414
     */
    int operator[](int k){
        if(k<50) return -999;
        else return 999;
    }
};
int main0()
{
    MyValue v1(10);
    //++v1;
    //++v1;
    //++(++v1) ++v1 10->11
    // v1' 12 하지만 v1'이아닌 v1
    MyValue k=v1++;
    
    //++(v1++) 11
    //(++v1)++ 12
    k.show();
    return 0;
}

int main999()//idx operator
{
    MyValue v1(10);
    cout<<v1[70]<<endl;
    return 0;
}



/*
 포인터 연산자의 중복
 pointer operator overloading
 */

class MyIntPtr{
private:
    int *p;
public:
    MyIntPtr(int *_p):p(_p){}
    ~MyIntPtr(){ //스마트포인터가 되는 핵심
        delete p;
    }
    int operator *(){
        return *p;
    }
};





int main()
{
    //while(1)
    //{
        //int *p=new int(40); //메모리는 계속 생성된다. memory leak
        //delete p;
        //unique_ptr<int> p(new int (40));
    //}
    while (true)
    {
    MyIntPtr p(new int(40));
        cout<<*p<<endl; //operator overloading
    }
    while (true)
    {
    MyIntPtr *p1=new MyIntPtr(new int(40));
    }
    return 0;
}






//대입연산자
int main112()
{
    MyValue v1(10);
    MyValue k=v1; //복사생성자
    
    MyValue v2(20);
    k=v2;   //대입연산자,assignment operator
    k.show();
    return 0;
}









/*
    클래스로 부터 오직 1개의 객체만 만들어지도록 하는 싱글톤 패턴이 적용된 클래스
 */

class MyOnlyObj{
private:
    int d; //단순데이터, 별의미 없음
private: // 생성자를 막아놓음
    static MyOnlyObj* instance;
    MyOnlyObj(){
        d=100;
    };
public:
    static MyOnlyObj* getInstance()
    {
        if(instance == nullptr)
        {
            instance=new MyOnlyObj();
        }
        return instance;
    }
    void showD(){
        cout<<d<<endl;
    }
    void setD(int k)
    {
        d=k;
    }
};
MyOnlyObj* MyOnlyObj::instance=nullptr;
int main2()
{
    MyOnlyObj *p1=MyOnlyObj::getInstance();
    MyOnlyObj *p2=MyOnlyObj::getInstance();
    MyOnlyObj *p3=MyOnlyObj::getInstance();
    p1->showD();
    p2->setD(300);
    p1->showD();
    return 0;
}

class Myobj{
private:
    int i;
    float j;
public:
    static int k; //only 1 copy 메모리상에 하나 즉 클래스 자체의 정보를 가지고 있음 오브젝트가 없어도 존재가능하다.
                // 왜쓰냐? 초기화하는것도 일반 객체와 다르다.
    Myobj(int _i,float _j):i(_i),j(_j){}
    void show()
    {
        cout<<i<<" "<<j<<endl;
        cout<<k<<endl;
    }
    
    static void showstatics(){ //객체가 없이도 그냥 부를 수 있음.제약사항:객체가 있어야만 할 수 있는 것들을 못한다.(i,j를 사용하지 못함), k는 사용할수 있음
        cout<<"i am a static function method"<<endl;
        cout<<k<<endl;
    }
};
int Myobj::k=10; //static 변수는 이런식으로 초기화 한다. //클래스 안에 있기떄문에 이런식으로 초기화 한다.
int main1() {
    Myobj::showstatics(); //이런식으로 함수를 부른다.
    //Myobj o1(10,3.14);
    //Myobj* o2=new Myobj(20,9.999);
    //o1.show(); // 10,3.14,10;
    //o2->k=777;
    //o1.show(); // 10,3.14,777;
    return 0;
}
