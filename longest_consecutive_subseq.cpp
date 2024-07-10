#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;        


int main(){
        
  // vector <int> nums = {12,4,4,20,21,21,4,5,12,14,16,6,7};
  vector <int> nums = {2,20,4,10,3,4,5};
  unordered_map<int, int> mp;
  map<int, int> sorted_map;

  for (auto x: nums){
    sorted_map[x] = 1;
  }

  for (auto x: sorted_map){
    // cout<<x.first<<" "<<x.second<<endl;
    if(mp.find(x.first) != mp.end()){ // element present, do not increment
      continue;
    }
    else if(mp.find(x.first - 1) != mp.end() ) // sequence present
    {
      int temp = mp[x.first-1] + 1;
      mp.erase(x.first-1);
      mp[x.first] = temp; // replace the key with the latest head
      cout<<"For key: "<<x.first<<" the value is: "<<temp<<endl;
    }
    else{
      mp[x.first]++;
      // cout<<"print the key and value\n";
      // cout<<"For key: "<<nums[i]<<" the value is: "<<mp[nums[i]]<<endl;
    }
    
  }

  int max=0; 
  for (auto x = mp.begin(); x!=mp.end(); x++){
      if (x->second > max){
          max = x->second;
      }
  }
  
  cout<<"The length of the longest consecutive subsequence is: "<<max<<endl;

}


// subhobrata's code
// unordered_set<int> ms(nums.begin(),nums.end());
//         int result=0;
//         for(auto num:nums){
//             int length=1;
//             int currentnum=num;//2
//             while(ms.find(currentnum+1)!=ms.end()){
//                 length++;//2,3,4
//                 currentnum+=1;//3,4,5
//             }
//             result=max(length, result);


//         }