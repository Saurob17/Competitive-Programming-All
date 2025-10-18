//https://leetcode.com/problems/bitwise-and-of-numbers-range/
#include <bits/stdc++.h>
using namespace std;
    int rangeBitwiseAnd1(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
int main(){
    int l,r;
    cin>>l>>r;
    cout<<rangeBitwiseAnd1(l,r)<<endl;
}