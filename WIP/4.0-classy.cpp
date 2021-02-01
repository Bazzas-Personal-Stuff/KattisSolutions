#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
using namespace std;

class Compare {
  public:
    inline bool operator()(const pair<string, int> a, const pair<string, int> b) const {
        if (a.second == b.second) {
            return (a.first.compare(b.first) < 0);
        } else {
            return a.second > b.second;
        }
    }
};

int main() {
    int cases, peopleCount;
    cin >> cases >> peopleCount;

    for (int thisCase = 0; thisCase < cases; thisCase++) {

        set<pair<string, int>, Compare> pqueue;
        for (int personID = 0; personID < peopleCount; personID++) {
            string name, classes, trash, thisToken;
            cin >> name >> classes >> trash;
            name.pop_back(); // get rid of colon
            stringstream ss(classes);
            vector<int> splitLTR;
            while (getline(ss, thisToken, '-')) {
                int val;
                if (thisToken.compare("upper") == 0) {
                    val = 1;
                } else if (thisToken.compare("middle") == 0) {
                    val = 0;
                } else {
                    val = -1;
                }
                splitLTR.push_back(val);
            }
            int i = 10, sum = 0;
            for (int idx = splitLTR.size() - 1; idx >= 0; idx--) {
                sum += (int)(splitLTR[idx] * pow(2, i));
                i--;
            }
            pqueue.insert(pair<string, int>(name, sum));
        }
        set<pair<string, int>>::iterator it;
        for (it = pqueue.begin(); it != pqueue.end(); it++) {
            cout << it->first << '\n'; //' ' << pqueue.top().second << '\n';
        }
        cout << "==============================\n";
    }
}

// strings to numbers LTR until you get to "class"
// RTL add all numbers together

/*

upper class and middle-upper class are equivalent, as are
middle-middle-lower-middle and lower-middle.

2x2^1 != 2x2^2

When comparing classes, once you have reached the lowest level of detail,
you should assume that all further classes are the same as the middle level of
the previous level of detail. So upper class and middle-upper class are
equivalent, as are middle-middle-lower-middle and lower-middle.
*/