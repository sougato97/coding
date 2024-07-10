#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// int main() {
//   // vector<int> nums = {1,2,4,6};
//   vector<int> nums = {-1,0,1,2,3};
//   vector<int> res;
//   int mult=1;
//   int result;
//   for(int i=0;i<nums.size();i++){
//       mult=mult*nums[i];
//   }
//   for(int i=0;i<nums.size();i++){
//       result=mult/nums[i];
//       res.push_back(result);
//   }
  
//   cout<<"The result is: "<<endl;
//   for(int i=0;i<res.size();i++){
//       cout<<res[i]<<" ";
//   }
//   cout<<endl;
// }

// Naive approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        vector<int> prefix(nums.size(),1), postfix(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        for(int i=nums.size()-2;i>=0;i--){
            postfix[i] = postfix[i+1]*nums[i+1];

        }

        for(int i=0;i<nums.size();i++){
            res.push_back(prefix[i]*postfix[i]);
        }
        return res;
    }
};

// the problem is: takes up 3*O(n) space


// Optimized approach (impossible to remember)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        int prefix = 1, postfix = 1;
        for(int i=0;i<nums.size();i++){
            result[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--){
            result[i]*= postfix;
            postfix*=nums[i];
        }
        return result;
    }
};