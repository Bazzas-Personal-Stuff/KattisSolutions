// https://open.kattis.com/problems/twostones

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << ((n % 2) ? "Alice\n" : "Bob\n");
}