#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countSetBitsUtil(int n){
		int count = 0;
		while(n){
			n = n&(n-1);
			count++;
		}
		return count;
	}

	vector<int> countSetBitsAllBrute(int n){
		vector<int> result;
		for(int i=0; i<=n; i++){
			result.push_back(countSetBitsUtil(i));
		}

		return result;
	}

	vector<int> countSetBitsAllDP(int n){
		vector<int> DP(n+1, 0);

		DP[0] = 0;

		if(n == 0)
			return DP;
		DP[1] = 1;

		for(int i=2; i<=n; i++){
			if(i&1)
				DP[i] = DP[i/2] + 1;
			else
				DP[i] = DP[i/2];
		}

		return DP;
	}

    vector<int> countSetBits(int n) {
        return countSetBitsAllDP(n);
    }
};

int main(){
	Solution s;
	vector<int> result = s.countSetBits(5);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<" ";

	return 0;
}