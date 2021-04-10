

// problem : https://www.hackerrank.com/challenges/accessing-inherited-functions/

// soultion =====================================================================
/*
class D : public B, public C, public A {

    int val;
public:
    //Initially val is 1
    D() :val(1) {  }

    //Implement this function
    void update_val(int new_val) {
        while (new_val > 1) {
            if (new_val % 2 == 0) new_val /= 2, A::func(val);
            if (new_val % 3 == 0) new_val /= 3, B::func(val);
            if (new_val % 5 == 0) new_val /= 5, C::func(val);
        }
    }
    int getA() {
        return A::getA();
    }
    int getC() {
        return C::getC();
    }
    int getB() {
        return B::getB();
    }
    //For Checking Purpose
    void check(int); //Do not delete this line.
};
*/
// =============================================================================


