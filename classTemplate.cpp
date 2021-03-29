/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
*/

// problem : https://www.hackerrank.com/challenges/c-class-templates/problem
// sloution =============================================
/*
template<typename t> class AddElements {
public:
    t e1;
    string estr;

    AddElements(t ef1) :e1(ef1) {
        this->estr = ef1;
    }
    t add(t ei2) {
        this->e1 += ei2;
        return (this->e1);
    }
    string concatenate(string el2) {
        return (estr + el2);
    }
    ~AddElements() {

    }
};

int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

int r = start_up();
#define endl '\n';
*/
// ==================================================


/*
int main() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        string type;
        cin >> type;
        if (type == "float") {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
*/