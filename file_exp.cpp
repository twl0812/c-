
// //파일 입출력

// //stream : 외부에 있는 데이터를 읽고 쓰는 통로
// //input stream 
// //output stream <--자바에도 있는 개념

// //파일의 2가지종류 :text, binary
// //text:ASCII code 값으로 저장 
// //binary:값 그대로 




// //이진파일
// //binary file :값이 그대로 기록된다.
// //stream -input,output

#include<fstream>
#include<iostream>
using namespace std;
// int main()
// {
//     // ofstream os("test.txt");//close가 자동으로 된다.,write only;

//     // for(int i=0;i<100;i++)
//     // {
//     //     os<<i<<" ";
//     //     if(!(i%10))
//     //     {
//     //         os<<endl;
//     //     }
//     // }

//     //ifstream is("test.txt");
//     // int number;
//     // while(is>>number)
//     // {
//     //     cout<<number<<" ";
//     // }
//     // char c;
//     // while(!is.eof())
//     // {
//     // is.get(c);
//     // cout<<c<<endl;
//     // }
//     // return 0;






//     //기록할데이터
//     // int buffer[]={10,20,30,40,50};
//     // int data =20;
//     // char buffer2[]={'1','2','3','4','5'};
//     // ofstream os("binary.dat",ofstream::binary);
//     // os.write((char*)&buffer[0],sizeof(buffer));
//     //os.write((char*)&buffer2[0],sizeof(buffer2));

//     //읽기

//      int buffer[5];
//      ifstream is("binary.dat",ifstream::binary);
//      is.read((char *)buffer,20);
//      for(auto &v:buffer) 
//      {
//          cout<<v<<endl;
//      }
//     // return 0;

    

// }
// int main()
// {
//     //random access file
//     //순차 접근 파일: 앞에서 부터 파일을 모드 읽어야 원하는 위치전달
//     //임의 접근 파일 (random access file)
//     ifstream is("binary.dat",ifstream::binary);
//     int v;
//     is.seekg(4,ios::beg); //seekget ,seekp
//     is.seekg(-4,ios::end); //-->50
//     is.read((char*)&v,4); 
//     is.seekg(4,ios::cur);
//     is.read((char*)&v,4);
//     cout<<"value: "<<v<<endl;

//     return 0;
// }

//exception handing
//error handing

// int main()
// {
//     try{
//         int person=0;
//         if(person==0)
//         {
//             throw person;
//         }
//         else throw 'c';
//     }   //다중 캐치묹당
//     catch(int e)
//     {
//         std::cout<<"Exception catched!!"<<endl;
//     }
//     catch (char c)
//     {
//         std::cout<<"Character exption catched!!"<<endl;
//     }
// }
