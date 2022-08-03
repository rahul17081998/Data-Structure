#include<iostream>
using namespace std;
// Effective solution 
// time complexity: O(m+n)
// Aux space: O(m+n);
void union_two(int a[], int b[], int m, int n)
{
    int i=0,j=0,k=0;
    int temp[m+n]; // extra array
    while (i<m and j<n)
    {
        if(a[i]<=b[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else if(a[i]>=b[j])
        {
            temp[k]=b[j];
            k++;
            j++;
        }
        
    }
    while (i<m)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while (j<n)
    {
        temp[k]=b[j];
        k++;
        j++;
    }
    /*
    cout<<"Sorted array"<<endl;
    for (int i = 0; i < m+n; i++)
    {
        cout<<temp[i]<<" ";
    }
    */
    cout<<endl;
    cout<<"Union elements"<<endl;
    for (int i = 0; i < m+n; i++)
    {  
        if (i==0)
        {
            cout<<temp[i]<<" ";
        }
    
        if (temp[i] !=temp[i-1])
        {
            cout<<temp[i]<<" ";
        }
        
    }
    
    
}


// effective approch : mergesort method
// time complexity: O(m+n)
// Aux space: O(1);
void mergeSort_union(int a[],int b[], int m, int n)
{
    int i=0,j=0;
    while (i<m and j<n)
    {
        if(i>0 && a[i]==a[i-1]){i++; continue;}
        if(i>0 && b[i]==b[i-1]){j++; continue;}
        if(a[i]<b[j])
        {
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]>b[j])
        {
            cout<<b[j]<<" ";
            j++;
        }
        else
        {
            cout<<a[i]<<" ";
            i++;
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
    int a[] = {1,1,3,10,30};
    int m = sizeof(a)/sizeof(a[0]);
    int b[] = {1,2,3,5,7,10,30,};
    int n = sizeof(b)/sizeof(b[0]);
    union_two(a,b,m,n);
    cout<<endl;
    mergeSort_union(a,b,m,n);
    return 0;
}