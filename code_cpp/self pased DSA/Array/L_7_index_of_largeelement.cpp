#include <iostream>
using namespace std;

int indlarele(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {12, 40, 45, 50, 4};
    int n;
    n = sizeof(arr) / sizeof(arr[0]);
    cout << indlarele(arr, n);
    return 0;
}