#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3, 7, 8, 8, 6, 6, 6};
    int k = 4;
    unordered_map<int, int> counts;
    vector<vector<int>> freq(nums.size()+1); // this is important, made the mistake of declaring vector<int, vector<int>>

    for (auto x: nums){

        counts[x]++;
    }

    // for (auto x: counts){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    // cout<<"\nend of unordered map\n"<<endl;

    for (auto x: counts){

        freq[x.second].push_back(x.first);
    }

    // cout<<"Printing the size of frequency "<<freq.size()<<endl;
    vector<int> topk;
    for (int i = freq.size()-1; i>-1; i--){

        for(int j = 0; j < freq[i].size(); j++){
            if (topk.size() == k){  
                break;
            }
            topk.push_back(freq[i][j]);
        }
    }

    cout<<"Printing the top k elements"<<endl;
    for(auto k: topk){
        cout<<k<<" ";
    }
    cout<<endl;

    // cout<<"Printing the frequency"<<endl;
    // for (int i = freq.size()-1; i>-1; i--){

    //     for(int j = 0; j < freq[i].size(); j++){
    //         cout<<freq[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for (int i = 0; i < freq.size(); i++){

    //     for (int j = 0; j < freq[i].size(); j++){
    //         cout<<freq[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}