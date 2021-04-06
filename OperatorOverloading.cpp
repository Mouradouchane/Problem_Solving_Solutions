#include <iostream>
#include <vector>

// problem : https://www.hackerrank.com/challenges/operator-overloading/problem
// soultion ===================================================================

class Matrix {
public:
    std::vector<std::vector<int>> a;
    Matrix() {

    }
    ~Matrix() {

    }
};

Matrix operator +(Matrix& m1, Matrix& m2) {
    Matrix rs;
    std::vector<int> newRow;
    for (int M = 0; M < m1.a.size(); M += 1) {
        for (int N = 0; N < m1.a[M].size(); N += 1) {
            newRow.push_back(m1.a[M][N] + m2.a[M][N]);
        }
        rs.a.push_back(newRow);
        newRow.clear();
    }

    return rs;
}
// end of soultion ===================================================================




/*
int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
*/