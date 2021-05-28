#include<iostream>
#include<algorithm>
#include<vector>

// problem : https://www.hackerrank.com/challenges/attending-workshops/problem
// solution O(n*2 + n log(n)) ==================================================

// workshop class 
class Workshop {
public:
    int s = 0; // start time
    int d = 0; // duration
    int e = 0; // end time ==> ( s + d )
    Workshop(int s, int d) :s(s), d(d) {
        // end time ==> ( s + d )
        e = s + d;
    }
};

// for sorting workshops by "end time" from smaller to bigger
bool sortFunction(Workshop a, Workshop b) {
    return (a.e < b.e);
}

    // Available_Workshops class contain 
    // workshop ==> vector of workshops
    // calcMax function who calculate the maximum of available workshops
class Available_Workshops {
protected:
    std::vector<Workshop> workshop;
public:
    // in 'construction time' we pass array of "start time" & "durations" with "n length"
    // and filling workshop vector & sorting 
    Available_Workshops(int s[], int d[], int n) { 
            // O(n)
        for (int i = 0; i < n; i += 1) {    
            Workshop currentWorkshop(s[i], d[i]);
            workshop.push_back(currentWorkshop);
        }

        // O(n log n) to O(n²)
        // sorting vector of workshop important for correct processes
        std::sort(workshop.begin(), workshop.end(), sortFunction);
    }

    int calcMax() {
        // max Available_Workshops we found in loop processe
        int max = 0;

        // like temp variable contain alwayse the "end time" of pervious one 
        // important for checking 
        int end = 0; 

        // looping 'using iterator' over all
        // O(n)
        for (std::vector<Workshop>::iterator it = workshop.begin(); it != workshop.end(); it += 1) {
            // in case current workshop start time bigger than pervious 
            // that mean it's a valid workshop soo we increment max :)
            if (it->s >= end) {
                max += 1;
                // and we make pervious end equal to 'current end'
                // important for valid checking 
                end = it->e;
            }
        }

        // last step return max we found
        return max;
    }
};


// in initialize just calling passing all values to new Available_Workshops object and ===> "will be processed in construction time"
Available_Workshops* initialize(int s[], int d[], int n) {
    // passing start time array & duration & length n
    Available_Workshops* workshops = new Available_Workshops(s, d, n);

    // return proccessed Available_Workshops object with vector of workshops ready for calculating
    return workshops;
}

// in CalculateMaxWorkshops just calling calcMax in p 
int CalculateMaxWorkshops(Available_Workshops* p) {
    int max = p->calcMax();

    return max;
}
// =====================================================================================
