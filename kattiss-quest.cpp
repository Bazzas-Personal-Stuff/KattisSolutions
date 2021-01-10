// UNFINISHED

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct quest {
    int e;
    int g;
};

bool egComparator(quest a, quest b) {
    if (a.e == b.e) {
        return a.g > b.g;
    } else
        return a.e > b.e;
};
int main() {
    int count;
    cin >> count;

    // vector<quest> entries;
    set<quest, decltype(egComparator) *> entries(egComparator);

    for (int i = 0; i < count; i++) {

        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int a, b;
            cin >> a >> b;
            quest temp;
            temp.e = a;
            temp.g = b;
            entries.insert(temp);
        } else {
            // query
            // sort(entries.begin(), entries.end(), egComparator);
            int energy;
            int thisGold = 0;
            cin >> energy;

            // print out quest database every query
            /*
            cout << "Current quest database: " << '\n';
            for (int j = 0; j < entries.size(); j++) {
                quest q = entries[j];
                cout << "E: " << q.e << "\tG: " << q.g << '\n';
            }
            cout << "Querying with " << energy << " energy:" << '\n';
            */
            /*
             for (int j = 0; j < entries.size(); j++) {
                 if (entries[j].e <= energy) {
                     thisGold += entries[j].g;
                     energy -= entries[j].e;
                     entries.erase(entries.begin() + j);
                     j--;
                 }
             }
             */
            set<quest>::iterator it;
            set<quest>::iterator end = entries.end();
            for (it = entries.begin(); it != end; it++) {
                quest q = *it;
                if (q.e <= energy) {
                    thisGold += q.g;
                    energy -= q.e;
                    // entries.erase(it);
                    // it--;
                    end = entries.end();
                }
            }
            cout << thisGold << "\n";
        }
    }

    return 0;
}
