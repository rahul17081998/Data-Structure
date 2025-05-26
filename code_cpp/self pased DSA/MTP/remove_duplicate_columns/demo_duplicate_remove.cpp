#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//write your function here

// print all bicoloring
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






// remove duplicate columns
void removeDuplicateColumns(vector<vector<int> > &bicolor){
    int row = bicolor.size();
    int col = bicolor[0].size();
    cout<<row<<" <---- row    col ----> "<<col<<endl;
    vector<vector<int> > updatedBicolorings;
    for(int i=0; i<row; i++){
        vector<int> c;
        updatedBicolorings.push_back(c);
    }


    unordered_map<string, int> mpp; // store the unique columns index
    // take each columns ans go throught all the columns elements
    for(int j=0; j<col; j++){
        string str="";
        for(int i=0; i<row; i++){
            if(bicolor[i][j]==1) str = str + "a";
            else str = str + "b";
        }
        // check if this columns pattern was present in past
        if(mpp.find(str)==mpp.end()){
            for(int i=0; i<row; i++){
                updatedBicolorings[i].push_back(bicolor[i][j]); 
            }
            
            mpp[str]=j; // it will over write if this pattern has present in past
        }   
    }

    cout<<"old size: "<<bicolor[0].size()<<"    New size: "<<updatedBicolorings[0].size()<<endl;
    cout<<"   map size: "<<mpp.size()<<endl;
    bicolor = updatedBicolorings;
   
    
}







// random bicoloring input generator
void runProgram(int n, int m, int k)
{
   
    srand(time(0));  // Initialize random number generator.
    for(int x=0; x<k; x++)
    {
        vector<vector<int> > grid;
        for(int j=0; j<m; j++){
            vector<int> v;
            for(int i=0; i<n; i++)
            {
                if((rand() % 2) == 0){
                    v.push_back(-1);
                   
                }
                else{
                    v.push_back(1);
                  
                }
            }
           
            grid.push_back(v);
        }
        print_2D_Array(grid);
        removeDuplicateColumns(grid);
        cout<<endl;
        print_2D_Array(grid);
       
    }
   
}


int main(){
    
    runProgram(9,3,1); // n, m, k
    return 0;
}