// https://open.kattis.com/problems/bokforing

#include <iostream>
#include <map>
using namespace std;

int defaultAmount;
map<int, int> people;

void SET(int person, int amount) { people[person] = amount; }

void RESTART(int amount) {
    people.clear();
    defaultAmount = amount;
}

void PRINT(int person) {
    if (people.count(person) != 0) {
        cout << people[person] << endl;
    } else {
        cout << defaultAmount << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    int Q;

    cin >> N >> Q;

    string instruction;
    int a;
    int b;

    for (int i = 0; i < Q; i++) {
        cin >> instruction;
        cin >> a;
        if (instruction.compare("SET") == 0) {
            cin >> b;
            SET(a, b);
        } else if (instruction.compare("RESTART") == 0) {
            RESTART(a);
        } else if (instruction.compare("PRINT") == 0) {
            PRINT(a);
        }
    }
}