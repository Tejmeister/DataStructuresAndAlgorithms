#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int KthSmallest(vector<int> arr, int k){
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
	arr.push_back(7);
	arr.push_back(10);
	arr.push_back(4);
	//arr.push_back(3);
	arr.push_back(20);
	arr.push_back(15);


	int k = 4;

	Solution s;
	cout<<s.KthSmallest(arr, arr.size()-k+1)<<endl;
}