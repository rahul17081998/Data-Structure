#include<iostream>
using namespace std;

int partation(int arr[], int n, int index)
{   int temp[n];
    int count=0;
    int y=arr[index];
    // int pivot_count=0;
    int before_pivote_count=0;
    // counting if piport is repated
    /*
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==y)
        {
            pivot_count++;
        }
    }*/
    //before actual how many pivotes are present in array
    for (int i = 0; i < index; i++)
    {
        if(arr[i]==y)
        {
            before_pivote_count++;
        }
    }
    

    // arranging the array a/c to pivote

    //coping smaller element in tempery array which is smaller than pivote
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<y)
        {
            temp[count]=arr[i];
            count++;
        }
    }
    //coping element in tempery array which is equal to the pivote
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==y)
        {
            temp[count]=arr[i];
            count++;
        }
    }
    //coping element in tempery array which is greater than pivote
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>y)
        {
            temp[count]=arr[i];
            count++;
        }
    }
    // first pivote index after arranging array a/c to pivote
    int first_pivote;
    for (int i = 0; i < n; i++)
    {
        if(temp[i]==y)
        {
            first_pivote=i;
            break;
        }
    }
    
    return first_pivote+before_pivote_count;
    
}
int main(){
    int arr[] = {3,8,6,7,12,10};
    int index =3;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<partation(arr,n,index);
    return 0;
}