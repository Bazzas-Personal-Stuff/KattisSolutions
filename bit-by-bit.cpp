// UNFINISHED

#include <iostream>
#include <vector>
using namespace std;

char bits[32];

void _clear(int idx) { bits[idx] = '0'; }

void _set(int idx) { bits[idx] = '1'; }

void _or(int idx1, int idx2) {

    if (bits[idx1] == '1' || bits[idx2] == '1') {
        bits[idx1] = '1';
    } else if (bits[idx1] == '0' && bits[idx2] == '0') {
        bits[idx1] == '0';
    } else {
        bits[idx1] = '?';
    }

    // 0 ? --> ?
    // 1 ? --> 1
    // 0 0 --> 0
}

void _and(int idx1, int idx2) {
    if (bits[idx1] == '0' || bits[idx2] == '0') {
        bits[idx1] == '0';
    } else if (bits[idx1] == '1' && bits[idx2] == '1') {
        bits[idx1] = '1';
    } else {
        bits[idx1] = '?';
    }

    // 0 ? --> 0
    // 1 ? --> ?
    // 1 1 --> 1
}

/*
CLEAR 𝑖
Put a zero into bit 𝑖
SET 𝑖
Put a one into bit 𝑖
OR 𝑖
Store in bit 𝑖 the logical OR of the contents of bits 𝑖 and 𝑗
AND 𝑖
Store in bit 𝑖 the logical AND of the contents of bits 𝑖 and 𝑗
*/

int main() {
    int instructionCount = 0;
    while (cin >> instructionCount) {
        if (instructionCount == 0)
            return 0;

        for (int i = 0; i < 32; i++) {
            bits[i] = '?';
        }
        for (int i = 0; i < instructionCount; i++) {
            string thisInstruction = "";
            cin >> thisInstruction;
            int arg1, arg2;
            cin >> arg1;
            if (thisInstruction == "CLEAR") {
                _clear(arg1);
            } else if (thisInstruction == "SET") {
                _set(arg1);
            } else if (thisInstruction == "OR") {
                cin >> arg2;
                _or(arg1, arg2);
            } else if (thisInstruction == "AND") {
                cin >> arg2;
                _and(arg1, arg2);
            }
        }
        for (int i = 31; i >= 0; i--) {
            cout << bits[i];
        }
        cout << endl;
    }
}
