#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chocolateDistribution(vector<int>& arr, int m) {
        int n = arr.size();
        if(n < m)
            return -1;
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;

        for(int i=0; i+m-1<n; i++){
            if(arr[i+m-1] - arr[i] < minDiff)
                minDiff = arr[i+m-1] - arr[i];
        }

        return minDiff;
    }
};

int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(9);
    arr.push_back(56);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(12);

    int numOfStudents =5;

    Solution s;
    cout<<s.chocolateDistribution(arr, numOfStudents);

}