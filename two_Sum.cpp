#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i=0; i<nums.size(); i++){
        int temp = target - nums[i];
        // checks for the complement
        if (mp.find(temp) != mp.end()){
            // mp[temp] is the index of the complement element int he original array
            // temp is the complement element
            return {mp[temp], i};
        }
        // key:element, value:index
        mp.insert({nums[i],i});
    }
    return {};
}

int main() {
    int n = 5;
    vector<int> arr = {3, 2, 4};
    int target = 6;
    vector<int> ans = twoSum(arr, target);
    cout << "This is the answer: " << ans[0] << " " << ans[1] << endl;
    return 0;
}