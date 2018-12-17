#include <iostream>
#include <string>
using namespace std;
// Sign In and Sign Out (25)

int main() {
    int n;
    string name, time_in, time_out,
           first, last, first_time, last_time;

    cin >> n >> name >> time_in >> time_out;    // the first case
    first = last = name;
    first_time = time_in;
    last_time = time_out;
    for (int i=1; i<n; i++) {    // the rest n-1 cases
        cin >> name >> time_in >> time_out;
        if (time_in < first_time) {
            first_time = time_in;
            first = name;
        }
        if (time_out > last_time) {
            last_time = time_out;
            last = name;
        }
    }
    cout << first << ' ' << last << endl;
}