#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[], int N){
    for(int i=0; i<N; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


// Bubble Sort

void BubbleSort(int arr[], int N){
	for(int i=0; i<N-1; i++){
		for(int j=0; j<N-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

// Optimized bubble sort

void OptimizedBubbleSort(int arr[], int N){
	for(int i=0; i<N-1; i++){
		bool swapped = false;
		for(int j=0; j<N-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		if(swapped == false)
			break;
	}
}

// Selection Sort

void SelectionSort(int arr[], int N){
	int min_index = 0;
	for(int i=0; i<N-1; i++){
		min_index = i;
		for(int j=i+1; j<N; j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(arr[i], arr[min_index]);
	}
}

// Insertion Sort

void InsertionSort(int arr[], int N){

}


int main()
 {
	//code
  	int arr[] = {12,21,5,351,98,122,39,87,53,90,17,68};
  	int size = sizeof(arr)/sizeof(arr[0]);
  	printArray(arr,size);
  	SelectionSort(arr,size);
  	printArray(arr,size);
	return 0;
}