#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findMinAbsDiffPairs(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int minDiff = INT_MAX;
    vector<vector<int>> pairs;

    for (int i = 1; i < arr.size(); i++) {
        int diff = arr[i] - arr[i - 1];

        if (diff < minDiff) {
            minDiff = diff;
            pairs.clear();
            pairs.push_back({arr[i - 1], arr[i]});
        } else if (diff == minDiff) {
            pairs.push_back({arr[i - 1], arr[i]});
        }
    }

    return pairs;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> minAbsDiffPairs = findMinAbsDiffPairs(arr);

    cout << "Pairs with minimum absolute difference:" << endl;
    for (const vector<int>& pair : minAbsDiffPairs) {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }

    return 0;
}
