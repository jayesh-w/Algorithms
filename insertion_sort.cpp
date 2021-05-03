#include <iostream>
#include <array>
using namespace std;




void insertion_sort(int arr[]) {
	// int size = sizeof(arr)/sizeof(arr[0]);  // Only works for same types
	int size = 5;
	cout << "size of int is " << *(&arr + 1) - arr << endl;
	for(int j=1; j<=size; j++) {
		int key = arr[j];
		int i = j-1;
		while(i>=0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i = i-1;
			arr[i+1] = key;
		}
	}
	

}

int main() {
	int arr[5] = {5,4,3,1,2};
	insertion_sort(arr);
	for(int i=0;i<5;i++) {
		cout << arr[i] << endl;
	}
	return 0;

}