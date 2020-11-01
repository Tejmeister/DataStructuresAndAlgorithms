#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return ( n>0 && !(n&n-1));
    }
};

int main(){
	Solution s;
	cout<<"8: "<<s.isPowerOfTwo(8)<<endl;
	cout<<"9: "<<s.isPowerOfTwo(9)<<endl;
	return 0;
}