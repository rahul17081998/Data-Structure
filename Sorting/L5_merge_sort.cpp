#include<iostream>
using namespace std;
/*
// Naive solution
// T(n)=(m+n)*log(m+n)
// Aux space = (m+n)
void merge(int a[],int b[],int m, int n)
{ 
    int c[m+n];
    // copy element of array a[] into c[]
    for (int i = 0; i < m; i++)
    {
        c[i]=a[i];
    }
    // copy element of array b[] into c[]
    for (int i = 0; i < n; i++)
    {
        c[m+i]=b[i];
    }
    // sorting array c[]
    sort(c,c+m+n);
    // printing array c[ ]
    for (int i = 0; i < m+n; i++)
    {
        cout<<c[i]<<" ";
    }
    
}
*/

// Effective approch
// T(n) = (m+n)
// Aux space = O(1)
void mergeSort(int a[],int b[], int m, int n)
{
    int i=0,j=0;
    while (i<m and j<n)
    {
        if(a[i]<=b[j])
        {
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]>=b[j])
        {
            cout<<b[j]<<" ";
            j++;
        }
        
    }
    while (i<m)
    {
        cout<<a[i]<<" ";
        i++;
    }
    while (j<n)
    {
        cout<<b[j]<<" ";
        j++;
    }

    
    
}

int main(){
    int a[] = {10,20,35};
    int m = sizeof(a)/sizeof(a[0]);
    int b[] = {5,50,50};
    int n = sizeof(b)/sizeof(b[0]);
    // merge(a,b,m,n);
    mergeSort(a, b, m, n);
    return 0;
}