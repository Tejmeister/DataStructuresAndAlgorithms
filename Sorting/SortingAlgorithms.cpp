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
	int hole, currentValue;
	for(int i=1; i<N; i++){
		currentValue = arr[i];
		hole = i;
		for(int j=i-1; j<N; j++){
			while(hole > 0 && arr[hole-1] > currentValue){
				arr[hole] = arr[hole-1];
				hole--;
			}
		}
		arr[hole] = currentValue;
	}
}

// Count number of passed in Bubble Sort

void SwapsInBubbleSort(int arr[], int N){
	int swaps = 0;
	for(int i=0; i<N-1; i++){
		for(int j=0; j<N-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swaps++;
			}
		}
	}
	cout<<"Number of swaps: " <<swaps<<endl;
}

// Quick Sort
// partition function
int partition(int arr[], int start, int end){
	int pivot = arr[end];
	int pivot_index = start;
	for(int j=start; j<end; j++){
		if(arr[j] < pivot){
			swap(arr[pivot_index], arr[j]);
			pivot_index++;
		}
	}
	swap(arr[end], arr[pivot_index]);

	return pivot_index;
}
// sort function
int QuickSort(int arr[], int start, int end){
	int pivot_index;
	if(start < end){
		pivot_index = partition(arr,start,end);

		QuickSort(arr,start,pivot_index-1);
		QuickSort(arr,pivot_index+1,end);
	}
	return 0;
}

// Merge Sort
// merge function
void merge(int arr[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;	
	int left[n1];
	int right[n2];
	for(int i=0; i<n1; i++)
		left[i] = arr[l+i];
	for(int i=0; i<n2; i++)
		right[i] = arr[m+i+1];
	int i = 0;
	int j = 0;
	int k = l;
	while(i<n1 && j <n2){
		if(left[i] <= right[j]){
			arr[k++] = left[i++];
		}
		else if(left[i] > right[j]){
			arr[k++] = right[j++];
		}
	}

	while(i<n1){
		arr[k++] = left[i++];
	}

	while(j<n2){
		arr[k++] = right[j++];
	}

}
// sort function
void MergeSort(int arr[], int l, int r){
	if(l<r){
		int m = (l+r)/2;

		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}

// Count Inversion
int countInversion(int arr[], int N){
	int count = 0;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++)
			if(arr[i] > arr[j])
				count++;
	}

	return count;
}

int inversionMerge(int arr[], int temp[], int start, int mid, int end){
	int invCount = 0;

	int i = start;
	int j = mid;
	int k = start;

	while(i<mid && j<=end){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];

			invCount = invCount + (mid - i);
		}
	}

	while(i < mid){
		temp[k++] = arr[i++];
	}

	while(j <= end){
		temp[k++] = arr[j++];
	}

	for(i = start; i<=end; i++){
		arr[i] = temp[i];
	}

	return invCount;
}

int inversionUsingMergeSort(int arr[], int temp[], int start, int end){
	int mid, invCount = 0;
	if(start < end){
		mid = start + (end-start)/2;

		invCount += inversionUsingMergeSort(arr, temp, start, mid);
		invCount += inversionUsingMergeSort(arr, temp, mid+1, end);

		invCount += inversionMerge(arr, temp, start, mid+1, end);
	}

	return invCount;
}

int countInversion2(int arr[], int N){
	int temp[N];
	inversionUsingMergeSort(arr, temp, 0, N-1);
}

int main()
 {
	//code
  	//int arr[] = {12,21,5,351,98,122,39,87,53,90,17,68};
  	int arr[] = {8, 22, 7, 9, 31, 5, 13};
  	int size = sizeof(arr)/sizeof(arr[0]);

  	cout<<countInversion2(arr, size);

	return 0;
}