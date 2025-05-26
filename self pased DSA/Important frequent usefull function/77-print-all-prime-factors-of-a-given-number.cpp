#include <bits/stdc++.h>
using namespace std;
/*
dividing of the given number by an integer starting from 2 representing current factor of that number. 
This approach works on the fact that all composite numbers have factors in pairs other than 1 or number itself

Time Complexity: This Approach is best for all composite numbers and achieves O(log n) but is O(n) otherwise.
*/
void primeFactors(int n)
{
	int c=2;
	while(n>1)
	{
		if(n%c==0){
		cout<<c<<" ";
		n/=c;
		}
		else c++;
	}
}

/* Driver code */
int main()
{
	int n = 118;
	primeFactors(n);
	return 0;
}
