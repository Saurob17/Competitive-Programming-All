#include <bits/stdc++.h>
using namespace std;

bool liniarsearch(int arr[], int size, int ele)
{
    if (size == 0){
         return false;
    }
       


    if (arr[0] == ele)
    {
        return true;
    }
    else
    {
        bool remainderPart = liniarsearch(arr + 1, size - 1, ele) ;
       return remainderPart;
    }
}

int main()
{
    int n = 6;
    int arr[n] = {4, 2, 6, 9, 33, 20};
    int ele=91;
    bool ans=liniarsearch(arr,n,ele);
    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
}