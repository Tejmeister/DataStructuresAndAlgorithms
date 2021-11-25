#include <iostream>

using namespace std;

bool isSubsequence(string s, string t){
    int n = s.size();
    int m = t.size();
    
    int i = 0;
    for(int j = 0; j<m && i<n; j++){
        if(s[i] == t[j])
            i++;
    }
    
    return i == n;
}

int repeatingCount(string A, string B){
    // returns true if A repeated k times, then B is subsequence of A
    int count = 1;
    int LIMIT = 100;

    int bLen = B.size();
    string S = A;    
    while(S.size() < bLen){
        S += A;
        count++;
    }
    
    if(isSubsequence(B, S))
        return count;
        
    while(!isSubsequence(B, S) && count < LIMIT){
        S = S + A;
        count++;
    }
        
    return count == LIMIT? -1 : count;
}

int main()
{
    string s = "abc";
    string t = "ababababaaa";
    
    cout<<repeatingCount(s, t);

    return 0;
}