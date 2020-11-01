#include<bits/stdc++.h>
using namespace std;

int main(){

	int a = 5;
	int *p;
	p = &a;
	cout<<"a	"<<a<<endl;
	cout<<"p	"<<p<<endl;
	cout<<"&a	"<<&a<<endl;
	cout<<"&p	"<<&p<<endl;
	cout<<"*p	"<<*p<<endl;
	*p = 12;
	cout<<"*p	"<<*p<<endl;
	cout<<"a	"<<a<<endl;
	return 0;
}