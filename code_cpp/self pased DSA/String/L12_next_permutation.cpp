// C++ program to illustrate
// next_permutation example

// this header file contains next_permutation function
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string arr="AEF";
    sort(arr.begin(), arr.end());
 
	cout << "The 3! possible permutations with 3 elements:\n";
	do {
        cout<<arr<<" ";
	} while (next_permutation(arr.begin(), arr.end()));
	return 0;
}
