#include<bits/stdc++.h>

using namespace std;

bool isMajority(vector<int> v, int target){
	int n = v.size();
	int start = lower_bound(v.begin(), v.end(), target) - v.begin();
	int end = upper_bound(v.begin(), v.end(), target) - v.begin() - 1;
	cout<<"start: "<<start<<endl;
	cout<<"end: "<<end<<endl;
	if(0 <= start && start <= n && 0 <= end && end <= n){
		if(v[start] == v[end] && v[start] == target){
			if(end-start +1> n/2)
				return true;
		}
	}
	return false;
}

void fizzBuzz(int n){
	for(int i=1; i<=n; i++){
		if(i%15 == 0)
			cout<<setw(15)<<"FizzBuzz"<<"\t";
		else if(i%3 == 0)
			cout<<setw(15)<<"Fizz"<<"\t";
		else if(i%5 == 0)
			cout<<setw(15)<<"Buzz"<<"\t";
		else
			cout<<setw(15)<<i<<"\t";
	}
}

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);

	//cout<<isMajority(v,4);
	fizzBuzz(100);
	return 0;
}