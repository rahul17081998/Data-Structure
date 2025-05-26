#include<iostream>
using namespace std;

void lageelement(int arr[],int n)
{
int max = arr[0];
int x=0;
// Traverse method to find large element in a array
for (int i = 1; i <n; i++)
{
    if(max<arr[i]){

        max = arr[i];
        x=i;
    }
}
cout<<"large element is: "<<max<<endl;
cout<<"index of large element is: "<<x<<endl;
// index of large element
/*for ( int j = 0; j < 5; j++)
{
    if(max==arr[j])
        x=j;
}
cout<<"index of large element: "<<x<<endl;
*/
}

int main(){
    int a[]={4,3,45,300,2,56,754,1};
    int n = sizeof(a)/sizeof(a[0]);
    lageelement(a,n);
    
    //Program to sort array in increasing order using C++ inbuilt function
    /*sort(a,a+n);  //C++ inbuilt function
     cout<<"large element: "<<a[n-1]<<endl;
     cout<<"second largest element: "<<a[n-2]<<endl;
    cout<<"\nArray after sorting in increasing order:\n";
    for(int i=0;i<n;i++)
         {
             cout<<a[i]<<" ";
        }
        */
    return 0;
}