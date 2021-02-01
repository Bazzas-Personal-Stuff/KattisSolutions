/*





    find x for

    y = x^p
    if(p rt y)

    25 = x^2
    25 = 5^2
    if p root y < 2, the power can't get any higher.
*/

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int y;
    while (cin >> y) {
        if (y == 0)
            break;
        int prevWorkingPow = 1;
        for (int p = 2;; p++) {
            double root = pow(y, 1.0 / p);

            if (root < 2)
                break;
            if (trunc(root) == root) {
                prevWorkingPow = p;
            }
        }
        cout << prevWorkingPow << '\n';
    }
}