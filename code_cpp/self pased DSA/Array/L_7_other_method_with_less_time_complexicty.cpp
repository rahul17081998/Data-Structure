#include <iostream>
using namespace std;

void function1(int input[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] > input[res])
        {
            res = i;
        }
    }
    cout<<"index: "<<res<<endl;
    cout<<"largest element: "<<input[res]<<endl;
}

int main()
{
    int arr1[] = {21, 3, 54, 1, 100};
    int n;
    n = sizeof(arr1) / sizeof(arr1[0]);
    // cout << function1(arr1, n);
    function1(arr1, n);
    return 0;
}