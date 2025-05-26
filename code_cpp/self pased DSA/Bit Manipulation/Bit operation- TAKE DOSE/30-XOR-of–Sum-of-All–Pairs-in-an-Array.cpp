/*
Given an array A of size n. the task is to generate a new sequence B with size N^2 having elements sum of every pair of array A and find the xor value of the sum of all the pairs formed. 

Note: Here (A[i], A[i]), (A[i], A[j]), (A[j], A[i]) all are considered as different pairs.

Examples: 

Input: arr = {1, 5, 6}
Output: 4
B[3*3] = { 1+1, 1+5, 1+6, 5+1, 5+5, 5+6, 6+1, 6+5, 6+6}
B[9] = { 2, 6, 7, 6, 10, 11, 7, 11, 12}
So, 2 ^ 6 ^ 7 ^ 6 ^ 10 ^ 11 ^ 7 ^ 6 ^ 11 ^ 12 = 4

Input :1, 2
Output :6
*/

// C++ program to find XOR of
// sum of every possible pairs
// in an array
#include <bits/stdc++.h>
using namespace std;

// Function to find XOR of sum
// of all pairs
int findXor(int arr[], int n)
{
    int sumXor=0;
    for(int i=0; i<n; i++){
        sumXor ^=(2*arr[i]);
    }
    return sumXor;
	
}

// Drivers code
int main()
{
	int arr[3] = { 1, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << findXor(arr, n);

	return 0;
}
