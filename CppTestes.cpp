#include<iostream>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int Q = 0; std::cin >> Q;

    int QueryValue, QueryType;
    std::vector<int> qs;

    std::vector<int>::iterator it;
    bool isFound = false;

    for (int i = 0; i < Q; i += 1) {
        std::cin >> QueryType;
        std::cin >> QueryValue;

        if (QueryType == 1) qs.push_back(QueryValue);
        if (QueryType == 2) {

            for (int cc = 0; cc < qs.size(); cc += 1) {
                if (qs.at(cc) == QueryValue) {
                    qs.erase(qs.begin() + cc);
                    break;
                }
            }
        }

        if (QueryType == 3) {
            for (int c = 0; c < qs.size(); c += 1) {
                if (qs.at(c) == QueryValue) {
                    std::cout << "Yes" << std::endl;
                    isFound = true;
                    break;
                }
            }

            if(!isFound) std::cout << "No" << std::endl;
        }
        isFound = false;
    }


    return 0;
}

