/*
    maximum table radius is when chord with angle (clinksPerPerson * Θ) has length 2*d
    minimum table radius is when chord with angle ((clinksPerPerson+1) * Θ) has length 2*d

    we have
        - chord length  (l)
        - chord angle   (Θ)
    need
        - radius        (r)

    chord formula
        l = 2r sin(Θ/2)
        r = 1/2sin(Θ/2)

        l = 2d so
        2d/2sin(Θ/2) = r
        d/sin(Θ/2) = r
*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    // n = number of people around table
    // d = radius of each person
    // t = number of clink sounds
    int n, d, t, clinksPerPerson;
    double angleBetweenPeople, minR, maxR;
    cin >> n >> d >> t;

    angleBetweenPeople = (2 * M_PI) / n; // radians
    clinksPerPerson    = t * 2 / n;      // might only need half (used to be (t*2)/n)
    if (clinksPerPerson + 1 == n) {
        minR = 0;
        maxR = d;
    } else {

        minR = d / sin((clinksPerPerson / 2 + 1) * angleBetweenPeople / 2);
        maxR = d / sin(clinksPerPerson / 2 * angleBetweenPeople / 2);
    }
    printf("%.5lf %.5lf\n", minR, maxR);
}