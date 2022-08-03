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
    int a[]={10,15,20,40,8,11,55};
    int low = 0;
    int mid = 3;
    int high = 6;
    int left[mid+1-low];
    int right[high-mid];

    for (int i = 0; i < mid+1-low; i++)
    {
        left[i]=a[i];
    }

    for (int i = mid+1; i <= high; i++)
    {
        right[i-mid-1]=a[i];
    }
    /*
    for (int i = 0; i < mid+1; i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < high-mid; i++)
    {
        cout<<right[i]<<" ";
    }
     */
    // merge(a,b,m,n);
    mergeSort(left, right, mid+1, high-mid);
    return 0;
}