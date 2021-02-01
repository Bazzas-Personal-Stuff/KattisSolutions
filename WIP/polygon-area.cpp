// failing second test case

#include <iostream>
#include <vector>
using namespace std;

struct Point {
    float x;
    float y;
};

float SegmentArea(vector<Point> *polygon, int idx1, int idx2) {
    float width  = (*polygon)[idx2].x - (*polygon)[idx1].x;
    float height = ((*polygon)[idx2].y + (*polygon)[idx1].y) / 2.0;
    return width * height;
}

float GetArea(vector<Point> *polygon) {
    float total = 0;

    for (int i = 0; i < polygon->size() - 1; i++) {
        total += SegmentArea(polygon, i, i + 1);
    }
    // add the last edge
    total += SegmentArea(polygon, polygon->size() - 1, 0);
    return total;
}

int main() {
    int n = 0;
    cin >> n;
    while (n != 0) {
        vector<Point> vertices;
        for (int i = 0; i < n; i++) {
            Point p;
            cin >> p.x >> p.y;
            vertices.push_back(p);
        }
        float area = GetArea(&vertices);
        if (area < 0) {
            printf("CCW %.1f\n", area * -1);

        } else {
            printf("CW %.1f\n", area);
        }

        cin >> n;
    }
}