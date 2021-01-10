// UNFINISHED

#include <iostream>
#include <vector>
using namespace std;

void subsetSums(vector<int> nums, int l, int r, int sum = 0) {
    // Print current subset
    if (l > r) {
        cout << sum << " ";
        return;
    }

    // Subset including arr[l]
    subsetSums(nums, l + 1, r, sum + nums[l]);

    // Subset excluding arr[l]
    subsetSums(nums, l + 1, r, sum);
}

int main() {
    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        cout << "Case #" << t + 1 << ":"
             << "\n";
        vector<int> set;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int j;
            cin >> j;
            set.push_back(j);
        }
        // do stuff here for each case
        subsetSums(set, 0, set.size() - 1);

        return 0;
    }
}
