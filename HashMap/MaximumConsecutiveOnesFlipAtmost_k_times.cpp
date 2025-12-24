#include<bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
    int l = 0, zeroCount = 0, maxLen = 0;

    for (int r = 0; r < nums.size(); r++) {
        if (nums[r] == 0) zeroCount++;

        while (zeroCount > k) {
            if (nums[l] == 0) zeroCount--;
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<longestOnes(nums,k)<<endl;

}
