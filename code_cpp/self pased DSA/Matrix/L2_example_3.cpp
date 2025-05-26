/*
#include<iostream>
using namespace std;
const int R=3;
const int C=2;
void print(int mat[R][C])
{
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cout<<mat[i][j]<<" ";
}
int main(){
    int mat[R][C]= {{10,20},
                    {30,40},
                    {50,60}};
                                
    print(mat);
    return 0;
}
*/


/*
// Example 4
#include<iostream>
using namespace std;

int main(){
    int m=3,n=2;
    int **arr;
    arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=i;
            cout<<arr[i][j]<<" ";
        }
        
    }
        
    return 0;
}
*/

// Example 5
#include<iostream>
using namespace std;

int main(){
    int m=3,n=2;
    int *arr[m];
    for (int i = 0; i < m; i++)
    {
        arr[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=i;
            cout<<arr[i][j]<<" ";
        }
        // cout<<endl;
        
    }
    
    return 0;
}