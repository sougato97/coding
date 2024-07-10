#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    for (int j = 0; j < nums.size(); j++){
        cout<<nums[j]<<endl;
    }
}