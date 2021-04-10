#include <iostream>
#include <stdexcept>

    // problem : https://www.hackerrank.com/challenges/cpp-exception-handling/


namespace soultion {

    using namespace std;

    int largest_proper_divisor(int n) {
        if (n == 0) {
            throw invalid_argument("largest proper divisor is not defined for n=0");
        }
        if (n == 1) {
            throw invalid_argument("largest proper divisor is not defined for n=1");
        }
        for (int i = n / 2; i >= 1; --i) {
            if (n % i == 0) {
                return i;
            }
        }
        return -1; // will never happen
    }


    // soultion ========================================================================
    void process_input(int n) {
        try {
            int d = largest_proper_divisor(n);
            cout << "result=" << d << endl;
        }
        catch (std::exception error) {
            std::cout << "largest proper divisor is not defined for n=" << n << std::endl;
        }
        std::cout << "returning control flow to caller" << std::endl;
    }
    // ==================================================================================

}