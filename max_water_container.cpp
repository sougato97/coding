#include <optional>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> heights = {1,7,2,5,4,7,3,6};
  int left = 0;
  int right = heights.size() - 1;
  int max_area = 0;
  int area = 0; 

  while(left<right){
      int area = min(heights[left], heights[right]) * (right-left);
      if (area > max_area){
          max_area = area;
      }
      if (heights[left] < heights[right]){
          left ++;
      }
      else{
          right--;
      }
  }
  cout<<"The max area is: "<<max_area<<endl;
}
