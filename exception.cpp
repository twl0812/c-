#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    try
    {
        cout<<v.at(0)<<endl; 
        cout<<v.at(10)<<endl; //->error
        v.resize(v.max_size()+1); //maxsize->벡터가가진 최대의 사이즈
    }
    catch(length_error& e)
    {
        cout<<"me: length "<<e.what()<<endl;
    }
    catch(out_of_range& e) //catch는 한번만 처리되면 끝이다.
    {
        cout<<"me: range "<<e.what()<<endl;
    }
    catch(exception& e)
    {
        cout<<"exception"<<e.what()<<endl;
    }
    cout<<"ended"<<endl;
    return 0;
}