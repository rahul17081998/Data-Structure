#include<iostream>
using namespace std;

void deleteduplicate(int arr[], int n)
{
    int indx= 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==arr[i+1])
        {
                indx=indx+1;   // count no of duplicates
            for(int j=i; j< n; j++)
            {
                arr[j]=arr[j+1];
            }
        }
    }
    
    for (int i = 0; i <= n-indx+1; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}

int main(){
    int array_2[]={2,53,6,3,113,5,42,1,5462,3,6,6};
    int n = sizeof(array_2)/sizeof(array_2[0]);
    sort(array_2,array_2+n);
    cout<<"sorted array before deleting duplicates: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<array_2[i]<<" ";
    }
    cout<<"sorted array after deleting duplicates: "<<endl;
    deleteduplicate(array_2, n);
    
    return 0;
}