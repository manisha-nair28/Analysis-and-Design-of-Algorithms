#include<iostream>
 
using namespace std;
 
// A function to find the maximum of two integers.
int max(int a, int b)
{
	return (a > b)? a:b;
}
 
// A function to find the maximum sum sub-array which includes mid of the sub-array.
int MaxCrossingSum(int arr[], int low, int mid, int high)
{
	// Include elements having index value less than or equal to the mid.
	int sum = 0;
	int leftpartsum = -1;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + arr[i];
		if (sum > leftpartsum)
			leftpartsum = sum;
	}
 
	// Include elements having index value greater mid.
	sum = 0;
	int rightpartsum = -1;
	for (int i = mid+1; i <= high; i++)
	{
		sum = sum + arr[i];
		if (sum > rightpartsum)
			rightpartsum = sum;
    }
 
	// Return sum of elements on left and right of mid.
	return leftpartsum + rightpartsum;
}
 
// Returns sum of maxium subarray sum.
int MaxSubArraySum(int arr[], int low, int high)
{
	int mid;
	// If low index is equal to the high index h then the subarray contains only one element.
	if (low == high)
		return arr[low];
 
	// Otherwise find the mid index and proceed.
	mid = (low + high)/2;
 
	// Maximum sum sub-array can be either in the left part, right part or covering elements from both parts.
	return max(max(MaxSubArraySum(arr, low, mid), MaxSubArraySum(arr, mid+1, high)), MaxCrossingSum(arr, low, mid, high));
}
 
int main()
{
	int n, i;
	cout<<"Enter the number of data element in the array: ";
	cin>>n;
 
    int a[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>a[i];
	}
 
	// Print the maximum sub-array sum.
	cout<<"\nMaximum sub-array sum is: "<<MaxSubArraySum(a, 0, n-1);
 
	return 0;
}
