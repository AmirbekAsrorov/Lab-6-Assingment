#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findMinAbsDiffPairs(vector<int>& arr, int index, int minDiff, vector<vector<int>>& pairs){
    if(index>=arr.size()){
        return;
    }
    if (index>0){
        int diff=arr[index]-arr[index-1];
        if(diff<minDiff){
            minDiff=diff;
            pairs.clear();
            pairs.push_back({arr[index-1], arr[index]});
        } else if(diff==minDiff){
            pairs.push_back({arr[index-1], arr[index]});
        }
    }
    findMinAbsDiffPairs(arr, index+1, minDiff, pairs);
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<vector<int>> minAbsDiffPairs;
    findMinAbsDiffPairs(arr, 1, arr[1] - arr[0], minAbsDiffPairs);
    //cout << "Pairs with minimum absolute difference:" << endl;
    for (const vector<int>& pair : minAbsDiffPairs) {
        cout  << pair[0] << " " << pair[1]  << endl;
    }
    return 0;
}
