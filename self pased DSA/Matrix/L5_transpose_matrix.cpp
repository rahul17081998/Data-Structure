#include<iostream>
using namespace std;
// change these values A/c to dimension of matrix m*n
const int m=2;

void transpose(int mat[m][m])
{   int temp[m][m];
    for(int i=0; i<m; i++)
    { 
        for(int j=0; j<m; j++)
        {
            temp[j][i]=mat[i][j];
        }
        
    }
    // copy elements from temp[][] array to mat[][]
    for(int i=0; i<m; i++)
    { 
        for(int j=0; j<m; j++)
        {
            // cout<<temp[i][j]<<" ";
            mat[i][j]=temp[i][j];
        }
        
    }
    // print those elements 
    for(int i=0; i<m; i++)
    { 
        for(int j=0; j<m; j++)
        {
            cout<<temp[i][j]<<" ";
           
        }
        cout<<endl;
    }

}
int main(){
    /*
    int mat[R][C]= {{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
    */
    int mat[m][m]={{1,1},
                   {2,2}};
    transpose(mat);
    return 0;
}