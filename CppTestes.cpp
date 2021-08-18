#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <Windows.h>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : Cache {
private:
    std::map<int, int> maap;
    int currentCapacity = 0;
public:
    LRUCache(int capacity = 0) {
        cp = capacity;
    }
    void set(int key, int value) {
        if (currentCapacity < cp) {
            auto it = maap.find(key);
            if (it != maap.end()) {
                it->second  = value;
            }
            else {
                maap.insert({ key,value });
                currentCapacity += 1;
            }
        }
        else {
            std::map<int, int>::iterator min;
            int mn = 999999;

            for (std::map<int, int>::iterator it = maap.begin(); it != maap.end(); it++) {
                if (it->second < mn) {
                    min = it;
                    mn = it->second;
                }
            }
            maap.erase(min);
            maap.insert({ key,value });
        }
    }
    int get(int key) {
        auto it = maap.find(key);
        return (it != maap.end()) ? it->second : -1;
    }
    ~LRUCache() {}
};

class testcase {
public : 
    std::string command = "";
    int key = 0 , value = 0;
    testcase(std::string cmd = "" , int Key = 0 , int val = 0) {
        command = cmd;
        key = Key;
        value = val;
    }
};

int main() {
    std::vector<testcase> alot = {};
    std::vector<int> testcase_answers = {};
    std::vector<int> answer = {};

    int n = alot.size() , capacity = 644, i;
    // cin >> n >> capacity;
    LRUCache l(capacity);

    for (i = 0; i < n; i++) {
      //  Sleep(250);

        if (alot[i].command == "get") {
            answer.push_back(l.get(alot[i].key));
        }
        else if (alot[i].command == "set") {
            l.set(alot[i].key, alot[i].value);
        }
    }
    for (int i = 0; i < testcase_answers.size(); i += 1) {
        Sleep(10);
        if(testcase_answers[i] == answer[i]) std::cout <<"CORRECT =>    " << testcase_answers[i]  <<  " " << answer[i] << '\n';
        else std::cout << "ERROR => " << testcase_answers[i] << "   " << answer[i] << '\n';
    }
    return 0;
}
