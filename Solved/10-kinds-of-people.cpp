#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

/*
    World map is stored as a 2d array of chars
    We only need one bit to store world information, so a "visited" flag
    can be stored in the second bit, used for pathfinding.

    0000 0011
           │└─ value (binary/decimal)
           └── "visited" flag

    Value and flag can be accessed with bitwise AND
        char value = world[x][y] & 1;
        bool flag = world[x][y] & 2 == 2;

    When both origin and destination coordinates have not been identified, the origin is scanned
    to find immediately adjacent elements with the same type.
    Each coordinate is stored in a map when it is traversed (this is probably inefficient)
    along with its sector ID, which is incremented after a sector is scanned.
    If two coordinates already exist in the map and their sector IDs are identical, there must be a
    path between them.
    If only one coordinate exists in the map, OR the coordinates have differing sector IDs,
    the coordinates don't exist in the same sector and so there is no path between them.
*/

vector<vector<char>> world;
bool checkValidPoint(pair<int, int> point, char type)
{
    if ((point.first >= 0) && (point.first < world.size()) &&
        (point.second >= 0) && (point.second < world[0].size()))
    { // in map bounds
        char element = world[point.first][point.second];
        if ((element & 2) != 2 &&
            (element & 1) == type)
        { // not visited and same type
            return true;
        }
    }
    return false;
}

int main()
{
    map<pair<int, int>, int> sectorMap;

    int columnMax, rowMax;
    cin >> rowMax >> columnMax;
    for (int i = 0; i < rowMax; i++)
    {
        vector<char> temp;
        for (int j = 0; j < columnMax; j++)
        {
            char c;
            cin >> c;
            c -= '0'; // convert from ascii to number
            temp.push_back(c);
        }
        world.push_back(temp);
    }

    int queryCount;
    int sectorCount = 0;
    cin >> queryCount;
    for (int i = 0; i < queryCount; i++)
    {
        pair<int, int> origin, destination;
        string originString;
        cin >> origin.first >> origin.second >> destination.first >>
            destination.second;

        // normalize to start at 0
        origin.first--;
        origin.second--;
        destination.first--;
        destination.second--;

        char originType = world[origin.first][origin.second] & 1;
        if (originType == 0)
        {
            originString = "binary";
        }
        else
        {
            originString = "decimal";
        }

        // don't need to pathfind if they're different types
        if (world[origin.first][origin.second] !=
            world[destination.first][destination.second])
        {
            cout << "neither\n";
            continue;
        }

        // check if points are already in mapped sectors
        int originInMap = sectorMap.count(origin);
        int destinationInMap = sectorMap.count(destination);

        // if both are not in map, scan from origin first before continuing.
        if (originInMap == 0 && destinationInMap == 0)
        {
            vector<pair<int, int>> thisIter;
            vector<pair<int, int>> nextIter;
            thisIter.push_back(origin);
            world[origin.first][origin.second] |= 2;
            while (!thisIter.empty())
            {
                for (int i = 0; i < thisIter.size(); i++)
                {

                    pair<int, int> coord = thisIter[i];
                    sectorMap.insert(
                        pair<pair<int, int>, int>(coord, sectorCount));
                    pair<int, int> n = coord, s = coord, e = coord, w = coord;
                    n.second++;
                    s.second--;
                    e.first++;
                    w.first--;
                    vector<pair<int, int>> possible = {n, s, e, w};

                    for (pair<int, int> p : possible)
                    {
                        if (checkValidPoint(p, originType))
                        {
                            nextIter.push_back(p);
                            world[p.first][p.second] |= 2;
                        }
                    }
                }
                thisIter.swap(nextIter);
                nextIter.clear();
            }
            originInMap = sectorMap.count(origin);
            destinationInMap = sectorMap.count(destination);
            sectorCount++;
        }

        // if they both are, check sector id
        if (originInMap > 0 && destinationInMap > 0)
        {
            if (sectorMap[origin] == sectorMap[destination])
            {
                cout << originString << '\n';
            }
            else
            {
                cout << "neither\n";
            }
        }
        // if only one is, they're in different sectors
        else
        {
            cout << "neither\n";
        }
    }
}