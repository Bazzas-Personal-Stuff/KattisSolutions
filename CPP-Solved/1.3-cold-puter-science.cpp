// https://open.kattis.com/problems/cold

#include <iostream>
using namespace std;
int main() {
    int tempCount;
    int total = 0;
    cin >> tempCount;
    for (int i = 0; i < tempCount; i++) {
        int temp;
        cin >> temp;
        if (temp < 0)
            total++;
    }

    cout << total << '\n';
    return 0;
}