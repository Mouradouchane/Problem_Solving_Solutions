#include <iostream>

// problem : https://www.hackerrank.com/challenges/box-it/problem
// soultion ========================================================================
class Box {
private:
	int l = 0, b = 0, h = 0;
public:
	Box() {
	}
	Box(int length, int breadth, int height) :l(length), b(breadth), h(height) {
	}
	Box(const Box& B) {
		l = B.l, b = B.b, h = B.h;
	}

	int getLenght() {
		return l;
	}
	int getBreadth() {
		return b;
	}
	int getHeight() {
		return h;
	}
	long long CalculateVolume() {
		return (long long)l * b * h;
	}

	bool operator < (Box& B) {
		if ((l < B.l) || ((b < B.b) && (l == B.l)) || ((h < B.h) && (l == B.l) && (b == B.b))) {
			return true;
		}
		else return false;

	};

};

std::ostream& operator<< (std::ostream& output, Box& B) {
	output << B.getLenght() << " " << B.getBreadth() << " " << B.getHeight();
	return output;
}
// =====================================================================================
