// https://open.kattis.com/problems/kattissquest

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int count;
    map<int, priority_queue<int>, greater<int>> energyMap;

    cin >> count;

    for (int i = 0; i < count; i++)
    {

        string cmd;
        cin >> cmd;
        if (cmd == "add")
        {
            int energy, gold;
            cin >> energy >> gold;
            if (energyMap.count(energy) == 0)
            {
                energyMap[energy] = priority_queue<int>();
            }
            energyMap[energy].push(gold);
        }
        else
        {
            //  query

            //  rather than iterating over every element of the map,
            //  we can leverage the map's tree properties to search for the next key we need
            //  with logarithmic time complexity.

            int energy;
            long int thisGold = 0;
            cin >> energy;
            map<int, priority_queue<int>>::iterator it;
            for (it = energyMap.begin(); it != energyMap.end(); it = energyMap.lower_bound(energy))
            {
                if (it->first <= energy)
                {
                    while (it->first <= energy)
                    {
                        energy -= it->first;
                        thisGold += it->second.top();
                        it->second.pop();
                        if (it->second.size() == 0)
                        {
                            it = energyMap.erase(it);
                            break;
                        }
                    }
                }
            }
            cout << thisGold << "\n";
        }
    }

    return 0;
}
