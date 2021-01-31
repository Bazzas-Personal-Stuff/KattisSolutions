#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

float distWithoutRad(int cx, int cy, int x, int y, int r) {
    float dy, dx;
    dy = y - cy;
    dx = x - cx;
    return sqrt(dy * dy + dx * dx) - r;
}

int main() {
    int cx, cy, n;
    int x, y, r;
    priority_queue<float, vector<float>, greater<float>> distanceQueue;
    cin >> cx >> cy >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        distanceQueue.push(distWithoutRad(cx, cy, x, y, r));
    }

    distanceQueue.pop();
    distanceQueue.pop();

    float third = distanceQueue.top();
    if (third < 0) {
        third = 0;
    }

    cout << (int)third << '\n';
}