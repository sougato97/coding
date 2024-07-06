class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++){
                if (nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};



// Big O solution 

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp; 
        for (auto i: nums){
            // 1 2 3 2 4  
            if (mp.find(i) != mp.end()) // means that the element exists in the map
            {
                return true;
            }
            // mp.insert({i, true});
            mp[i]=true;
        }
        return false;
    }
};
