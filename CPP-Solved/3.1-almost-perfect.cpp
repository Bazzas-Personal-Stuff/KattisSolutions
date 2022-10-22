// https://open.kattis.com/problems/almostperfect

#include <cmath>
#include <iostream>

using namespace std;

long long sumDivisors(long long input) {
    long long sum    = 0; // We start it as 0 as 1 gets counted in the first for loop interation {sum += i}
    double inputSqrt = sqrt(input);
    for (int i = 1; i <= inputSqrt; i++) {
        if (input % i == 0) {
            if (i == inputSqrt) {
                sum += i;
            } else {
                sum += i;
                sum += input / i;
            }
        }
    }
    sum -= input;
    /*We subtract the input as in the first for loop iteration it adds the input.
        In the almost perfect example for 28 it is 1,2,4,7, and 14. Noting 28 is not included.
        sum += input/i in the first iteration adds 28/1 = 28. Therefore the importance of sum -== input.
    */
    return sum;
}

int main() {
    long long n;
    while (cin >> n) {
        long long d = sumDivisors(n);
        if (n == d) {
            cout << n << " perfect" << endl;
        } else if (abs(n - d) <= 2) {
            cout << n << " almost perfect" << endl;
        } else {
            cout << n << " not perfect" << endl;
        }
    }
}