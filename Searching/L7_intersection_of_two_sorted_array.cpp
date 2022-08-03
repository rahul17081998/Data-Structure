#include<iostream>
using namespace std;
// Naive approch: O(m*n)
void intersection(int a[], int b[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if(a[i] != a[i+1])
        {
            for (int j = 0; j < n; j++)
            {
                if(a[i]==b[j])
                {
                    cout<<a[i]<<" ";
                    break;
                }
            }
            
        }

    }
    
    
}
// Effective approch
void inter_section(int a[], int b[], int m, int n)
{
    int i=0,j=0;
    while(i<m and j<n)
    {
        if (i>0 and a[i]==a[i-1])
        {
            i++;
            continue;
        }
       
        if (a[i]>b[j])
        {
            j++;
        }
        else if (a[i]<b[j])
        {
            i++;
        }
        else if (a[i]==b[j])
        {
            cout<<a[i]<<" ";
            i++;
            j++;
        }
         
    }
}

int main(){
    int a[] = {1,1,3,3,3,10,20,30,30};
    int m = sizeof(a)/sizeof(a[0]);
    int b[] = {1,1,1,1,3,5,7,10,23,23,30,30};
    int n = sizeof(b)/sizeof(b[0]);
    // intersection(a, b, m, n);
    inter_section(a, b, m, n);
    return 0;
}