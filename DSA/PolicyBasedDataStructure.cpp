#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
using namespace __gnu_pbds;

int main() {

    ordered_set os;
    // 1.insert a number in the list/set
    os.insert(5);
    //2.delete a given number from the set
    os.erase(5);

    //3.check if the list is empty
    //if(os.empty()) 

    //4.count of a given number in the list
    os.count();

    //5.delete all the  numbers in the list
    os.clear();

    //6.how many distinc number in the list
    os.size();

    //7.what is the smallest number in the list
    *os.begin();

    //8.what is the greatest number in the list
    *os.rbegin();
    //or
    auto pos = os.end();
    pos--;
    *pos;


    //9.Find a given number or say if it is not found
   /*
   if(os.find()==end())  cout<<"Not found";
   auto pos=os.find();
   */

   //10.how many number are smaller than a given value
    cout << os.order_of_key(7);  //it return how many num...

    //11.how many numbers are smaller then ot eaual to a given value
    int cnt = os.ordered_key(7);
    if (os.find() != os.end()) cnt++;

    //or, if we find the next value smaller then i want the its previos values smalle value
    cnt = os.order_of_key(8);

    //12.how many numbers are grater theb given value_compare
    os.size() - cnt;

    //13.how many numbers are greater then or equal to a given value
    os.size() - os.order_ofkey(7);

    //14.if the given number are sorted in ascending order, wnat is the k'th number

    /*
    1 2 5 6
    0 1 2 3

    cout<<os.find_by_order(2);
    */

    //15.if the given number are sorted in descending order, what is the k'th number
    //if we use greater<int>
    os.find_by_order(2);

    /*
    1 2 5 6 7
    0 1 2 3 4 => size-1
    os.find_by_order(os.size()-1-k);
    */

    //16.delete the k'th smallest number
    os.earase(os.find_by_order(2));
    int k;
    //17.delete the k'th greatest number 
    os.earase(os.find_by_order(os.size() - 1 - k));

    //18.delete the smallest number from the list 
    os.earase(os.begin());

    //19.delete the gratest number from the list
    os.earase(os.rbegin());

    //20. parint all the number in asscending order
    for (auto it = os.begin();it != os.end();it++) {
        cout << *it << " ";
    }

    //21.print all the number in decresing number 
    for (auto it = os.rbegin();it != os.rend();it++) {
        cout << *it << " ";
    }

    //22.which is the smallest number which is greater then or equal to a given number
    // 1 2 5 6 8
    cout<<os.lower_bound();

    //23.what is the smallest number is greater then to a given number
    cout<<*os.upper_bound();

    





}