#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int maximumSumSubArray(vector<int> arr){
		int max_so_far = INT_MIN;
		int max_ending_here = 0;

		for(int i=0;i<arr.size(); i++){
			max_ending_here += arr[i];
			if(max_ending_here > max_so_far)
				max_so_far = max_ending_here;
			if(max_ending_here < 0)
				max_ending_here = 0;
		}

		return max_so_far;
	}
};

int main(){
	vector<int> arr;
	arr.push_back(-2);
	arr.push_back(1);
	arr.push_back(-3);
	arr.push_back(4);
	arr.push_back(-1);
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(-5);
	arr.push_back(4);

	
	Solution s;
	cout<<s.maximumSumSubArray(arr)<<endl;
}