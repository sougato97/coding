#include <iostream>
#include <vector>

int main() {
    long long arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    std::vector<long> vec(arr, arr + arrSize);
    // std::vector<long> vec = arr;

    // Print the vector
    for (long elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl; // Ensure the output is flushed

    return 0;
}
