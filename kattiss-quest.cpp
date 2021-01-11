// UNFINISHED

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
    map<int, priority_queue<int>> energyMap;

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
            // query

            int energy;
            long int thisGold = 0;
            cin >> energy;
            map<int, priority_queue<int>>::reverse_iterator it, end;
            for (it = energyMap.rbegin(); it != energyMap.rend();)
            {
                bool hasErased = false;
                while (it->first <= energy && !it->second.empty())
                {
                    thisGold += it->second.top();
                    energy -= it->first;
                    it->second.pop();
                    if (it->second.empty())
                    {
                        energyMap.erase(next(it).base());
                        // hasErased = true;
                        break;
                    }
                }
                if (!hasErased)
                {
                    ++it;
                }
            }

            cout << thisGold << "\n";
        }
    }

    return 0;
}
