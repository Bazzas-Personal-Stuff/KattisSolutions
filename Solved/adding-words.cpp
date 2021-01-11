#include <iostream>
#include <map>
using namespace std;
enum stringCode
{
    eDef,
    eCalc,
    eClear,
    eUndefined,
};

stringCode getCode(string command)
{
    if (command == "def")
        return eDef;
    if (command == "calc")
        return eCalc;
    if (command == "clear")
        return eClear;
    return eUndefined;
}

int main()
{
    map<string, int> m;

    while (!cin.eof())
    {

        string command;
        cin >> command;
        stringCode commandCode = getCode(command);
        string var;
        string op;
        int val;
        int sum;
        bool undef;
        bool inMap = false;
        switch (commandCode)
        {
        case eDef:
            cin >> var;
            cin >> val;

            m[var] = val;

            break;
        case eCalc:

            val = 0;
            
            undef = false;
            cin >> var;
            cout << var << ' ';

            if (m.find(var) != m.end()) {
                // Check if var in m before this
                val = m[var];
                sum = val;
            } else {
                undef = true;
            }

            while (true)
            {
                cin >> op;
                cout << op << ' ';

                if (op != "=")
                {
                    cin >> var;
                    cout << var << ' ';

                    if (m.find(var) != m.end())
                    {
                        val = m[var];
                        if (op == "+")
                        {
                            sum += val;
                        }
                        else if (op == "-")
                        {
                            sum -= val;
                        }
                    }
                    else
                    {
                        undef = true;
                    }
                }
                else
                {
                    break;
                }
            }

            if (undef == true)
            {
                cout << "unknown\n";
                break;
            }

            // Do reverse lookup
            inMap = false;
            for (auto item : m)
            {
                if (item.second == sum && item.first != "")
                {
                    cout << item.first << "\n";
                    inMap = true;
                    break;
                }
            }
            // If reverse lookup fails
            if (!inMap)
                cout << "unknown\n";
            break;
        case eClear:
            m.clear();
            break;
        default:
            //cout << "Command not recognised\n";
            break;
        }
    }

    return 0;
}
