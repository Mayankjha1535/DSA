#include<iostream>
using namespace std;

void printHeap(int arr[], int n){
	cout<<"Heap is : ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

void heapify(int arr[], int n, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left<n && arr[left] > arr[largest] ){
		largest = left;
	}
	if(right< n && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest!=i){
		swap(arr[i],arr[largest]); // swap the elements 
		heapify(arr,n,largest);  // heapify the new tree
	}
}

void HeapSort(int arr[], int n){  
	int last_non_leaf = (n/2)-1;     //start from the last of non-leaf nodes to reduce the time complexity as leaf nodes are already heapified
	for(int i=last_non_leaf;i>=0;i--){
		heapify(arr,n,i); //build heap phase
	}
	for(int i = n-1;i>=0;i--){
		swap(arr[i],arr[0]);   //extraction phase
		heapify(arr,i,0);  //reduce the heap size by 1 
	}
}

int main(){
	int arr[] = {20,11,15,10,8,12,21};
	int n = sizeof(arr)/sizeof(arr[0]);
	printHeap(arr,n);
	HeapSort(arr,n);
	printHeap(arr,n);
	return 0;
}
