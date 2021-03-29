/*
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
using namespace std;
*/


// problem : https://www.hackerrank.com/challenges/inherited-code/problem
// solution  ============================================================
/*
	class BadLengthException :public exception {
	protected:
		int nError;
	public:
		BadLengthException(int n) : nError(n) {

		};
		int what() {
			return nError;
		}
	};
*/
// =====================================================================




/*
bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while (T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				cout << "Valid" << '\n';
			}
			else {
				cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
*/