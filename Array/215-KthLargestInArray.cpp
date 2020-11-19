#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int KthLargest(vector<int> arr, int k){
		priority_queue<int, vector<int>, greater<int> > pq;

		for(int i=0; i<arr.size(); i++){
			if(pq.size() < k){
				pq.push(arr[i]);
			}
			else{
				if(pq.top() < arr[i]){
					pq.pop();
					pq.push(arr[i]);
				}
			}
		}

		return pq.top();
	}
};

int main(){
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(5);
	arr.push_back(6);

	int k = 4;

	Solution s;
	cout<<s.KthLargest(arr, k)<<endl;
}