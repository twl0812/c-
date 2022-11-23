#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

//int main()
//{
//    //vector,list,deque
//    //set,map
//    set<int> my_set;
//
//    my_set.insert(1);
//    my_set.insert(2);
//    my_set.insert(3);
//
//
//    //iterator
//    for(auto it=my_set.begin();it!=my_set.end();it++)
//    {
//        cout<<*it<<endl;
//    }
//        //range-basedforloop
//    for(auto&e:my_set)
//    {
//        cout<<e<<endl;
//    }
//    return 0;
//}
//int main()
//{
//    //map :hashtable ==>key,value
//    //검색좋음
//    //key와 value값을 지정해준다.
//    map<string,int> my_map;
//    my_map["john"]=20;
//    my_map["johnson"]=19;
//    cout<<my_map["john"]<<endl;
//    cout<<my_map["johnson"]<<endl;
//
//
//    return 0;
//}

/*  container adapter
    stack queue priority_queue 이거와 같이 사용할 수 있게끔 바꾸어줌
 */
//int main()
//{
//    //stack<int> my_stack;//기본적으로 vector임 default
//    stack<int,list<int>> my_stack;
//    my_stack.push(10);
//    my_stack.push(20);
//    my_stack.push(30);
//    cout<<my_stack.size()<<endl<<endl;
//    while(!my_stack.empty()) {
//        cout << my_stack.top() << endl;
//        my_stack.pop();
//    }
//    return 0;
//}
//int main()
//{
//    //queue<int,deque<int>>my_q;
//    queue<int>my_q;
//    my_q.push(10);
//    my_q.push(20);
//    my_q.push(30);
//    cout<<my_q.size()<<endl<<endl;
//    cout<<my_q.front()<<endl;
//    cout<<my_q.back()<<endl<<endl;
//
//    while(!my_q.empty())
//    {
//        cout<<my_q.front()<<endl;
//        my_q.pop();
//    }
//    return 0;
//}




//template<typename T>
//class MyCompare{
//public:
//    bool operator()(T a,T b){
//        if(a>b) return true;
//        else return false;
//    }
//};
//int main()
//{
//    priority_queue<int,vector<int>,MyCompare<int>> pq;
//    pq.push(50);
//    pq.push(20);
//    pq.push(30);
//    while(!pq.empty())
//    {
//        cout<<pq.top()<<endl;
//        pq.pop();
//    }
//    return 0;
//}

/*
 Algorithm
 :find
 :count_if :조건을 만족하는 것의 개수
 :copy:복사하기
 :sort:정렬하기,기본은 오름차순
 :for_each:각요소에 함수 적용

 STL:container,iterator,algorithm
 */
//bool mycondition(string s)
//{
//    if(s.length()>=6) return true;
//    else return false;
//}
//bool my_str_sort(string s1,string s2)
//{
//    return s1>s2;
//}
//void my_func(string s)
//{
//    cout<<"string is: "<<s<<endl;
//}
//int main()
//{
//    vector<string>myf={"apple","banana","tomato","pair"};
////    sort(myf.begin(), myf.end(),my_str_sort);
//    std::sort(myf.begin(), myf.end());
//    std::reverse(myf.begin(), myf.end());
//    for(auto&e:myf) cout<<e<<" ";
//
//
//    //find
//    //1.검색의 범위를 지정 ==>[A,b)
//    //2.찾고자하는 것
////   auto it =find(myf.begin(), myf.end(),"umjunsick"); //type은 iterator
////   if(it==myf.end()) cout<<"NOT FIND"<<endl;
////   else cout<<"FIND!"<<*it<<endl;
////    auto it=find_if(myf.begin(), myf.end(),mycondition); //걸리는조건 하나만 찾고 return함
//    for_each(myf.begin(), myf.end(),my_func);
//
//    return 0;
//}


/*
  Lambda function == Lambda expression
  ==>이름이 없는 함수
 */
bool my_my_func(int i)
{
    return i%2==0;
}
int main()
{
    vector<int> numbers={1,2,3,4,5};
    auto count= count_if(numbers.begin(), numbers.end(),my_my_func);
    cout<<"normal func : "<<count<<endl;
    auto count2= count_if(numbers.begin(), numbers.end(),[](int x){return x%2==0;});
    cout<<"lambda func : "<<count<<endl;
    return 0;
}