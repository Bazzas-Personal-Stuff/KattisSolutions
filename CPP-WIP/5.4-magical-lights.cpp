// magical colour = number of nodes with colour is odd (within subtree)
// when k == 0, print magical colours in subtree of X (parent node)

#include <bitset>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class node {
  public:
    node *parent = NULL;
    vector<node *> children;
    bitset<100> magicColours;
    int baseColour;

    void flipColourParent(int colour1, int colour2) {

        magicColours.flip(colour1);
        magicColours.flip(colour2);
        if (parent != NULL && parent->magicColours.any()) {
            parent->flipColourParent(colour1, colour2);
        }
    }

    void setColour(int colour) {
        flipColourParent(baseColour, colour);
        baseColour = colour;
    }
    void calculateChildren() {
        if (magicColours.none()) {
            magicColours[baseColour] = 1;
            for (node *child : children) {
                child->calculateChildren();
                magicColours ^= child->magicColours;
            }
        }
    }
};

int main() {
    int n, q, k, x;
    cin >> n >> q;
    vector<node> allNodes(n);
    // initialize colours
    for (int i = 0; i < n; i++) {
        int colour;
        cin >> colour;
        colour--;
        allNodes[i].baseColour = colour;
    }

    // get parents of node i
    // NOTE: node identifier has been normalized here (starts at 0)
    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;
        p--;
        allNodes[i + 1].parent = &allNodes[p];
        allNodes[p].children.push_back(&allNodes[i + 1]);
    }

    for (int i = 0; i < q; i++) {
        cin >> k >> x;
        x--;
        if (k == 0) { // query
            allNodes[x].calculateChildren();
            cout << allNodes[x].magicColours.count() << '\n';
        } else { // set
            k--;
            allNodes[x].setColour(k);
        }
    }
}