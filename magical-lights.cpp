// magical colour = number of nodes with colour is odd (within subtree)
// when K == 0, print magical colours in subtree of X (parent node)

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
        if (parent != NULL) {
            parent->flipColourParent(colour1, colour2);
        }
    }

    void setColour(int colour) {
        flipColourParent(baseColour, colour);
        baseColour = colour;
    }
    void initializeChildren() {
        for (node *child : children) {
            child->initializeChildren();
            magicColours ^= child->magicColours;
        }
    }
};

int main() {
    int n, q, K, X;
    cin >> n >> q;
    vector<node> allNodes(n);
    // initialize colours
    for (int i = 0; i < n; i++) {
        int colour;
        cin >> colour;
        colour--;
        allNodes[i].magicColours[colour] = 1;
        allNodes[i].baseColour           = colour;
    }

    // get parents of node i
    // NOTE: node identifier has been normalized here (starts at 0)
    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;
        allNodes[i + 1].parent = &allNodes[p - 1];
        allNodes[p - 1].children.push_back(&allNodes[i + 1]);
    }

    allNodes[0].initializeChildren();

    for (int i = 0; i < q; i++) {
        cin >> K >> X;
        X--;
        if (K == 0) {
            cout << allNodes[X].magicColours.count() << '\n';
        } // query
        else {
            K--;
            allNodes[X].setColour(K);
        } // set colour
    }
}