
// problem : https://www.hackerrank.com/challenges/cpp-maps/problem
// soultion =======================================================

/*
#include <iostream>
#include <map>

int main() {
    int Q = 0; std::cin >> Q;

    std::map<std::string, int> studentMap;

    int QueryType;
    std::string studentName;
    int studentMarks;

    while (Q != 0) {
        std::cin >> QueryType;
        std::cin >> studentName;


        if (QueryType == 1) {
            std::cin >> studentMarks;
            studentMap[studentName] += studentMarks;
            Q -= 1;
            continue;
        }

        if (QueryType == 2) {
            studentMap[studentName] = 0;
            Q -= 1;
            continue;
        }


        if (QueryType == 3) {
            std::cout << studentMap[studentName] << std::endl;
            Q -= 1;
            continue;
        }

        Q -= 1;
    }

    return 0;
}

*/

// =====================================================================