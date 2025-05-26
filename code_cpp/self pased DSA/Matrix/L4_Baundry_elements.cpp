#include<iostream>
using namespace std;
// change these values A/c to dimension of matrix m*n
const int m=4;  // rows
const int n=1;  // columns
void boundry_ele(int mat[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            {
                if(i==0)
                {
                    cout<<mat[i][j]<<" ";
                }
                if(j==n-1 and i>0)
                {
                    cout<<mat[i][j]<<" ";
                }

            }
    }

    for (int i = 0; i < m; i++)
    {
        if(i==m-1 and i!=0)
        {
            for (int j = n-2; j >=0 ; j--)
            {
                cout<<mat[i][j]<<" ";
            }
            
        }
        
    }


    if(n!=1)
    {
        for (int i = m-2; i >0; i--)
    {
        
        cout<<mat[i][0]<<" ";
    }
    }
    
    
    
}

int main(){
    /*
    //      m=4,n=4
    int mat[m][n]= {{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
    */

   /*
    //      m=4,n=2         
   int mat[m][n]={{1,2},
                  {3,4},
                  {5,6},
                  {6,7},
                    };  
    */

    /*
    //    corner case-1 
    // m=1,n=4
    int mat[m][n]={{1,2,3,4}};     
    */

    //    corner case-2
    // m=4,n=1
    int mat[m][n]={{1},
                   {2},
                   {3},
                   {4}};

                   
    boundry_ele(mat);
    return 0;
}