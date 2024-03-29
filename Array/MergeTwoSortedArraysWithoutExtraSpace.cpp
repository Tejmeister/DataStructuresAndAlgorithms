#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
	int getGap(int gap){
		if(gap <= 1)
			return 0;
		return (gap/2) + (gap%2);
	}

public:
	// Gives TLE
	void mergeTLE(int arr1[], int arr2[], int n, int m) {
	    // code here
	    for(int i=m-1; i>= 0; i--){
	        int j, last = arr1[n-1];
	        for(j = n-2; j>=0 && arr1[j] > arr2[i]; j--){
	            arr1[j+1] = arr1[j];
	        }
	        
	        if(j!=(n-2) || last > arr2[i]){
	            arr1[j+1] = arr2[i];
	            arr2[i] = last;
	        }
	    }
	}

	void merge2(int arr1[], int arr2[], int n, int m){
		int gap = n + m;
		int i, j;

		for(gap = getGap(gap); gap>0; gap = getGap(gap)){
			for(i=0; i+gap<n; i++){
				if(arr1[i] > arr1[i+gap]){
					swap(arr1[i], arr1[i+gap]);
				}
			}

			for(j=gap > n ? gap-n : 0; i<n && j<m; i++, j++){
				if(arr1[i] > arr2[j]){
					swap(arr1[i], arr2[j]);
				}
			}

			if(j < m){
				for(j=0; j+gap<m; j++){
					if(arr2[j] > arr2[j+gap]){
						swap(arr2[j], arr2[j+gap]);
					}
				}
			}
		}
	}
};

int main()
{
    int a1[] = { 10, 27, 38, 43, 82 };
    int a2[] = { 3, 9 };
    int n = sizeof(a1) / sizeof(int);
    int m = sizeof(a2) / sizeof(int);
 
    Solution s;

    // Function Call
    s.merge2(a1, a2, n, m);
 
    printf("First Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a1[i]);
 
    printf("\nSecond Array: ");
    for (int i = 0; i < m; i++)
        printf("%d ", a2[i]);
    printf("\n");
    return 0;
}