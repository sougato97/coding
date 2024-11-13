#include <optional>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> prices = {2,4,1};
  int left = prices[0]; // buy
  int right = prices[1]; // sell
  int sell_index = 1;
  int i = 1;
  while(i<prices.size()){
    i++;
    if (i == prices.size())
      break;
    if (left >= right){
        left = right;
        right = prices[i];
        sell_index = i;
    }
    else if(left < right){
        if (prices[i] < left && i < sell_index){
          left = prices[i];
        }
        if (prices[i] > right)
          right = prices[i];
          sell_index = i;
    }

    cout<<"The left is: "<<left<<" and the right is: "<<right<<endl;
  }
  if (right-left < 0){
      return 0;
  }
  return (right-left);
}   