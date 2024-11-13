#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
  long long n = a.size(); // size of the array

  // Find the sum of elements and square of the elements
  long long Sn = (n * (n+1))/2; // sum of N elements
  long long Sn_squared = (n*(n+1)*(2*n+1))/6; // Sum of N^2 elements
  
  
  long long sum = 0, sum_elem_squared = 0;
  for (int i=0; i<n; i++){
    sum += a[i];
    sum_elem_squared += (long long)a[i] * (long long)a[i];
  } 

  /*
  r -> repeated no.
  m -> missing no. 
  val1 = sum - Sn = r-m
  val2 = sum_elem_squared - Sn_squared = r^2 - m^2 = (r+m)(r-m) 
  val3 = r+m
  */
  long long val1 = sum - Sn;
  long long val2 = sum_elem_squared - Sn_squared;
  long long val3 = val2/val1; 
  long long r = (val1 + val3)/2;
  long long m = r - val1;
  return {(int)r, (int)m};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

