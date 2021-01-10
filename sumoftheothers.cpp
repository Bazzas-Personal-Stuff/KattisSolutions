#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string inString = "";

    while (getline(cin, inString)) {
        stringstream ss;
        ss << inString;
        int sum = 0;
        int temp;
        while (ss >> temp) {
            sum += temp;
        }
        int sumOfOthers = sum / 2;
        cout << sumOfOthers << '\n';
    }
    int term;
    int sum = 0;
}