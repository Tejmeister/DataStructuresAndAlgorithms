#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int countSetBits(int n){
    int count = 0;
    while(n){
		n = n&(n-1);
		count++;
    }
	
	return count;
  }
  
  public:
  int minimumFlipsToConvertAtoB(int A, int B){
	int C = A^B;
	return countSetBits(C);
  }
};


int main(){
	int T;
	while(T){
		int A, B;
		cin>>A>>B;
		cout<<minimumFlipsToConvertAtoB(A,B)<<endl;
		T--;
	}
	return 0;
}	
