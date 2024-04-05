#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMajorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    int majorityElement = 0;
    int maxCount = 0;

    for (int num : nums) {
        count[num]++;
        if (count[num] > maxCount) {
            maxCount = count[num];
            majorityElement = num;
        }
    }

    return majorityElement;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int majorityElement = findMajorityElement(nums);

    cout << "Majority element: " << majorityElement << endl;

    return 0;
}
