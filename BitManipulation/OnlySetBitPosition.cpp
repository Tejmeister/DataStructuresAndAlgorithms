#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int log2N(int n){
        return (n>1) ? 1 + log2N(n/2): 0;
    } 
    
    bool isPowerOfTwo(int n){
        return (n>0 && !(n&(n-1)));
    }
  public:
    int findPosition(int N) {
        // code here
        if(!isPowerOfTwo(N))
            return -1;
        return log2N(N) + 1;
    }
};	

int main(){
	Solution s;
	cout<<"38: "<<s.findPosition(38)<<endl;
	cout<<"8: "<<s.findPosition(8)<<endl;
	return 0;
}
