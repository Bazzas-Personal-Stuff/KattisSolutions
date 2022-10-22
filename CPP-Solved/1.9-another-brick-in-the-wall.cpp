// https://open.kattis.com/problems/anotherbrick

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    
    bool badWidth = false;
    bool badHeight = false;
    int temp = 0;
    int currentWidth = 0, currentHeight = 0;
    while(cin){
        cin >> temp;
        currentWidth += temp;
        if(currentWidth > w){
            badWidth = true;
            break;
        }
        if(currentWidth == w){
            currentWidth = 0;
            currentHeight++;
            if(currentHeight == h) break;
        }
    }

    badHeight = !(currentHeight == h);
    if(!badWidth && !badHeight){
        cout << "YES" << '\n';
        //cout << "current height " << currentHeight << "\ttarget height " << h << '\n';
    }    
    //else cout << "NO" << "bad width? " <<  badWidth << " bad height? " << badHeight << '\n';
    else cout << "NO" << '\n';
    return 0;
}
