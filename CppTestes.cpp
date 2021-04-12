#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops {
    int start_time;
    int duration;
    int end_time;
    Workshops(int start , int dur) {
        start_time = start;
        duration = dur;
        end_time = start + dur;
    }
};

struct Available_Workshops {
    int n; // length signed up workshop's
    std::vector<int> ends;
    std::vector<Workshops> arr; // array of signed up workshop's
};


Available_Workshops pt;

Available_Workshops* initialize(int start_time[], int duration[], int N) {
    pt.n = N;
    for (int s = 0; s < N; s+=1) {
        Workshops tempW(start_time[s], duration[s]);
        pt.ends.push_back(tempW.end_time);
        pt.arr.push_back(tempW);
    }

    return &pt;
}


int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int max = ptr->n;


    for (int a = 0; a < ptr->n-1 ; a += 1) {
        if (ptr->arr[a].start_time != ptr->arr[a+1].start_time && ptr->arr[a].end_time != ptr->arr[a+1].end_time) {
            max -= 2;
        }
    }


    return max;
}

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
