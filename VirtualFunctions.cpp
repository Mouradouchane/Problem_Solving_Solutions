/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
*/

/*
// solution ===============================================================
class Person {
protected:
    string name;
    short age;
public:
    virtual void getdata() {};
    virtual void putdata() {};
    Person() {

    }
};

class Professor : public Person {
protected:
    int publications;
public:
    static int cur_Pid;
    void getdata() {
        string newN;
        short newAG;
        int newPubs;

        cin >> newN >> newAG >> newPubs;

        name = newN; age = newAG; publications = newPubs;
    }
    void putdata() {
        Professor::cur_Pid += 1;
        cout << name << " " << age << " " << publications << " " << cur_Pid << endl;
    }
    Professor() {
  
    }
};

int Professor::cur_Pid = 0;

class Student :public Person {
protected:
    int marks[6]; int sum = 0;
public:
    static int cur_id;
    void getdata() {
        string newN;
        short newAG;

        cin >> newN >> newAG;
        name = newN; age = newAG;

        for (int m = 0; m < 6; m += 1) {
            cin >> marks[m];
            sum += marks[m];
        }
    }
    void putdata() {
        Student::cur_id += 1;
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
    Student() {
     
    }
};

int Student::cur_id = 0;
//=================================================================================
*/
/*
int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
*/