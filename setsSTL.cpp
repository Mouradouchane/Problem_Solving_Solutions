/*
#include <iostream>
#include <set>

int main() {

    // problem : https://www.hackerrank.com/challenges/cpp-sets/problem
    // soultion =======================================================

    int Q; std::cin >> Q;

    std::set<int> seq;

    int type, query;
    for (int i = 0; i < Q; ++i) {
        std::cin >> type;
        std::cin >> query;

        switch (type) {
        case 1: seq.insert(query); break;
        case 2: seq.erase(query); break;
        case 3: std::cout << (seq.find(query) == seq.end() ? "No" : "Yes") << std::endl; break;
        }

    }

    // ====================================================================

    return 0;
}
*/