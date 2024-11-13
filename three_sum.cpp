#include <optional>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

// optional<vector<int>> twoSum(vector<int>nums, int start){
//     int j = nums.size() - 1;
//     int target = nums[start];
//     int i = start + 1;
//     // cout<<"The start address is: "<<start<<endl;
//     // cout<<"The target is: "<<nums[start]<<endl;
//     while (i<j){
//       if (nums[i] + nums[j] + target > 0){
//         j--;
//         // if (start == 2)
//         //   cout<<"First condition with nums[i] = "<<nums[i]<<" and nums[j] = "<<nums[j]<<endl;
//       }
//       else if (nums[i] + nums[j] + target < 0){
//         i++;
//         // if (start == 2)
//         //   cout<<"Second condition with nums[i] = "<<nums[i]<<" and nums[j] = "<<nums[j]<<endl;
//       }
//       else if (nums[i] + nums[j] + target == 0){
//         // if (start == 2){
//         //   cout<<"The two sum is: ";
//         // cout<<nums[i]<<" "<<nums[j]<<" with target: "<<target<<endl;
//         // cout<<"3rd condition\n";
//         return {{nums[i], nums[j]}};
//       }
//     }
//     return nullopt;
// }


// int main(){
//   // vector<int> nums = {-1, 0, 1, 2, -1, -4};
//   vector<int> nums = {-2, 0, 1, 1, 2};
//   sort(nums.begin(), nums.end());
//   cout<<"The sorted vector is: \n";
//   for (auto i: nums){
//     cout<<i<<" ";
//   }
//   cout<<"\nEnd of no_duplicate set\n";
//   int i = 0;
//   while(i<nums.size()){
//     // cout<<"The i is: "<<i<<endl;
//     if(i==nums.size()-1)
//       break;
//     auto twosum_vector = twoSum(nums, i);
//     if (twosum_vector){
//       cout<<"The three sum is: ";
//       cout<<nums[i]<<" "<<(*twosum_vector)[0]<<" "<<(*twosum_vector)[1]<<endl;
//         // return {nums[i], twosum_vector[0], twosum_vector[1]};
//     }
//     i++;
//   }
// }


vector<vector<int>> twoSum(vector<int>nums, int start){
    int j = nums.size() - 1;
    int target = nums[start];
    int i = start + 1;
    vector<vector<int>> three;
    while (i<j){
        if (nums[i] + nums[j] + target > 0){
            j--;
        }
        else if (nums[i] + nums[j] + target < 0){
            i++;
        }
        else if (nums[i] + nums[j] + target == 0){
          three.push_back({target, nums[i], nums[j]});
          i++;
          j--;
          while(i<j && nums[i] == nums[i-1])
            i++;
        }
    }
    return three;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    sort(nums.begin(), nums.end());
    int i = 0;
    vector<vector<int>> result;
    set<vector<int>> result_set;
    while(i<nums.size()){
        if(i==nums.size()-1)
        break;
        auto twosum_vector = twoSum(nums, i);
        // if (!twosum_vector.empty()){
        //     for (auto x: twosum_vector)
        //         result_set.insert(x);
        //     // result.push_back(temp);
        // }
        for (auto x: twosum_vector){
            result.push_back(x);
        }
        i++;
    }
    // for (auto x: result_set){
    //     result.push_back(x);
    // }
    
    cout<<"The three sum is: \n";
    for (auto x: result){
      cout<<"Pair:";
      for (auto y: x){
          cout<<y<<" ";
      }
      cout<<endl;
    }
    // return result;
}

