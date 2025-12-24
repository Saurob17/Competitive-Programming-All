/*#include <bits/stdc++.h>
using namespace std;
void print(int arr[],int n){
    cout<<"Size of array is = "<<n<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool liniarsearch(int *arr, int size, int ele)
{
    print(arr,size);
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
}*/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int d1 = abs(a - b);
        int d2 = abs(b - c);
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());

        int di = v[2] - v[1];

        if (d1 == d2)
        {
            cout << "YES" << endl;
        }
        else if (di % v[0] == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
       vector<pair<int, int>> p(n); 

    
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        p[i] = make_pair(first, second); 
    }
int s=n*(m*m);
for(int i=1;i<n-1;i++){
   s -= (abs(p[i].first - p[i].first) * abs(p[i].second - p[i + 1].second));

}
if(n==1){
    cout<<n*(m*m)<<endl;
}
else{
    s-=(abs((p[0].first+m)-p[1].first)*abs((p[0].second+m)-p[1].second));
    cout<<s<<endl;
}

    }

}
 