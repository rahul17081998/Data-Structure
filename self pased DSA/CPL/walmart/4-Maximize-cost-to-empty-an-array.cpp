/*
Maximize cost to empty an array by removing contiguous subarrays of equal elements
Given an array arr[] consisting of N integers and an integer M, the task is to find the maximum cost that can be obtained by performing the following operation any number of times. 
n one operation, choose K contiguous elements with same value(where K ≥ 1) and remove them and cost of this operation is K * M. 

*/

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Initialize dp array
int dp[101][101][101];

// Function that removes elements
// from array to maximize the cost
int helper(int arr[], int left, int right,
		int count, int m)
{
	// Base case
	if (left > right)
		return 0;

	// Check if an answer is stored
	if (dp[left][right][count] != -1) {
		return dp[left][right][count];
	}

	// Deleting count + 1 i.e. including
	// the first element and starting a
	// new sequence
	int ans = (count + 1) * m
			+ helper(arr, left + 1,
					right, 0, m);

	for (int i = left + 1;
		i <= right; ++i) {

		if (arr[i] == arr[left]) {

			// Removing [left + 1, i - 1]
			// elements to continue with
			// previous sequence
			ans = max(
				ans,
				helper(arr, left + 1,
					i - 1, 0, m)
					+ helper(arr, i, right,
							count + 1, m));
		}
	}

	// Store the result
	dp[left][right][count] = ans;

	// Return answer
	return ans;
}

// Function to remove the elements
int maxPoints(int arr[], int n, int m)
{
	int len = n;
	memset(dp, -1, sizeof(dp));

	// Function Call
	return helper(arr, 0, len - 1, 0, m);
}

// Driver Code
int main()
{
	// Given array
	int arr[] = { 1, 3, 2, 2, 2, 3, 4, 3, 1 };

	int M = 3;

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << maxPoints(arr, N, M);
	return 0;
}
