#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<deque> //double ended queue
using namespace std;
/*
    STL
    Standard Template Library
    ex) vector<int> ....


    1.container
    vector,list,queue,stack,priorty queue,set->중복을 허락하지않는집합,map->hashtable


    2.iterator: 반복자


    3.algorithm
    find, sort,reverse,remove,transform
*/

// vector,list
//int main11()
//{
    /*
        list:DLL
        vector:array,contiguous memory

        list:insertion,deletion 거의 일정
        vector: add는 일정,insertion,deletion은 상황에 따라 다르다.

        list:large memory
        vector:small memory

        list:no default size
        vector:default size

        list: random access is not possible .at(i) 인덱스 지원을 안한다.
        vector:v.at(1)


        Interator
        ==generalized pointer
        begin()
        end()
        ++
        --
        *
        rbegin():reverse begin
        rend(): reverse end
    */
    // vector<int> v={1,2,3,4,5};
    // list<int>v2={1,2,3,4,5};
    // for(auto& e:v)
    // {
    //     cout<<e<<endl;
    // }
    // for(auto& e:v2)
    // {
    //     cout<<e<<endl;
    // }
    // return 0;
//}
int main()
{
    list<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);    
    for(auto i= v.begin(); i!=v.end();i++)
    {
        cout<<*i<<endl;
    }
    for(auto e:v)
    {
        cout<<e<<" ";
    }
    return 0;
}
// int main5()
// {
//     deque<int>dq;
//     dq.push_back(10);
//     dq.push_back(20);
//     dq.push_front(999);
//     dq.push_front(100);

// }
