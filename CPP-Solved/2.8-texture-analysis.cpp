#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {

    string pixels;
    int iter = 1;
    while (getline(cin, pixels)) {
        if (pixels[0] == 'E')
            return 0;
        cout << iter++;
        if (pixels.length() == 1) {
            cout << " EVEN\n";
            continue;
        }

        int initialWhitespace = 0;
        int whiteSinceLast = 0;

        int i = 1;
        char c = '?';
        while (c != '*') {
            c = pixels[i];
            if (c == '.') {
                initialWhitespace++;
            }
            i++;
        }
        for (; i < pixels.length(); i++) {
            c = pixels[i];
            if (c == '.') {
                whiteSinceLast++;
            } else if (c == '*') {
                if (whiteSinceLast != initialWhitespace) {
                    cout << " NOT";
                    break;
                } else {
                    whiteSinceLast = 0;
                }
            }
        }
        cout << " EVEN\n";
    }
}