// https://open.kattis.com/problems/thisaintyourgrandpascheckerboard

#include <bits/stdc++.h>
using namespace std;

int output = 1;

void checkSeries(vector<char> series) {
    int consecutive = 0;
    char prevColour = series[0];
    int blackCount  = 0;
    int whiteCount  = 0;
    for (char c : series) {

        // Check for 3 consecutive squares of the same colour
        if (c == prevColour) {
            consecutive++;
            if (consecutive >= 3) {
                output = 0;
                return;
            }
        } else {
            consecutive = 1;
            prevColour  = c;
        }

        // Check for equal black squares and white squares
        if (c == 'B')
            blackCount++;
        else
            whiteCount++;
    }
    if (blackCount != whiteCount) {
        output = 0;
    }
}

int main() {
    int n;
    cin >> n;

    // column-major ordering (internal vector is a column)
    vector<vector<char>> columnVectors = vector<vector<char>>(n, vector<char>(n));

    for (int row = 0; row < n; row++) {
        vector<char> thisRowVec = vector<char>(n);
        for (int col = 0; col < n; col++) {
            char thisChar;
            cin >> thisChar;
            thisRowVec[col]         = thisChar;
            columnVectors[col][row] = thisChar;
        }
        // do row check
        checkSeries(thisRowVec);
    }
    for (vector<char> v : columnVectors) {
        checkSeries(v);
    }

    cout << output << '\n';
}