#include <iostream>
#include <algorithm>

// problem : https://www.hackerrank.com/challenges/deque-stl/problem
// soultion ========================================================

void printKMax(int arr[], int n, int k) {

    int max = *std::max_element(arr, arr + k);
    std::cout << max << " ";

    for (int i = 1; i <= (n - k); i += 1) {

        if (arr[k + i - 1] > max) {
            max = arr[k + i - 1];
            std::cout << max << " ";
            continue;
        }

        if (arr[i - 1] != max) {
            std::cout << max << " ";
        }
        else {
            max = *std::max_element(&arr[i], &arr[i + k]);
            std::cout << max << " ";
            continue;
        }

    }
    std::cout << std::endl;
}
//=======================================================================