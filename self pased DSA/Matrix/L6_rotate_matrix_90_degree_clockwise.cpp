#include<iostream>
using namespace std;
const int m=4;

void rotatemat(int mat[m][m])
{
    for (int j = m-1; j >=0; j--)
    {
        for (int i = 0; i < m; i++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main(){
    
    int mat[m][m]= {{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
    rotatemat(mat);
    return 0;
}