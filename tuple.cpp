#include <bits/stdc++.h>
using namespace std;
int main()
{

    //tuple a data structure which can store multiple values of different data types
    //syntax
    // tuple<data_type1,data_type2,data_type3....> tuple_name;

    tuple<int,int,string,double> t1;

    t1=make_tuple(1,2,"hello",4.5);

    //accessing tuple elements
    cout<<get<0>(t1)<<"\n"; //1
    cout<<get<1>(t1)<<"\n"; //2
    cout<<get<2>(t1)<<"\n"; //hello
    cout<<get<3>(t1)<<"\n"; //4.5

    //vector of tuples
    vector<tuple<int,string,double, int>> v;
    v.push_back(make_tuple(1,"apple",2.5,10));
    v.push_back(make_tuple(2,"banana",1.5,20)); 
    v.push_back(make_tuple(3,"cherry",3.0,15));
    for(auto &it:v){
        cout<<get<0>(it)<<" "<<get<1>(it)<<" "<<get<2>(it)<<" "<<get<3>(it)<<"\n";
    }



}