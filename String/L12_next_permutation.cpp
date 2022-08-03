// C++ program to illustrate
// next_permutation example

// this header file contains next_permutation function
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	// int arr[] = { 1, 2, 3 };
	// sort(arr, arr + 3);
    string arr="ACB";
    sort(arr.begin(), arr.end());

	cout << "The 3! possible permutations with 3 elements:\n";
	do {
		// cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
        cout<<arr<<" ";
	} while (next_permutation(arr.begin(), arr.begin() + 3));

	// cout << "After loop: " << arr[0] << ' '
	// 	<< arr[1] << ' ' << arr[2] << '\n';

	return 0;
}
