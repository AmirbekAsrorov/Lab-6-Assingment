#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sortArray(vector<int>& arr, int n) {
    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even.push_back(arr[i]);
        } else {
            odd.push_back(arr[i]);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());

    int evenIndex = 0;
    int oddIndex = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            arr[i] = even[evenIndex];
            evenIndex++;
        } else {
            arr[i] = odd[oddIndex];
            oddIndex++;
        }
    }
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

    sortArray(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
