#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> outVector;
    char nextChar;
    int consecutiveBacks = 0;
    while (!cin.eof()) {
        nextChar = cin.get();

        if (nextChar == '<') {
            outVector.pop_back();
        } else {

            outVector.push_back(nextChar);
        }
    }
    outVector.pop_back();
    for (char c : outVector) {
        cout << c;
    }
    cout << '\n';
}

/*
- Get string
- Store string
- manipulate string





Neils way:
- count consecutive '<'

Bailey's way
- Count consecutive '<'s
-


if (startIndex == 0) just get everything after the last '<'

substring(0, startIndex) + last '<' to end of string

ab<<cd<d<

cab<<cd<d<
*/