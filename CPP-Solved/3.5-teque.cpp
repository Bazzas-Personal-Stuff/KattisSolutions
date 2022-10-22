// https://open.kattis.com/problems/teque

/*
1. push_back x: insert the element 𝑥 into the back of the teque.
2. push_front x: insert the element 𝑥 into the front of the teque.
3. push_middle x: insert the element 𝑥 into the middle of the teque.
The inserted element 𝑥 now becomes the new middle element of the teque.
If 𝑘 is the size of the teque before the insertion, the insertion index for 𝑥 is (𝑘+1)/2 (using 0-based indexing).
*/

#include <deque>
#include <iostream>
#include <string>

using namespace std;
deque<int> frontHalf, backHalf;

void balance() {
    int expected   = (frontHalf.size() + backHalf.size() + 1) / 2;
    int difference = frontHalf.size() - expected;
    int toMove;
    if (difference > 0) {
        toMove = frontHalf.back();
        backHalf.push_front(toMove);
        frontHalf.pop_back();
    } else if (difference < 0) {
        toMove = backHalf.front();
        frontHalf.push_back(toMove);
        backHalf.pop_front();
    }
}

void push_back(int element) {
    balance();
    backHalf.push_back(element);
}

void push_front(int element) {
    balance();
    frontHalf.push_front(element);
}

void push_middle(int element) {
    balance();
    backHalf.push_front(element);
}

int get(int index) {
    if (index < frontHalf.size()) {
        return frontHalf[index];
    } else {
        return backHalf[index - frontHalf.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string instruction;
    int value;

    for (int i = 0; i < n; i++) {
        cin >> instruction >> value;
        if (instruction.compare("get") == 0) {
            cout << get(value) << '\n';
        } else if (instruction.compare("push_back") == 0) {
            push_back(value);
        } else if (instruction.compare("push_front") == 0) {
            push_front(value);
        } else if (instruction.compare("push_middle") == 0) {
            push_middle(value);
        }
    }
}
