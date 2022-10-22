// https://open.kattis.com/problems/acm

#include <iostream>
#include <map>

using namespace std;

class Stats{
    public:
        int penalties;
        int finalSubTime;
        bool solved = false;
        Stats(){}


};


int main(){
    int timePenalty = 20;
    map<char, Stats> attempts;
    int timer = 0;
    while (true){
        int entry;
        cin >> entry;

        if (entry != -1){
            int minutes = entry;
            char problem;
            string result;
            cin >> problem;
            cin >> result;

            if(result == "right"){
                attempts[problem].solved = true;
                attempts[problem].finalSubTime = minutes;
            } else{
                attempts[problem].penalties++;
            }

        }
        else break;
    }


    int solves = 0;
    for(auto item : attempts){
        if(item.second.solved) {
            timer+= item.second.finalSubTime;
            timer += item.second.penalties * timePenalty;
            solves++;
        }
    }
    cout << solves << ' ' << timer;

    return 0;
}