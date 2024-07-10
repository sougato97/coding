class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> nums_cpy = nums;
        for (int i = 0; i<nums.size(); i++){
            for (int j = 0; j<nums.size(); j++){
                if (i == j){
                    continue;
                }
                else if(nums[i] + nums[j] == target){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }

        }
    }
};

//Two Integer Sum
//Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

//You may assume that every input has exactly one pair of indices i and j that satisfy the condition.


// optimized

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> nums_cpy = nums;
        unordered_map<int, int> mp;
        for (int i = 0; i<nums.size(); i++){
            int temp = target - nums[i];
            if (mp.find(temp) != mp.end()){
                return {mp[temp], i};
            }
            mp.insert({nums[i], i});
        }

        return {};
    }
};
