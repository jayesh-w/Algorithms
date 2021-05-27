/* 
The Maximum SubArray Problem. 

Problem Statement : Given an Array of Integers Find the Maximum Subarray.
Technique Used : Divide and Conquer. 
Divide : 
1. Left Subarray
2. Right Subarray
3. Subarray crossing Mid ( compulsory )

Array = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]
Ans = [18,20,-7,12]

Reference : Introduction to Algorithms, Page 72.


*/
#include<iostream>
using namespace std;

struct subarray
{
	int lowerbound, upperbound, sum; // A simple Method to return multiple values at once
									// Although you can use vector,tuple,pairs in c++11
};

subarray MaxCrossSub(int arr[],int low,int mid,int high) {
	int left_sum,right_sum,sum,i,j;
	subarray ans;
	left_sum = arr[mid];
	right_sum = arr[mid+1];
	int max_left = mid;
	int max_right = mid+1;
	for(i=mid; i>=low;i--) {
		sum = sum + arr[i];
		if(sum>left_sum) {
			left_sum = sum;
			max_left = i;
		}

	}
	sum = 0;
	for(j=mid+1;j<=high;j++) {
		sum = sum + arr[j];
		if(sum>right_sum) {
			right_sum = sum;
			max_right = j;
		}

	}
	ans.lowerbound = max_left;
	ans.upperbound = max_right;
	ans.sum = left_sum+right_sum;

	return ans;

}


subarray MaxSubArray(int arr[],int low,int high) {
	subarray base,leftsub,rightsub,crosssub;
	int mid;
	if(low==high) { 				// Base case :Array has only 1 element
		base.lowerbound = low;
		base.upperbound = high;
		base.sum = arr[low]; 
		return base; 
	}
	else {
		mid = (low+high)/2;
		leftsub = MaxSubArray(arr,low,mid);
		rightsub = MaxSubArray(arr,mid+1,high);
		crosssub = MaxCrossSub(arr,low,mid,high);
		if(leftsub.sum >= rightsub.sum && leftsub.sum >= crosssub.sum ) {
			return leftsub;
		}
		else if(rightsub.sum >= leftsub.sum && rightsub.sum >= crosssub.sum) {
			return rightsub;
		}
		else {
			return crosssub;
		}

	}


}

int main() {

	int arr[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int size = sizeof(arr)/sizeof(arr[0]); // Doesnt work inside functions
	subarray ans; 
	ans = MaxSubArray(arr,0,size-1); // Initial sizes:: low : 0 | High : size-1
	int sum = 0;
	for(int i=ans.lowerbound; i<=ans.upperbound ; i++) {
		sum = sum + arr[i];
	}

	cout << "Answer is : " << endl;
	cout << "Max Subbarray is : [" ;
	for(int i=ans.lowerbound ; i<=ans.upperbound ; i++) {
		cout << arr[i] << ",";
	}
	cout << "]"<<endl;
	cout << "Lower Bound : "<<ans.lowerbound << endl; 
	cout << "Upper Bound : " << ans.upperbound << endl;
	cout << "SUM : " << sum << endl;


	return 0;
}
