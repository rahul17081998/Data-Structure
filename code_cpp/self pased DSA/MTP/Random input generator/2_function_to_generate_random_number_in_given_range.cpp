#include<bits/stdc++.h>
using namespace std;

// we can generate any random number between given range
int random(int low, int high)
{
	return low + rand() % (high - low + 1);
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		cout << random(1, 10) <<endl;
	}

	return 0;
}