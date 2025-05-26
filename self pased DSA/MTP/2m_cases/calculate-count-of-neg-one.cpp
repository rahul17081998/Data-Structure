


#include<bits/stdc++.h>
using namespace std;

//write your function here
void print_2D_Array(vector<vector<int> > bicolor)
{
    for (int i = 0; i < bicolor.size(); i++)
    {
        cout<<"B"<<i<<" = ";
        for(int j=0; j < bicolor[0].size(); j++)
        {
            cout<<bicolor[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void countNeg(vector<vector<int> > bicolor){
    for (int i = 0; i < bicolor.size(); i++)
    {
        cout<<"B"<<i<<" = ";
        int Neg=0;
        for(int j=0; j < bicolor[0].size(); j++)
        {
            cout<<bicolor[i][j]<<" ";
            if(bicolor[i][j]==-1) Neg++;
        }
        cout<<"   NegCount = "<<Neg<<"   PosCount = "<<(bicolor[0].size()-Neg)<<endl;
    }
}


int main(){
    int n,m;
    cout<<"Enter n and m: "<<endl;
    cin>>n>>m;
    vector<vector<int> > grid;
    while(m--){
        vector<int> level;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            level.push_back(x);
        }
        grid.push_back(level);
    }
    cout<<"Bicolorings "<<endl;
    // print_2D_Array(grid);
    countNeg(grid);


    return 0;
}