// https://open.kattis.com/problems/different

#include <bits/stdc++.h>

using namespace std;

int main() {
    long x, y;
    while (cin >> x >> y) {
        cout << abs(x - y) << '\n';
    }
}