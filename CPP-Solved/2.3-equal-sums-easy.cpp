// https://open.kattis.com/problems/equalsumseasy

#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;

// use bitmask (int32) to get all subsets in a binary form
// bitmask defines whether each element of the array is included or excluded

void printSubset(vector<int> set, int mask) {
    for (int i = 0; i < set.size(); i++) {
        bool useElement = (mask >> i) & 1;
        if (useElement) {
            cout << set[i] << " ";
        }
    }
    cout << "\n";
}

int subsetSum(vector<int> set, int mask) {
    int sum = 0;
    for (int i = 0; i < set.size(); i++) {
        bool useElement = (mask >> i) & 1;
        if (useElement) {
            sum += set[i];
        }
    }
    return sum;
}

int main() {
    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        cout << "Case #" << t + 1 << ":"
             << "\n";
        vector<int> inputSet;
        map<int, int> sumMap;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int j;
            cin >> j;
            inputSet.push_back(j);
        }
        // do stuff here for each case
        int highestMask = pow(2, n) - 1;
        for (int i = 0; i <= highestMask; i++) {
            int key = subsetSum(inputSet, i);
            int val = i;

            if (sumMap.count(key) == 0) {
                // the sum is unique
                sumMap.insert(pair<int, int>(key, val));
            } else {
                // sum is already in the map
                // print out the subset in map
                printSubset(inputSet, sumMap.find(key)->second);
                // print out this subset
                printSubset(inputSet, i);
                break;
            }
        }
    }
}
