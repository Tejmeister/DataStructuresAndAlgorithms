#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int countSetBits(int n){
		int count = 0;
		while(n){
			n = n & (n-1);
			count++;
		}

		return count;
	}
};


int main(){

	Solution s;
	cout<<s.countSetBits(5);
	return 0;
}