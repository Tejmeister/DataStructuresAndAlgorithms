#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static comparator(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    
    bool static comparatorDescending(vector<int> a, vector<int> b){
        return a[0] >= b[0];
    }
    
    // Extra space 0(N)
    vector<vector<int> > merge(vector<vector<int> >& intervals){
        int size = intervals.size();
        
        if(size <= 1)
            return intervals;
        
        // sort based on starting times
        sort(intervals.begin(), intervals.end(), comparator);
        
        vector<vector<int> > result;
        
        result.push_back(intervals[0]);
        
        for(int i=1; i<size; i++){
            vector<int> latest = result.back();
            
            // If ending time of latest interval is less than starting time of current interval then simply push to result because there is no overlap
            if(latest[1] < intervals[i][0])
                result.push_back(intervals[i]);
            
            else if(latest[1] < intervals[i][1]){
                latest[1] = intervals[i][1];
                result.pop_back();
                result.push_back(latest);
            } 
        }
        
        return result;
    }
    
    // No extra space O(1)
    // But TLE since erase operation is costly
    vector<vector<int> > mergeNoExtraSpaceButTLE(vector<vector<int> >& intervals) {
        int size = intervals.size();
        
        if(size <= 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), comparator);
        
        int index = 0;
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[index][1] >= intervals[i][0]){
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);
                i--;
            }
            else{
                index = i;
            }
        }
            
        return intervals;
    }
};


int main(){
    vector<vector<int> > intervals;
    vector<int> temp(2);
    // [[1,3],[2,6],[8,10],[15,18]]
    temp[0] = 1;
    temp[1] = 3;
    intervals.push_back(temp);
    temp[0] = 2;
    temp[1] = 6;
    intervals.push_back(temp);
    temp[0] = 8;
    temp[1] = 10;
    intervals.push_back(temp);
    temp[0] = 15;
    temp[1] = 18;
    intervals.push_back(temp);

    Solution s;

    intervals = s.merge(intervals);

    for(int i=0; i<intervals.size(); i++){
        
        cout<<"["<<intervals[i][0]<<", "<<intervals[i][1]<<"]";
        
        cout<<" ";
    }

    return 0;
}