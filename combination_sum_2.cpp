#include<bits/stdc++.h>

using namespace std;

void findCombination(int index, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
    
    // termination condition
    if (index == arr.size()){
        if (target == 0){
            sort(ds.begin(), ds.end());
            // check if ds is already present in ans
            if (find(ans.begin(), ans.end(), ds) != ans.end()){
                // do nothing
            }
            else{
                ans.push_back(ds);
            }
        }
        return;
    }
    
    // recursive calls
    if (arr[index] <= target){
        ds.push_back(arr[index]);
        // pick
        findCombination(index + 1, target-arr[index], arr, ds, ans);
        ds.pop_back();
    }

    // dont pick (this part is tricky, needs to be outside the if condition.)
    findCombination(index + 1, target, arr, ds, ans);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds; //here its a stack. 
    findCombination(0, target, candidates, ds, ans); 
    return ans;        
}

int main() {
  vector<int> v{2,5,2,1,2};
  vector < vector < int >> comb = combinationSum2(v, 5);
  cout << "[ ";
  for (int i = 0; i < comb.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << "]";
  }
  cout << " ]";
}