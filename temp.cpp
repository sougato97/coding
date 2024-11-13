#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = matrix.size();
    for (int i = 0; i < n; i++){
        cout << matrix[i][0] << " ";
        cout << endl;
    }

    return 0;
}