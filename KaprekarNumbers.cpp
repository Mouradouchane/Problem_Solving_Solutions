#include <string>
#include <vector>

// problem : https://www.hackerrank.com/challenges/kaprekar-numbers/problem
// solution =================================================================

std::vector<unsigned long long int> split(unsigned long long int const &num) {

    // square number & save it as string for split 
    std::string str = std::to_string( (num * num) );
    
    // middle index location for "split"
    unsigned int len = (str.size() % 2 != 0) ? (str.size() - 1) / 2 : str.size() / 2; 
    
    // 2 string for saving splited number in tow parts
    std::vector<std::string> nums = { "" , "" };

    // for match split location in loop
    bool h = false;
    for (unsigned int x = 0, n = 0; x < str.size(); x += 1) {
        if (x == len) n = 1; // mean we need to switch to the next one
        nums[n] += str[x];   // "char by char" fill target 
    }
    
    std::vector<unsigned long long int> splited;
    // convert to numbers & check if those numbers in empty or not
    splited.push_back((nums[0] != "") ? std::stoi(nums[1]) : 0);
    splited.push_back((nums[0] != "") ? std::stoi(nums[0]) : 0);

    // send splited values for check ;)
    return splited;
}

// check if splited values are "kaprekarNumbers" to the target
bool check(std::vector<unsigned long long int> splited, unsigned long long int const& target) {
    if (target == 1) return true; // 1 mean ==> true :)

    // else check if "kaprekarNumbers" & return
    return (splited[0] + splited[1]) == target;
}

// loop over all range & check 
void kaprekarNumbers(int p, int q) {
    // for matching if there's any kaprekar numbers or not
    short matches = 0;
    for (int i = p; i <= q;i += 1) {
        // split values 
        std::vector<unsigned long long int> splited_vals = split(i);
        // then check 
        if (check(splited_vals, i)) {
            std::cout << i << " ";
            matches += 1;
        }
    }

    // in case no kaprekar number found 
    if(matches == 0) std::cout << "INVALID RANGE\n";
}

// ========================================================================