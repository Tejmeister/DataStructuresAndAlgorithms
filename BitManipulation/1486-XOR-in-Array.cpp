#include<bits/stdc++.h>

using namespace std;	

class Solution {
public:
    int xorOperation(int n, int start) {
        int x = start;
        for(int i=1; i<n; i++){
            x = x^(start+2*i);
        }
        return x;
    }
};


int main(){
	Solution s;
	cout<<s.xorOperation(5, 0);
	return 0;
}