#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findSubsets(int index, vector<int> &nums, vector<int> &stack, vector<vector<int>> &ans){
        ans.push_back(stack); // for the first recursion call, it will be the empty stack
        for (int i = index; i<nums.size(); i++){
            // Check duplicates for the same stack level
            if (index != i && nums[i]==nums[i-1]){
                continue;
            }
            stack.push_back(nums[i]);
            findSubsets(i+1, nums, stack, ans);
            stack.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> stack;
        sort(nums.begin(), nums.end());
        /*
        0 sis the starting index
        stack maintains the datastructure of the present inserted element
        */
        findSubsets(0, nums, stack, ans);
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 3};
    Solution s;
    vector<vector<int>> ans = s.subsetsWithDup(arr);
    // Printing the answer
    for (int i = 0; i<ans.size(); i++){
        for (int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}